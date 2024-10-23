#ifndef DISPLAY_HPP_
    #define DISPLAY_HPP_

    #include <string>

class Disp {
    public:
        Disp();
        ~Disp();
        int display();
    
    private:
        std::string recipient;
        int display_prompt(std::string& recipient);
};

#endif
