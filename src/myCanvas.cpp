#include "myCanvas.hpp"

#include <fstream>
#include <iostream>
#include <algorithm>

namespace myCanvas
{
        Canvas::Canvas(int w, int h)
        {
            width = w;
            height = h;
            data = std::vector<std::vector<myColours::Colour>>(width, std::vector<myColours::Colour>(height, myColours::Colour()));
        }

        void writePixel(Canvas& canvas, int x, int y, myColours::Colour c)
        {

            canvas.data[x][y] = c;
        }

        void canvasToPPM(const Canvas& canvas)
        {
            std::string header = "P3\n"
                                + std::to_string(canvas.width)
                                + " "
                                + std::to_string(canvas.height)
                                + "\n255\n";
            std::sstream out("canvas.ppm", std::ios::trunc);
            out << header;
            for(auto& w : canvas.data)
            {
                for(auto& h : w)
                {
                    auto r = std::clamp(h.red, 0.0f, 255.0f);
                    auto g = std::clamp(h.green, 0.0f, 255.0f);
                    auto b = std::clamp(h.blue, 0.0f, 255.0f);

                    out << r << " " << g << " " << b << " ";

                }

            }

            out.close();


        }
}
