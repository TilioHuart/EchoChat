#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include <string>

class Network
{
  public:
    Network();
    ~Network();
    int send_data(const std::string& ip_receiver, const std::string& data);
    int retrieve_send_datas();

  private:
    const int port_to_listen;

    boost::asio::io_context io_context;
    boost::asio::ip::tcp::endpoint endpoint;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::ip::tcp::socket socket;

    boost::asio::streambuf buffer;

    int start_tcp_serveur();
    int convert_string_to_send_data(const std::string& data);
    std::string convert_received_data_to_string(const int data);
};

#endif
