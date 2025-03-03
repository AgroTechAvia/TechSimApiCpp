#include "SimClient.hpp"
#include <iostream>
#include "rpc/client.h"
#include <random>
#include <algorithm>
#include <cstdint>


template <typename T>
T clamp(T value, T minValue, T maxValue) {
    return (value < minValue) ? minValue : (value > maxValue) ? maxValue : value;
}

void RGBtoHSV(uint8_t r, uint8_t g, uint8_t b, float& h, float& s, float& v) {
    float rf = r / 255.0f;
    float gf = g / 255.0f;
    float bf = b / 255.0f;

    float max = std::max({rf, gf, bf});
    float min = std::min({rf, gf, bf});
    v = max;

    float delta = max - min;

    if (max == 0) {
        s = 0;
        h = -1; // Угол не определен
        return;
    }
    
    s = (max == 0) ? 0 : (delta / max);

    if (delta == 0) {
        h = 0; // Угол не определен
    } else if (max == rf) {
        h = (gf - bf) / delta;
    } else if (max == gf) {
        h = 2 + (bf - rf) / delta;
    } else {
        h = 4 + (rf - gf) / delta;
    }

    h *= 60;
    if (h < 0) h += 360;
}

// Функция для преобразования HSV в RGB
void HSVtoRGB(float h, float s, float v, uint8_t& r, uint8_t& g, uint8_t& b) {
    float c = v * s;
    float x = c * (1 - std::abs(fmod(h / 60.0f, 2) - 1));
    float m = v - c;

    float rf, gf, bf;

    if (h < 60) {
        rf = c; gf = x; bf = 0;
    } else if (h < 120) {
        rf = x; gf = c; bf = 0;
    } else if (h < 180) {
        rf = 0; gf = c; bf = x;
    } else if (h < 240) {
        rf = 0; gf = x; bf = c;
    } else if (h < 300) {
        rf = x; gf = 0; bf = c;
    } else {
        rf = c; gf = 0; bf = x;
    }

    r = static_cast<uint8_t>((rf + m) * 255);
    g = static_cast<uint8_t>((gf + m) * 255);
    b = static_cast<uint8_t>((bf + m) * 255);
}

// Функция для изменения насыщенности
void changeSaturation(std::vector<uint8_t>& image, float saturationFactor) {
    for (size_t i = 0; i < image.size(); i += 3) {
        // Получаем RGB значения
        uint8_t r = image[i];
        uint8_t g = image[i + 1];
        uint8_t b = image[i + 2];

        // Преобразуем в HSV
        float h, s, v;
        RGBtoHSV(r, g, b, h, s, v);

        // Изменяем насыщенность
        s *= saturationFactor;
        s = clamp(s, 0.0f, 1.0f); // Ограничиваем значения насыщенности

        // Преобразуем обратно в RGB
        HSVtoRGB(h, s, v, image[i], image[i + 1], image[i + 2]);
    }
}


class SimClientImpl {
public:
    SimClientImpl() : client(nullptr) {}
    
    void Connect(const std::string& address, int port) {
        // Инициализация rpc::client
        client = std::make_unique<rpc::client>(address, port);
    }

    std::unique_ptr<rpc::client> client; // Указатель на rpc::client
};

std::vector<uint8_t> Client::resizeImage(const std::vector<uint8_t>& image, int old_width, int old_height, int new_width, int new_height) 
{
    std::vector<uint8_t> resized_image(new_width * new_height * 4);
    
    for (int i = 0; i < new_height; ++i) {
        for (int j = 0; j < new_width; ++j) {
            int src_i = i * old_height / new_height;
            int src_j = j * old_width / new_width;
            
            for (int k = 0; k < 4; ++k) {
                resized_image[(i * new_width + j) * 4 + k] = image[(src_i * old_width + src_j) * 4 + k];
            }
        }
    }
    
    return resized_image;
}

