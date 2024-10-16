#include "app/user.hpp"

#include <string>

User::User(const std::string& user_name)
{
    this->user_name = user_name.empty() ? "Voldemort" : user_name;
    this->ip_address = "";
}

User::User(const std::string& user_name, const std::string& ip_address)
{
    this->user_name = user_name.empty() ? "Voldemort" : user_name;
    this->ip_address = ip_address;
}

User::~User() {}

std::string
User::get_user_name()
{
    return this->user_name;
}

std::string
User::get_ip_address()
{
    return this->ip_address;
}

void
User::change_user_name(const std::string& new_user_name)
{
    this->user_name = new_user_name.empty() ? this->user_name : new_user_name;
}
