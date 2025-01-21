#include <string>

class Client
{
public:
    std::string address;
    int port;
    
    Client(std::string address_p, int port_p);

    void PrintData();
};