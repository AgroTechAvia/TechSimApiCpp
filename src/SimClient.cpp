#include "SimClient.hpp"
#include <iostream>
#include "rpc/client.h"

Client::Client(std::string address_p, int port_p)
{
    
    address = address_p;
    port = port_p;
    
    std::cout << "Client has been created" << std::endl;
}

void Client::PrintData()
{
    std::cout << "Client addres: " << address << " , port: " << port << std::endl;

    rpc::client c(address, port);
    bool result = c.call("ping").as<bool>();

    std::cout << result << std::endl;
}