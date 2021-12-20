#include "Game/Util.h"

#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <cmath>
// 檔案是否存在
bool exist(const std::string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}
// 點到線的距離
float distanceOfPointToLine(float &x, float &y, float &a, float &b, float &c)
{
    // distance = |ax + by + c| / (a^2 + b^2)^0.5
    return abs(a * x + b * y + c) / sqrt(a * a + b * b);
}
//
float distanceOfPointToLineByAngle(float &ax, float &ay, float &bx, float &by, float &angle)
{

    // find the line (ax + by + c = 0) that pass (bx, by) with angle

    // slope = tan(angle)
    float slope = tan(angle);

    // y - by = slope * (x - bx)
    // simplify
    // slope * x - y + bx - slope * bx = 0
    // a = slope
    // b = -1
    // c = by - slope * bx
    static float b = -1;
    float c = by - slope * bx;
    return distanceOfPointToLine(ax, ay, slope, b, c);
}
// 點到線段的距離
float distanceOfPointToSeg(float &px, float &py, float &ax, float &ay, float &bx, float &by)
{
    // dot proeduct |ABxAP|
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
//
float crossProduct(float &ax, float &ay, float &bx, float &by)
{
    return ax * by - bx * ay;
}

std::string toString(int &a)
{
    char buffer[16];
    itoa(a, buffer, 10);
    return (std::string)buffer;
}
// 字串轉 RGB
sf::Color stringToColor(std::string string)
{
    // Split String with ,
    // Red, Green, Blue
    std::stringstream ss(string);
    std::string temp = "";
    int colorBytes[3];

    for (int i = 0; i < 3; ++i)
    {
        std::getline(ss, temp, ',');
        colorBytes[i] = atoi(temp.c_str());
    }

    // return Color(Red, Green, Blue);
    return sf::Color(colorBytes[0], colorBytes[1], colorBytes[2]);
}