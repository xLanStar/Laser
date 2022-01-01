#pragma once

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class PulseLaser : public Laser
    {
    private:
        float delay;             // 延遲
        float duration;          // 釋放的持續時間
        int dashLineLength;      // 脈衝長度
        sf::RectangleShape line; // 線物件

        bool pulsing = false; //是否為釋放狀態
        float counter = 0.f;  //計時器
        float liveTime;       //脈衝總生存時間

        std::vector<sf::RectangleShape> dashLine; //虛線存放器

        // UI Draw Function
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    public:
        // Constructor
        PulseLaser(sf::Vector2f position, float angle, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, int thickness = 7, float delay = 0.7f, float duration = 0.5f, int dashLineLength = 28);

        // Accessors
        bool isCollided(const Pattern &player) const override; //是否碰撞

        // Update Events
        void update(float deltaTime) override; //更新
    };
};