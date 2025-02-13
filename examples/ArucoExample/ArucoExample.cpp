#include "SimClient.hpp"  // Подключаем заголовочный файл из вашей библиотеки
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/aruco_detector.hpp>
#include <iostream>

#include <chrono>
#include <thread>

using namespace cv;
using namespace std;

cv::Mat recognitionAruco(cv::Mat image_mat)
{
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);

    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();

    cv::aruco::ArucoDetector detector(dictionary, detectorParams);

    cv::Mat output_image_mat = image_mat.clone();

    detector.detectMarkers(output_image_mat, markerCorners, markerIds, rejectedCandidates);

    if(!markerIds.empty())
    {
        cv::aruco::drawDetectedMarkers(output_image_mat, markerCorners, markerIds);
        std::cout << "NOT empty" << std::endl;
    }
    else
    {
        std::cout << "Empty bro" << std::endl;
    }

    return output_image_mat;
}

cv::Mat ConvertTo3Channel(const cv::Mat& src) 
{
    cv::Mat dst;
    cv::cvtColor(src, dst, cv::COLOR_RGBA2RGB);
    return dst;
}

int main() {
    // Создаем объект Client с использованием конструктора
    bool isConnect = false;
    Client client("127.0.0.1", 8080);
    try
    {
        isConnect = client.IsConnected();

        std::cout << "The result is: " << isConnect << std::endl;
    }
    catch(const char* error_message)
    {
        std::cout << error_message  << std::endl;
    }

    while(isConnect)
    {
        //isConnect = client.IsConnected();
        try
        {
            std::vector<uint8_t> image = client.GetCameraCapture(0,false);
            
            int width = 640; // Ширина изображения
            int height = 480;

            cv::Mat image_mat(height, width, CV_8UC4, const_cast<uint8_t*>(image.data()));
            cv::Mat image_rgb = ConvertTo3Channel(image_mat);

            cv::Mat image_with_aruco  = recognitionAruco(image_rgb);

            cv::imshow("Image", image_with_aruco);

            
        }
        catch(const char* error_message)
        {
            std::cout << error_message  << std::endl;
        }
        
        if (cv::waitKey(30) == 27) {
            break;
        }

        this_thread::sleep_for(chrono::milliseconds(10));
        
    }

    return 0;
}