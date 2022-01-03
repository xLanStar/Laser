// Laser 的抽象類別
#pragma once

#include "Game/GameObject/GameObject.h"
#include "Game/Particle/ParticleSystem.h"
#include "Game/Particle/ParticleSystemProp.h"
#include "Game/GameObject/Pattern/Pattern.h"

namespace GameObject
{
    class Laser : public GameObject
    {
    public:
        Laser(sf::Vector2f position, Color &color, int thickness, float arc, sf::FloatRect &borderRect, ParticleSystemProp &prop);

        bool isDestroyed() const;                                 // 回傳是否該被消除
        ParticleSystem &getParticleSystem();                      // 回傳對應的粒子特效
        virtual bool isCollided(const Pattern &player) const = 0; // 檢查是否被撞到

    protected:
        int thickness;                 // 線寬
        void destroy();                // 改為可刪除
        float arc;                     // 弧度
        sf::FloatRect &borderRect;     // GameState 的邊界
        sf::RectangleShape line;       // 線物件
        ParticleSystem particleSystem; // 該雷射所附加的粒子效果

    private:
        bool destroyed = false;                                                         // 是否該被刪除
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0; // 渲染
    };
};