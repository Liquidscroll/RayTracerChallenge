#ifndef MYCOLOURS_HPP
#define MYCOLOURS_HPP

#include <iostream>

namespace myColours
{
    class Colour
    {
        private:
        public:
            float red, green, blue;

            Colour(float r = 0, float g = 0, float b = 0);

            Colour operator+(const Colour& c)
            {
                return Colour(this->red + c.red, this->green + c.green, this->blue + c.blue);
            }

            Colour operator-(const Colour& c)
            {
                return Colour(this->red - c.red, this->green - c.green, this->blue - c.blue);
            }

            Colour operator*(const float& scalar)
            {
                return Colour(this->red * scalar, this->green * scalar, this->blue * scalar);
            }

            Colour operator*(const Colour& c)
            {
                return Colour(this->red * c.red, this->green * c.green, this->blue * c.blue);
            }

            bool operator==(const Colour& c)
            {
                return this->red == c.red && this->green == c.green && this->blue == c.blue;
            }

            friend std::ostream& operator<<(std::ostream& os, const Colour& c);

    };


}




#endif