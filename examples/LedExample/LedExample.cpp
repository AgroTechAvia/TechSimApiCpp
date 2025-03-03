#include "SimClient.hpp"  
#include <iostream>


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
    Client client("172.18.96.1", 8080);
    
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

            sleep(0.5);

            client.SetLedIntensity(0, 0.8);
            client.SetLedIntensity(1, 0.8);

            sleep(0.1);

            client.SetLedIntensity(0, 0.6);
            client.SetLedIntensity(1, 0.6);

            sleep(0.1);

            client.SetLedIntensity(0, 0.4);
            client.SetLedIntensity(1, 0.4);

            sleep(0.1);

            client.SetLedIntensity(0, 0.2);
            client.SetLedIntensity(1, 0.2);

            sleep(0.1);

            client.SetLedState(0,false);
            client.SetLedState(1,false);

            sleep(0.5);

            
        }
        catch(const char* error_message)
        {
            std::cout << error_message  << std::endl;
        }

        
        
    }

    return 0;
}