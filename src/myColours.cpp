#include "myColours.hpp"
#include <iostream>


namespace myColours
{
    Colour::Colour(float r, float g, float b)
                    : red(r), green(g), blue(b)
    {}

    std::ostream& operator<<(std::ostream& os, const Colour& c)
    {
        os << "(R:" << c.red << ", G:" << c.green << ", B:" << c.blue << ")";
        return os;
    }
}