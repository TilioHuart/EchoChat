#include "network/network.hpp"
#include "my_macros.hpp"

int
Network::send_data(const std::string& ip_receiver, const std::string& data)
{
    int data_to_send = Network::convert_string_to_send_data(data);

    return SUCCESS;
}
