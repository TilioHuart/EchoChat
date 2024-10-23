#ifndef APP_HPP
#define APP_HPP
#include "user.hpp"
#include <memory>
#include "display.hpp"

class App
{
  public:
    App();
    ~App();
    int launch_app();

  private:
    std::unique_ptr<User> self_user;
    Disp display;
};

#endif
