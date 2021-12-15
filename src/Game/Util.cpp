#include "Game/Util.h"

#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <cmath>

bool exist(const std::string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

float distanceOfPointToSeg(float &px, float &py, float &ax, float &ay, float &bx, float &by)
{
    // |AB|*|AP|
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

std::string toString(int &a)
{
    char buffer[16];
    itoa(a, buffer, 10);
    return (std::string)buffer;
}

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