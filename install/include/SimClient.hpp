#include <string>
#include <memory>
#include <vector>

class SimClientImpl;

class Client
{
public:
    std::string address;
    int port;
    
    
    Client(std::string address_, int port_);
    ~Client();

    bool IsConnected();
    std::vector<uint8_t> GetCameraCapture(int TargetCameraId, bool IsThermal);

    std::vector<float> GetLaserScan(float AngleMin, float AngleMax, float RangeMin, float RangeMax, int NumRanges, bool IsClear, float RangeError);

    std::vector<float> GetRadarPoint(int TargetRadarId, float baseAngle, float minDistance, float maxDistance, bool IsClear, float RangeError, float AngleError);

    float GetRangeData(int TargetRangefinderId, float minDistance, float maxDistance, bool IsClear, float RangeError);

    void SetLedIntensity(int TargetLedId, float Intensity);

    void SetLedState(int TargetLedId, bool NewState);

    
private:
    std::unique_ptr<SimClientImpl> impl;

    std::vector<uint8_t> resizeImage(const std::vector<uint8_t>& image, int old_width, int old_height, int new_width, int new_height);
    std::vector<uint8_t> applyGammaCorrection(const std::vector<uint8_t>& image, double gamma);
};