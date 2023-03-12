#ifndef UTIL_HPP
#define UTIL_HPP

#include "myData.hpp"

namespace util
{

    float getVectorMagnitude(const myData::myVector& v);

    myData::myVector normalizeVector(const myData::myVector& v);

    float getDotProduct(const myData::myVector& v, const myData::myVector& v2);

    myData::myVector getCrossProduct(const myData::myVector& v, const myData::myVector& v2);

}


#endif