#include "my_macros.hpp"
#include "iostream"

int echochat(void)
{
    std::cout << MySTD::my_strlen("Hello");
    return SUCCESS;
}
