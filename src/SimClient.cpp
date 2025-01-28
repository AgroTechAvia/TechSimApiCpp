#include "SimClient.hpp"
#include <iostream>
#include "rpc/client.h"



class SimClientImpl {
public:
    SimClientImpl() : client(nullptr) {}
    
    void Connect(const std::string& address, int port) {
        // Инициализация rpc::client
        client = std::make_unique<rpc::client>(address, port);
    }

    std::unique_ptr<rpc::client> client; // Указатель на rpc::client
};




Client::Client(std::string address_, int port_)
    : address(address_), port(port_), impl(std::make_unique<SimClientImpl>()) 
{
        impl ->Connect(address_, port_);
}

Client::~Client() = default;

bool Client::IsConnected()
{
    bool result = true;

    try
    {
        result = impl-> client -> call("ping").as<bool>();
    }
    catch(const std::exception& e)
    {
        result = false;
    }

    return result;
}
