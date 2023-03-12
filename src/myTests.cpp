#include <cmath>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "myCanvas.hpp"
#include "myData.hpp"
#include "myColours.hpp"
#include "util.hpp"


const float ERROR_MARGIN = 0.0001;

TEST_CASE("Tuple of point", "[point]")
{
    auto p = myData::myPoint(4.3f, -4.2f, 3.1f);
    REQUIRE_THAT(p.x, Catch::Matchers::WithinRel(4.3f));
    REQUIRE_THAT(p.y, Catch::Matchers::WithinRel(-4.2f));
    REQUIRE_THAT(p.z, Catch::Matchers::WithinRel(3.1f));
    REQUIRE(p.w == 1);
}

TEST_CASE("Tuple of Vector", "[vector]")
{
    auto v = myData::myVector(4.3f, -4.2f, 3.1f);
    REQUIRE_THAT(v.x, Catch::Matchers::WithinRel(4.3f));
    REQUIRE_THAT(v.y, Catch::Matchers::WithinRel(-4.2f));
    REQUIRE_THAT(v.z, Catch::Matchers::WithinRel(3.1f));
    REQUIRE(v.w == 0);
}

TEST_CASE("Addition", "[vector] + [point]")
{
    auto p = myData::myPoint(3, -2, 5);
    auto v = myData::myVector(-2, 3, 1);
    auto answer = myData::myPoint(1, 1, 6);

    REQUIRE(p + v == answer);
    REQUIRE(v + p == answer);
}

TEST_CASE("Subtracting 2 points", "[point] - [point]")
{
    auto p = myData::myPoint(3, 2, 1);
    auto p2 = myData::myPoint(5, 6, 7);
    auto answer = myData::myVector(-2, -4, -6);

    REQUIRE(p - p2 == answer);
}

TEST_CASE("Subtract a vector from a point", "[vector] - [point]")
{
    auto p = myData::myPoint(3, 2, 1);
    auto v = myData::myVector(5, 6, 7);
    auto a = myData::myPoint(-2, -4, -6);

    REQUIRE(p - v == a);
}

TEST_CASE("Subtract 2 vectors", "[vector] - [vector]")
{
    auto v1 = myData::myVector(3, 2, 1);
    auto v2 = myData::myVector(5, 6, 7);
    auto a = myData::myVector(-2, -4, -6);
    REQUIRE(v1 - v2 == a);
}

TEST_CASE("Subtract a vector from the 0 vector", "[zero] - [vector]")
{
    auto z = myData::myVector(0, 0, 0);
    auto v = myData::myVector(1, -2, 3);
    auto a = myData::myVector(-1, 2, -3);

    REQUIRE(z - v == a);
}

TEST_CASE("Tuple negation", "[tuple]")
{
    auto p = myData::myPoint(1, -2, 3, -4);
    auto v = myData::myVector(1, -2, 3, -4);
    auto a = myData::myPoint(-1, 2, -3, 4);
    auto a2 = myData::myVector(-1, 2, -3, 4);

    REQUIRE(-p == a);
    REQUIRE(-v == a2);
}

TEST_CASE("Multiply by scalar", "[tuple]")
{
    auto p = myData::myPoint(1, -2, 3, -4);
    auto v = myData::myVector(1, -2, 3, -4);
    auto a = myData::myPoint(3.5, -7, 10.5, -14);
    auto a2 = myData::myVector(3.5, -7, 10.5, -14);

    float scalar = 3.5;

    REQUIRE(p * scalar == a);
    REQUIRE(v * scalar == a2);

}

TEST_CASE("Multiply by fractional scalar", "[tuple]")
{
    auto p = myData::myPoint(1, -2, 3, -4);
    auto v = myData::myVector(1, -2, 3, -4);
    auto a = myData::myPoint(0.5, -1, 1.5, -2);
    auto a2 = myData::myVector(0.5, -1, 1.5, -2);

    float scalar = 0.5;

    REQUIRE(p * scalar == a);
    REQUIRE(v * scalar == a2);
}

TEST_CASE("Divide tuple by scalar", "[tuple]")
{
    auto p = myData::myPoint(1, -2, 3, -4);
    auto v = myData::myVector(1, -2, 3, -4);
    auto a = myData::myPoint(0.5, -1, 1.5, -2);
    auto a2 = myData::myVector(0.5, -1, 1.5, -2);

    float scalar = 2;

    REQUIRE(p / scalar == a);
    REQUIRE(v / scalar == a2);
}

TEST_CASE("Get Magnitude of Vector","[vector]")
{

    auto v = util::getVectorMagnitude(myData::myVector(1, 0, 0));
    auto v1 = util::getVectorMagnitude(myData::myVector(0, 1, 0));
    auto v2 = util::getVectorMagnitude(myData::myVector(0, 0, 1));
    auto v3 = util::getVectorMagnitude(myData::myVector(1, 2, 3));
    auto v4 =  util::getVectorMagnitude(myData::myVector(-1, -2, -3));

    REQUIRE(v == 1);
    REQUIRE(v1 == 1);
    REQUIRE(v2 == 1);
    REQUIRE_THAT(v3, Catch::Matchers::WithinAbs(sqrt(14), ERROR_MARGIN));
    REQUIRE_THAT(v4, Catch::Matchers::WithinAbs(sqrt(14), ERROR_MARGIN));
}

