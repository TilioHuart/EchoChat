#ifndef APP_HPP
#define APP_HPP
#include <string>

class App {
   public:
    App();
    ~App();
    int launch_app();

   private:
    std::string user;
    bool isOn;
};

#endif
