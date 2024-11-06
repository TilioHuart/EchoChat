#include "app/app.hpp"
#include "my_macros.hpp"
#include "iostream"
#include "gpg/keys/createKeyPair.h"

int
main(void)
{
    App app;

    app.launch_app();


    std::cout << "\n.\n.\nGPG IMPLEMENTATION >>>>>\n.\n.\n";

    generate_and_print_gpg_keys("John Doe", "johndoe@example.com");
    return SUCCESS;
}
