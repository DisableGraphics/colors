#ifndef STYLE_HPP
#define STYLE_HPP

#include <vector>

class Style
{
    public:
        /**
        *   \brief Enum that contains the style
        */
        enum Style_type
        {
            NORMAL = 1,
            BOLD = 2,
            UNDERLINE = 4,
            BLINK = 8,
            REVERSE = 16,
            CONCEALED = 32
        };
        /**
        *   \brief Default Style constructor
        */
        Style();
        /**
        *   \brief Style constructor
        *   \param style Initial value
        */
        Style(Style_type style);
        /**
        *   \brief Operator overload for int
        *   This returns the sum of all the styles in the Style object.
        */
        operator int() const;
        /**
        *   \brief Get all the styles contained in the Style object
        */
        std::vector<Style_type> get_styles() const;
        /**
        *   \brief Add another style to the Style object
        */
        void add_style(Style_type style);
        
    private:
        std::vector<Style_type> style;
};

#endif