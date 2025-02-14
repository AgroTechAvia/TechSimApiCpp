#include "SimClient.hpp"  
#include <corecrt_math_defines.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#else
#include <unistd.h>
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
            client.SetLedState(0,true);
            client.SetLedState(1,true);

            Sleep(500);

            client.SetLedIntensity(0, 0.8);
            client.SetLedIntensity(1, 0.8);

            Sleep(100);

            client.SetLedIntensity(0, 0.6);
            client.SetLedIntensity(1, 0.6);

            Sleep(100);

            client.SetLedIntensity(0, 0.4);
            client.SetLedIntensity(1, 0.4);

            Sleep(100);

            client.SetLedIntensity(0, 0.2);
            client.SetLedIntensity(1, 0.2);

            Sleep(100);

            client.SetLedState(0,false);
            client.SetLedState(1,false);

            Sleep(500);

            
        }
        catch(const char* error_message)
        {
            std::cout << error_message  << std::endl;
        }

        
        
    }

    return 0;
}