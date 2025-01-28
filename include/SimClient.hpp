#include <string>
#include <memory>

class SimClientImpl;

class Client
{
public:
    std::string address;
    int port;
    
    
    Client(std::string address_, int port_);
    ~Client();

    bool IsConnected();
private:
    std::unique_ptr<SimClientImpl> impl;

};