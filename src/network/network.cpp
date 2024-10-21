#include "network/network.hpp"
#include "my_macros.hpp"
#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/io_service.hpp>

Network::Network()
  : io_service()
  , socket(io_service)
  , buffer()
{
}

Network::~Network() {}

int
Network::send_data(const std::string& ip_receiver, const std::string& data)
{
    int data_to_send = this->convert_string_to_send_data(data);

    return SUCCESS;
}

int
Network::retrieve_send_datas()
{
    return SUCCESS;
}

int
Network::convert_string_to_send_data(const std::string& data)
{
    return 0;
}

std::string
Network::convert_received_data_to_string(const int received_data)
{
    return "haha";
}
