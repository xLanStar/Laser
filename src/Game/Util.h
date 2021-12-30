#include <string>

#include "SFML/Graphics/Color.hpp"

#define inRange(px, py, ax, ay, bx, by) ax <= px &&px <= bx &&ay <= py &&py <= by

#define PI 3.14159265358979323846

// 檔案是否存在
bool exist(const std::string &name);

// 點(ax, ay)到直線(ax+by+c=0)的距離
float distanceOfPointToLine(const float &x, const float &y, const float &a, const float &b, const float &c);

// 點(ax, ay)到經過點(bx,by)、角度angle的直線的距離
float distanceOfPointToLineByAngle(const float &ax, const float &ay, const float &bx, const float &by, const float &angle);

// 點到線段的距離
float distanceOfPointToSeg(const float &px, const float &py, const float &ax, const float &ay, const float &bx, const float &by);

// 外積
float crossProduct(float &ax, float &ay, float &bx, float &by);

// 整數轉字串
std::string toString(int a);

// 字串 "R, G, B" 轉顏色
sf::Color stringToColor(std::string string);