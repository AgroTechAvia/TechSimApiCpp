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
            float result = client.GetRangeData(0, 150, 1000, true, 0.15);

            std::cout << "range: " << result << std::endl;
            
        }
        catch(const char* error_message)
        {
            std::cout << error_message  << std::endl;
        }

        sleep(0.25);
        
    }

    return 0;
}