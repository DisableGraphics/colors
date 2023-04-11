#include <style.hpp>

Style::Style()
{
    style.push_back(NORMAL);
}

Style::Style(Style_type style)
{
    this->style.push_back(style);
}

std::vector<Style::Style_type> Style::get_styles() const
{
    return style;
}

void Style::add_style(Style::Style_type style)
{
    this->style.push_back(style);
}

Style::operator int() const
{
    int ret{0};
    for(auto & elem : style)
    {
        ret += elem;
    }
    return ret;
}