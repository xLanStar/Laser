#include "Game/Util.h"

#include <sys/stat.h>
#include <sstream>
#include <cmath>

// 角度轉弧度
float degToArc(float deg)
{
    return deg * PI / 180;
};

// 弧度轉角度
float arcToDeg(float arc)
{
    return arc * 180 / PI;
};
// 檔案是否存在
bool exist(const std::string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}
// 點到線的距離
float distanceOfPointToLine(const float &x, const float &y, const float &a, const float &b, const float &c)
{
    // distance = |ax + by + c| / (a^2 + b^2)^0.5
    return abs(a * x + b * y + c) / sqrt(a * a + b * b);
}
//
float distanceOfPointToLineByArc(const float &ax, const float &ay, const float &bx, const float &by, const float &arc)
{
    float slope = tan(arc); // 取得斜率
    static float b = -1;
    float c = by - slope * bx;
    return distanceOfPointToLine(ax, ay, slope, b, c);
}
// 點到線段的距離
float distanceOfPointToSeg(const float &px, const float &py, const float &ax, const float &ay, const float &bx, const float &by)
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

// 判斷點是否在範圍內
bool inRange(const sf::FloatRect &rect, const sf::Vector2f &position)
{
    return rect.left <= position.x && position.x <= rect.left + rect.width && rect.top <= position.y && position.y <= rect.top + rect.height;
}

std::string toString(int a)
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