#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <boost/asio/io_service.hpp>
#include <string>

class Network
{
  public:
    Network();
    ~Network();
    int send_data(const std::string& ip_receiver, const std::string& data);
    int retrieve_send_datas();

  private:
    boost::asio::io_service io_service;

    int convert_string_to_send_data(const std::string& data);
    std::string convert_received_data_to_string(const int data);
};

#endif
