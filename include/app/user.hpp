#ifndef USER_HPP_
#define USER_HPP_

#include <string>
class User
{
  public:
    User(std::string user_name, std::string ip_address);
    ~User();

    // Getters
    std::string get_user_name();
    std::string get_ip_address();

    // Setters
    void change_user_name(std::string new_user_name);

  private:
    std::string ip_address;
    std::string user_name;
};

#endif