std::vector<uint8_t> Client::applyGammaCorrection(const std::vector<uint8_t>& image, double gamma) {
    double inv_gamma = 1.0 / gamma;
    std::vector<uint8_t> table(256);

    // Заполнение таблицы преобразования
    for (int i = 0; i < 256; ++i) {
        table[i] = static_cast<uint8_t>(std::pow(i / 255.0, inv_gamma) * 255);
    }

    // Применение преобразования к изображению
    std::vector<uint8_t> corrected_image(image.size());
    for (size_t i = 0; i < image.size(); ++i) {
        corrected_image[i] = table[image[i]];
    }

    return corrected_image;
}



Client::Client(std::string address_, int port_)
    : address(address_), port(port_), impl(std::make_unique<SimClientImpl>()) 
{
        impl ->Connect(address_, port_);
}

Client::~Client() = default;

bool Client::IsConnected()
{
    bool result = true;

    try
    {
        result = impl-> client -> call("ping").as<bool>();
    }
    catch(const std::exception& e)
    {
        result = false;
    }

    return result;
}

std::vector<uint8_t> Client::GetCameraCapture(int TargetCameraId, bool IsThermal)
{
    std::vector<uint8_t> rawImage = impl-> client -> call("getCameraCapture",TargetCameraId,IsThermal).as<std::vector<uint8_t>>();

    int old_width = 480;
    int old_height = 360;
    std::pair<int, int> new_size(640, 480); 

    std::vector<uint8_t> resizedImage = resizeImage(rawImage,old_width, old_height, new_size.first, new_size.second);
    std::vector<uint8_t> correctedImage = applyGammaCorrection(resizedImage, 1.0);
    changeSaturation(correctedImage, 1.0);

    return correctedImage; 
}

std::vector<float> Client::GetLaserScan(float AngleMin, float AngleMax, float RangeMin, float RangeMax, int NumRanges, bool IsClear, float RangeError)
{
    std::vector<float> laserScanData = impl-> client -> call("getLaserScan", AngleMin,  AngleMax,  RangeMin,  RangeMax,  NumRanges).as<std::vector<float>>();

    if(!IsClear && (laserScanData.size() == NumRanges))
    {
        std::default_random_engine generator;
        std::normal_distribution<double> distribution(0.0, RangeError);

        for (size_t i = 0; i < NumRanges; ++i) 
        {
            double noise = distribution(generator);
            laserScanData[i] += noise;
        }   
    }

    return laserScanData;
}

std::vector<float> Client::GetRadarPoint(int TargetRadarId, float baseAngle, float minDistance, float maxDistance, bool IsClear, float RangeError, float AngleError)
{
    std::vector<float> radarPoint = impl -> client -> call("getRadarData",  TargetRadarId,  baseAngle,  minDistance,  maxDistance).as<std::vector<float>>();

    if (!IsClear) {
        std::default_random_engine generator;
        
        std::normal_distribution<float> range_distribution(0.0f, AngleError);
        float range_noise = range_distribution(generator);
        radarPoint[0] += range_noise;

        std::normal_distribution<float> angle_distribution(0.0f, AngleError);
        for (int i = 1; i < 3; ++i) {
            float angle_noise = angle_distribution(generator);
            radarPoint[i] += angle_noise;
        }
    }

    return radarPoint;
}

float Client::GetRangeData(int TargetRangefinderId, float minDistance, float maxDistance, bool IsClear, float RangeError)
{
    float rangePoint = impl-> client -> call("getRangefinderData",  TargetRangefinderId,  minDistance,  maxDistance).as<float>();

    if (!IsClear) {
        std::default_random_engine generator;
        std::normal_distribution<float> distribution(0.0f, RangeError);
        
        float noise = distribution(generator);
        rangePoint += noise;
    }

    return rangePoint;
}

void Client::SetLedIntensity(int TargetLedId, float Intensity)
{
    impl-> client -> call("setLedIntensity",  TargetLedId,  Intensity);
}

void Client::SetLedState(int TargetLedId, bool NewState)
{
    impl-> client -> call("setLedState",  TargetLedId, NewState);
}