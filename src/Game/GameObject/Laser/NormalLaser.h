#pragma once

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class NormalLaser : public Laser
    {
    public:
        NormalLaser(sf::Vector2f position, float angle, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, int speed = 900, int length = 280, int thickness = 7);

        bool isCollided(const Pattern &player) const override; //檢測是否碰撞到

        void update(float deltaTime) override; //更新

    private:
        int length;                 // 長度
        int speed;                  // 速度
        sf::Vector2f velocity;      // 速度在兩座標軸的分量
        sf::Vector2f startPosition; // 線段前端位置
        sf::Vector2f endPosition;   // 線段尾端位置

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override; //渲染
    };
};