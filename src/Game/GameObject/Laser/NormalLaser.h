#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class NormalLaser : public Laser
    {
    private:
        // Debug
        sf::RectangleShape box;
        sf::RectangleShape box2;

        // Laser Parameter
        int &length;              // 長度
        float angle;              // 角度
        float &speed;             // 雷射飛行速度
        sf::Vector2f velocity;    // 一秒移動的距離
        sf::Vector2f endPosition; // 尾端位置
        sf::RectangleShape line;  //繪製線

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    public:
        // Constructor
        NormalLaser(sf::Vector2f position, int &length, int &thickness, float &angle, float &speed, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop);
        ~NormalLaser();

        // Accessors
        void setColor(Color &color) override;                       //設定顏色
        void setPosition(sf::Vector2f &point) override;             //設定位置
        bool isCollided(sf::Vector2f &point, int &radius) override; //檢測是否碰撞到

        void update(float &deltaTime) override; //更新
    };
};