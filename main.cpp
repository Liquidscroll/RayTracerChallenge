#include <iostream>
#include <cmath>

#include <catch2/catch_session.hpp>

#include "src/myCanvas.hpp"
#include "src/myData.hpp"
#include "src/myColours.hpp"
#include "src/util.hpp"

struct projectile
{
    myData::myPoint pos;
    myData::myVector vel;

    projectile(const myData::myPoint& pos, const myData::myVector& vel)
    {
        this->pos = pos;
        this->vel = vel;
    }
};

struct environment
{
    myData::myVector grav, wind;

    environment(const myData::myVector& grav, const myData::myVector& wind)
    {
        this->grav = grav;
        this->wind = wind;
    }
};

projectile tick(projectile& proj, environment& env)
{
    proj.pos = proj.pos + proj.vel;
    auto tempVel = proj.vel + env.grav + env.wind;
    return projectile(proj.pos, tempVel);
}


int main(int argc, char* argv[])
{
    //Setup

    auto p = projectile(myData::myPoint(0, 1, 0), util::normalizeVector(myData::myVector(1, 1, 0)));
    auto e = environment(myData::myVector(0, -0.1, 0), myData::myVector(-0.01, 0, 0));
    auto c = myCanvas::Canvas(100, 100);

    while(p.pos.y <= 0)
    {
        p = tick(p, e);
        myCanvas::writePixel(c, p.pos.x, p.pos.y, myColours::Colour(1, 0, 0));
    }

    myCanvas::canvasToPPM(c);

    int result = Catch::Session().run(argc, argv);

    //CleanUp
    std::cout << "Hello World!" << std::endl;
    return result;
}