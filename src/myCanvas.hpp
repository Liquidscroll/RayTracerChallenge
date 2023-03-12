#ifndef MYCANVAS_HPP
#define MYCANVAS_HPP

#include <vector>

#include "myColours.hpp"

namespace myCanvas
{
    class Canvas
    {
        private:

        public:
            int width, height;
            std::vector<std::vector<myColours::Colour>> data;

            Canvas(int w = 10, int h = 10);




    };

    void writePixel(Canvas& canvas, int x, int y, myColours::Colour c);

    void canvasToPPM(const Canvas& canvas);

}



#endif