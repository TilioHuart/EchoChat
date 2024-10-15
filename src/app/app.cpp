#include "app/app.hpp"
#include "my_macros.hpp"
#include <memory>

App::App()
  : self_user(std::make_unique<User>("Voldemort"))
{
}

App::~App() {}

int
App::launch_app()
{
    return SUCCESS;
}
