#include "SimClient.hpp"  
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

void displayImage(const std::vector<uint8_t>& image_data, int width, int height) {
   
    cv::Mat image(height, width, CV_8UC4, const_cast<uint8_t*>(image_data.data()));

    
    cv::imshow("Image", image);
    cv::waitKey(0); 
}

int main() {
    
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

    if(isConnect)
    {
        try
        {
            std::vector<uint8_t> image = client.GetCameraCapture(0,false,false);

            int width = 640; 
            int height = 480;
            
            cv::Mat image_mat(height, width, CV_8UC4, const_cast<uint8_t*>(image.data()));
            
            cv::imshow("Image", image_mat);
            cv::waitKey(0);
        }
        catch(const char* error_message)
        {
            std::cout << error_message  << std::endl;
        }
        
    }

    return 0;
}