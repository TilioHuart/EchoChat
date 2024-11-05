#include "app/display.hpp"
#include "my_macros.hpp"
#include "string"
#include "iostream"
#include "stdlib.h"

Disp::Disp() {
    this->recipient = "Recipient";
}

Disp::~Disp() {}

int
Disp::display() {
    display_prompt(this->recipient);
    return SUCCESS;
}

int
Disp::display_prompt(std::string& recipient) {
    std::cout << BOLDBLUE << "Message with " << RESET;
    std::cout << BOLDRED << recipient << RESET << std::endl;
    return SUCCESS;
}
