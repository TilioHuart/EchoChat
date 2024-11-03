#include "network/network.hpp"
#include "my_macros.hpp"
#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/system/detail/error_code.hpp>
#include <iostream>

Network::Network()
  : io_context()
  , port_to_listen(3000)
  , acceptor(io_context)
  , endpoint(boost::asio::ip::tcp::v4(), port_to_listen)
  , socket(io_context)
  , buffer()
{
    this->start_tcp_serveur();
}

Network::~Network() {}

int
Network::start_tcp_serveur()
{
    const auto handler = [](const boost::system::error_code& error) {
        if (error) {
            std::cerr << "An error occurend: " << error.what() << std::endl;
        }
    };

    this->acceptor.open(this->endpoint.protocol());
    this->acceptor.bind(this->endpoint);

    this->acceptor.async_accept(this->socket, handler);

    this->io_context.run();

    return SUCCESS;
}

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
