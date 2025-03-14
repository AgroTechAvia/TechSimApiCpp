#include "SimClient.hpp"  
#include <iostream>
#include <math.h>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(static_cast<DWORD>(1000 * (x)))
#else
#include <unistd.h>
#define sleep(x) usleep(static_cast<useconds_t>(1000000 * (x)))
#endif

int main() 
{
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
        try
        {
            std::vector<float> result = client.GetRadarPoint(0, 45, 150, 2000, true, 0.15, 0.15);

            std::cout << "point: " << result[0]  << ", " << result[1] << ", " << result[2] << std::endl;
            
        }
        catch(const char* error_message)
        {
            std::cout << error_message  << std::endl;
        }

        sleep(0.25);
        
    }

    return 0;
}