TEST_CASE("Normalizing Vectors", "[vector]")
{
    auto v = util::normalizeVector(myData::myVector(4, 0, 0));
    auto v1 = util::normalizeVector(myData::myVector(1, 2, 3));
    auto v2 = util::getVectorMagnitude(util::normalizeVector(myData::myVector(1, 2, 3)));

    REQUIRE(v == myData::myVector(1, 0, 0));
    REQUIRE_THAT(v1.x, Catch::Matchers::WithinAbs(1/sqrt(14), ERROR_MARGIN));
    REQUIRE_THAT(v1.y, Catch::Matchers::WithinAbs(2/sqrt(14), ERROR_MARGIN));
    REQUIRE_THAT(v1.z, Catch::Matchers::WithinAbs(3/sqrt(14), ERROR_MARGIN));

    REQUIRE_THAT(v2, Catch::Matchers::WithinAbs(1.0, ERROR_MARGIN));

}

TEST_CASE("Dot Product", "[vector]")
{
    auto a = myData::myVector(1, 2, 3);
    auto b = myData::myVector(2, 3, 4);

    REQUIRE(util::getDotProduct(a, b) == 20);
}

TEST_CASE("Cross_Product", "[vector]")
{
    auto a = myData::myVector(1, 2, 3);
    auto b = myData::myVector(2, 3, 4);

    REQUIRE(util::getCrossProduct(a, b) == myData::myVector(-1, 2, -1));
    REQUIRE(util::getCrossProduct(b, a) == myData::myVector(1, -2, 1));
}

TEST_CASE("Basic Colours", "[colour]")
{
    auto c = myColours::Colour(-0.5, 0.4, 1.7);

    REQUIRE(c.red == -0.5f);
    REQUIRE(c.green == 0.4f);
    REQUIRE(c.blue == 1.7f);
}

TEST_CASE("Add/Subtract/Multiply Colors")
{
    auto c1 = myColours::Colour(0.9, 0.6, 0.75);
    auto c2 = myColours::Colour(0.7, 0.1, 0.25);

    auto c3 = c1 + c2;
    auto c4 = c1 - c2;

    auto c5 = (myColours::Colour(0.2, 0.3, 0.4) * 2);

    auto c6 = myColours::Colour(1, 0.2, 0.4);
    auto c7 = myColours::Colour(0.9, 1, 0.1);

    auto c8 = c6 * c7;

    REQUIRE_THAT(c3.red,  Catch::Matchers::WithinAbs(1.6f, ERROR_MARGIN));
    REQUIRE_THAT(c3.green, Catch::Matchers::WithinAbs(0.7f, ERROR_MARGIN));
    REQUIRE_THAT(c3.blue, Catch::Matchers::WithinAbs(1.0f, ERROR_MARGIN));
    REQUIRE_THAT(c4.red,  Catch::Matchers::WithinAbs(0.2f, ERROR_MARGIN));
    REQUIRE_THAT(c4.green, Catch::Matchers::WithinAbs(0.5f, ERROR_MARGIN));
    REQUIRE_THAT(c4.blue, Catch::Matchers::WithinAbs(0.5f, ERROR_MARGIN));
    REQUIRE_THAT(c5.red,  Catch::Matchers::WithinAbs(0.4f, ERROR_MARGIN));
    REQUIRE_THAT(c5.green, Catch::Matchers::WithinAbs(0.6f, ERROR_MARGIN));
    REQUIRE_THAT(c5.blue, Catch::Matchers::WithinAbs(0.8f, ERROR_MARGIN));

    REQUIRE_THAT(c8.red,  Catch::Matchers::WithinAbs(0.9f, ERROR_MARGIN));
    REQUIRE_THAT(c8.green, Catch::Matchers::WithinAbs(0.2f, ERROR_MARGIN));
    REQUIRE_THAT(c8.blue, Catch::Matchers::WithinAbs(0.04f, ERROR_MARGIN));
}

TEST_CASE("Create Canvas", "[canvas]")
{
    auto c = myCanvas::Canvas(10, 20);

    REQUIRE(c.width == 10);
    REQUIRE(c.height == 20);

    for(auto& w : c.data)
    {
        for(auto& h : w)
        {
            REQUIRE(h == myColours::Colour());
        }
    }

}

TEST_CASE("Write Pixel", "[canvas]")
{
    auto c = myCanvas::Canvas(10, 20);
    auto red = myColours::Colour(1, 0, 0);

    myCanvas::writePixel(c, 2, 3, red);

    REQUIRE(c.data[2][3] == red);
}