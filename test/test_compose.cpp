#include <colors.hpp>
#include <iostream>

int main()
{
    std::cout << Colors::compose(Colors::RED, Style::BLINK)
    << "Hello World!" << Colors::reset() << std::endl;
    if(Colors::compose(Colors::RED, Style::BLINK) == "\033[31;5m")
        return 0;
    else
        return 1;
}