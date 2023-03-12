#include "myData.hpp"



namespace myData
{
    myVector::myVector(float x, float y, float z, int w)
                    : x(x), y(y), z(z), w(w)
    {}

    myPoint::myPoint(float x, float y, float z, int w)
                    : x(x), y(y), z(z), w(w)
    {}





    std::ostream& operator<<(std::ostream& os, const myPoint& p)
    {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ", " << p.w << ")";
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const myVector& v)
    {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
        return os;
    }

    myPoint operator+(const myVector& v, const myPoint& p)
    {
        return myPoint(v.x + p.x, v.y + p.y, v.z + p.z);
    }
}
