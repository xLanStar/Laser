#include "Game/Util.h"

#include "cmath"

// 用向量法求點到線段的距離
float distanceOfPointToSeg(float &px, float &py, float &ax, float &ay, float &bx, float &by)
{
    // |AB*AP|
    float cross = (bx - ax) * (px - ax) + (by - ay) * (py - ay);

    if (cross <= 0)
    {
        // result = |AP|
        return sqrt((px - ax) * (px - ax) + (py - ay) * (py - ay));
    }

    // |AB|^2
    float lengthSquare = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
    if (cross >= lengthSquare)
    {
        // result = |BP|
        return sqrt((px - bx) * (px - bx) + (py - by) * (py - by));
    }

    // find Point c
    float r = cross / lengthSquare;
    float cx = ax + (bx - ax) * r;
    float cy = ay + (by - ay) * r;

    // result = |CP|
    return sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy));
}

// 整數轉字串
std::string toString(int &a)
{
    char buffer[16];
    itoa(a, buffer, 10);
    return (std::string) buffer;
}