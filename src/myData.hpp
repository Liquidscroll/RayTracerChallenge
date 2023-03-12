
#ifndef MYDATA_HPP
#define MYDATA_HPP

#include <iostream>

namespace myData
{
    class myVector
    {
        private:
        public:
            float x, y, z;
            int w;

            myVector(float x = 0, float y = 0, float z = 0, int w = 0);



            myVector operator-()
            {
                return myVector(-this->x, -this->y, -this->z, -this->w);
            }

            myVector operator+(const myVector& v) const
            {
                return myVector(this->x + v.x, this->y + v.y, this->z + v.z);
            }

            myVector operator-(const myVector& v) const
            {
                return myVector(this->x - v.x, this->y - v.y, this->z - v.z);
            }

            myVector operator*(const float& scalar) const
            {
                return myVector(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
            }

            myVector operator/(const float& scalar) const
            {
                return myVector(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
            }

            myVector& operator+=(const myVector& v)
            {
                this->x += v.x;
                this->y += v.y;
                this->z += v.z;
                this->w += v.w;
                return *this;
            }

            myVector& operator=(const myVector& v)
            {
                this->x = v.x;
                this->y = v.y;
                this->z = v.z;
                this->w = v.w;
                return *this;
            }

            bool operator==(const myVector& other) const
            {
                return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
            }

            friend std::ostream& operator<<(std::ostream& os, const myVector& v);
    };

    class myPoint
    {
        private:
        public:
            float x, y, z;
            int w;

            myPoint(float x = 0, float y = 0, float z = 0, int w = 1);

            myPoint operator-()
            {
                return myPoint(-this->x, -this->y, -this->z, -this->w);
            }


            myVector operator+(const myVector& v) const
            {
                return myVector(this->x + v.x, this->y + v.y, this->z + v.z);
            }

            myPoint operator+(const myVector& v)
            {
                return myPoint(this->x + v.x, this->y + v.y, this->z + v.z);
            }

            myVector operator-(const myPoint& p)
            {
                return myVector(this->x - p.x, this->y - p.y, this->z - p.z);
            }

            myPoint operator-(const myVector& v)
            {
                return myPoint(this->x - v.x, this->y - v.y, this->z - v.z);
            }

            myPoint operator*(const float& scalar)
            {
                return myPoint(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
            }

            myPoint operator/(const float& scalar) const
            {
                return myPoint(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
            }

            inline bool operator==(const myPoint& other) const
            {
                return this->w == other.w && this->x == other.x && this->y == other.y && this->z == other.z;
            }

            friend std::ostream& operator<<(std::ostream& os, const myPoint& p);
    };



    myPoint operator+(const myVector& v, const myPoint& p);

}


#endif