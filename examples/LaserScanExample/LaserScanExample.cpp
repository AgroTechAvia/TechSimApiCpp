#include "SimClient.hpp"  
#include <iostream>
#define _USE_MATH_DEFINES
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
    
        // Выводим данные клиента
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
            std::vector<float> result = client.GetLaserScan(-M_PI, M_PI, 0.1, 10, 360, true, 0.01);

            std::cout << "Get Scan with " << result.size()  << " points" << std::endl;
            
        }
        catch(const char* error_message)
        {
            std::cout << error_message  << std::endl;
        }

        sleep(0.1);
        
    }

    return 0;
}