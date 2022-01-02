#include <string>

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Rect.hpp"

#define PI 3.14159265358979323846

float degToArc(float deg); // 角度轉弧度

float arcToDeg(float arc); // 弧度轉角度

bool exist(const std::string &name); // 檔案是否存在

float distanceOfPointToLine(const float &x, const float &y, const float &a, const float &b, const float &c); // 點(ax, ay)到直線(ax+by+c=0)的距離

float distanceOfPointToLineByArc(const float &ax, const float &ay, const float &bx, const float &by, const float &arc); // 點(ax, ay)到經過點(bx,by)、角度angle的直線的距離

float distanceOfPointToSeg(const float &px, const float &py, const float &ax, const float &ay, const float &bx, const float &by); // 點到線段的距離

bool inRange(const sf::FloatRect &rect, const sf::Vector2f &position); // 判斷點是否在範圍內

std::string toString(int a); // 整數轉字串

sf::Color stringToColor(std::string string); // 字串 "R, G, B" 轉顏色