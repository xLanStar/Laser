#pragma once

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class NormalLaser : public Laser
    {
    private:
        int length;                 // 長度
        float angle;                // 角度
        float speed;                // 雷射飛行速度
        sf::Vector2f velocity;      // 單位時間移動的距離
        sf::Vector2f endPosition;   // 尾端位置
        sf::Vector2f startPosition; //前端位置
        sf::RectangleShape line;    // 線物件

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override; //渲染

    public:
        NormalLaser(sf::Vector2f position, float angle, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, float speed = 1.2f, int length = 300, int thickness = 10);

        bool isCollided(const Pattern &player) const override; //檢測是否碰撞到

        void update(float deltaTime) override; //更新
    };
};