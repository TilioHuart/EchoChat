#ifndef APP_HPP
#define APP_HPP
#include "user.hpp"
#include <memory>

class App
{
  public:
    App();
    ~App();
    int launch_app();

  private:
    User self_user;

    int initialize_network();
    int kill_network();
};

#endif
