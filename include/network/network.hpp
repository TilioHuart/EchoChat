#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <string>

class Network
{
  public:
    static int send_data(const std::string& ip_receiver,
                         const std::string& data);
    static int retrieve_send_datas();
    static int convert_string_to_send_data(const std::string& data);
    static int convert_send_data_to_string(const std::string& data);
};

#endif
