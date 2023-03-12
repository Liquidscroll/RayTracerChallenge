#include "util.hpp"
#include "myData.hpp"
#include <cmath>

namespace util
{

    float getVectorMagnitude(const myData::myVector& v)
    {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
    }

    myData::myVector normalizeVector(const myData::myVector& v)
    {
        return myData::myVector(v.x / getVectorMagnitude(v),
                                v.y / getVectorMagnitude(v),
                                v.z / getVectorMagnitude(v),
                                v.w / getVectorMagnitude(v));
    }

    float getDotProduct(const myData::myVector& v, const myData::myVector& v2)
    {
        return (v.x * v2.x + v.y * v2.y + v.z * v2.z + v.w * v2.w);
    }

    myData::myVector getCrossProduct(const myData::myVector& v1, const myData::myVector& v2)
    {
        return myData::myVector(v1.y * v2.z - v1.z * v2.y,
                                v1.z * v2.x - v1.x * v2.z,
                                v1.x * v2.y - v1.y * v2.x);
    }


}