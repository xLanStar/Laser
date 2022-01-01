#pragma once

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class PulseLaser : public Laser
    {
    public:
        PulseLaser(sf::Vector2f position, float angle, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, int thickness = 7, float delay = 0.7f, float duration = 0.5f, int dashLineLength = 28);

        bool isCollided(const Pattern &player) const override; //是否碰撞

        void update(float deltaTime) override; //更新

    private:
        int dashLineLength;   // 虛線長度
        bool pulsing = false; // 是否為釋放狀態
        float counter = 0.f;  // 計時器
        float delay;          // 延遲
        float duration;       // 脈衝釋放的持續時間
        float liveTime;       // 脈衝總生存時間

        std::vector<sf::RectangleShape> dashLine; //虛線存放器

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override; //渲染
    };
};