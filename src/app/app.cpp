#include "app/app.hpp"
#include "my_macros.hpp"
#include <memory>

App::App()
  : self_user("User1")
{
}

App::~App() {}

int
App::launch_app()
{
    return SUCCESS;
}
