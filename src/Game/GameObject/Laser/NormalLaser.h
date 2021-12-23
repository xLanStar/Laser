#pragma once

#include "SFML/Graphics.hpp"

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class NormalLaser : public Laser
    {
    private:
        // Debug
        // sf::RectangleShape box;
        // sf::RectangleShape box2;

        int &length;                // 長度
        float angle;                // 角度
        float &speed;               // 雷射飛行速度
        sf::Vector2f velocity;      // 單位時間移動的距離
        sf::Vector2f endPosition;   // 尾端位置
        sf::Vector2f startPosition; //前端位置
        sf::RectangleShape line;    // 線物件

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override; //渲染

    public:
        // Constructor
        NormalLaser(sf::Vector2f position, int &length, int &thickness, float &angle, float &speed, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop);

        void setPosition(sf::Vector2f position);
        // Accessors
        bool isCollided(sf::Vector2f &point, int &radius) const override; //檢測是否碰撞到

        // Update Events
        void update(float &deltaTime) override; //更新
    };
};