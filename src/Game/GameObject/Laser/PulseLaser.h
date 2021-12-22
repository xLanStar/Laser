#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "Game/GameObject/Laser/Laser.h"

namespace GameObject
{
    class PulseLaser : public Laser
    {
    private:
        int &thickness; // 線寬
        float angle;    // 角度
        float &delay;   // 延遲
        float &powerTime;
        float &duration;     // duration time during laser pulsing
        int &dashLineLength; // 脈衝長度
        sf::Vector2f deltaShake;

        sf::RectangleShape line;

        sf::RectangleShape box;

        bool pulsing = false;
        float counter = 0.f; //計時器
        float liveTime;
        float deltaThickness;

        std::vector<sf::RectangleShape> dashLine;

        // UI Draw Function
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    public:
        // Constructor
        PulseLaser(sf::Vector2f position, int &thickness, float &angle, float &delay, float &powerTime, float &duration, int &dashLineLength, int &dashLineThickness, Color &color, sf::FloatRect &borderRect, ParticleSystemProp &prop);
        ~PulseLaser();

        // Accessors
        void setColor(Color &color) override;                       //設定顏色
        void setPosition(sf::Vector2f &point) override;             //設定位置
        bool isCollided(sf::Vector2f &point, int &radius) override; //是否碰撞

        // Update Events
        void update(float &deltaTime) override; //更新
    };
};