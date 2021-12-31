#pragma once

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class PulseLaser : public Laser
    {
    private:
        int thickness;           // 線寬
        float delay;             // 延遲
        float powerTime;         // 脈衝充能的時間
        float duration;          // 釋放的持續時間
        int dashLineLength;      // 脈衝長度
        sf::Vector2f deltaShake; // 震動幅度
        sf::RectangleShape line; // 線物件

        bool pulsing = false; //是否為釋放狀態
        float counter = 0.f;  //計時器
        float liveTime;       //脈衝總生存時間
        float deltaThickness; //寬度變化量

        std::vector<sf::RectangleShape> dashLine; //虛線存放器

        // UI Draw Function
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    public:
        // Constructor
        PulseLaser(sf::Vector2f position, float angle, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop, int thickness = 25, float delay = 0.25f, float powerTime = 0.25f, float duration = 0.5f, int dashLineLength = 75, int dashLineThickness = 10);

        // Accessors
        bool isCollided(const Pattern &player) const override; //是否碰撞

        // Update Events
        void update(float deltaTime) override; //更新
    };
};