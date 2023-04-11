#ifndef COLORS_HPP
#define COLORS_HPP

#include <iostream>
#include <style.hpp>

class Colors
{
    public:
        enum Color
        {
            BLACK = 1,
            RED = 2,
            GREEN = 3,
            YELLOW = 4,
            BLUE = 5,
            MAGENTA = 6,
            CYAN = 7,
            WHITE = 8,
            DEFAULT = 9
        };
        /**
        * \brief Returns the ANSI escape code for the given color and style
        * \param fgcolor The foreground color
        * \param style The style
        * \return The ANSI escape code as std::string
        */
        static std::string compose(const Color &fgcolor, const Style &style);
        /**
        * \brief Returns the ANSI escape code as a readable string
        * \param fgcolor The foreground color
        * \param style The style
        * \return The ANSI escape code as std::string
        */
        static std::string get_compose_string(const Color &fgcolor, const Style &style);
        /**
        * \brief Resets the command line to the default style and color
        */
        static std::string reset();
    private:
        static std::string get_color_code(const Color &color);
        static std::string get_style_code(const Style &style);
        static int get_bits(int p);
};

#endif