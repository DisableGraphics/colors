#include <colors.hpp>
#include <cstring>
#include <iostream>

std::string Colors::compose(const Color &fgcolor, const Style &style)
{
    const char * begin = "\033[";
    const char * end = "m";
    //Return the ANSI escape sequence for the given color and style

    //The color and style are bitmasks, so we can use bitwise operators to compose them
    std::string color = "";
    color += begin;
    color += get_color_code(fgcolor);
    if(style != Style::NORMAL)
    {
        color += ";";
        color += get_style_code(style);
    }
    color += end;
    
    return color;
}

std::string Colors::get_color_code(const Color &color)
{
    //Return the ANSI escape sequence for the given color
    switch(color)
    {
        case BLACK:
            return "30";
        case RED:
            return "31";
        case GREEN:
            return "32";
        case YELLOW:
            return "33";
        case BLUE:
            return "34";
        case MAGENTA:
            return "35";
        case CYAN:
            return "36";
        case WHITE:
            return "37";
        case DEFAULT:
            return "39";
        default:
            return "39";
    }
}

int Colors::get_bits(int p)
{
    //Get all the set bits
    int count = 0;
    while(p)
    {
        count += p & 1;
        p >>= 1;
    }
    return count;
}

std::string Colors::get_style_code(const Style &style)
{
    std::string code = "";
    for(auto & style : style.get_styles())
    {
        switch(style)
        {
            case Style::NORMAL:
                code += "0";
                break;
            case Style::BOLD:
                code += "1";
                break;
            case Style::UNDERLINE:
                code += "4";
                break;
            case Style::BLINK:
                code += "5";
                break;
            case Style::REVERSE:
                code += "7";
                break;
            case Style::CONCEALED:
                code += "8";
                break;
            default:
                code += "0";
                break;
        }
        if(get_bits(style) > 1)
            code += ";";
    }
    return code;
}

std::string Colors::get_compose_string(const Color &fgcolor, const Style &style)
{
    std::string color = "\\033[";
    color += get_color_code(fgcolor);
    if(style != Style::NORMAL)
    {
        color += ";";
        color += get_style_code(style);
    }
    color += "m";
    
    return color;
}

std::string Colors::reset()
{
    return "\033[30m";
}