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
        Laser(sf::Vector2f position, Color &color, int thickness, float angle, sf::FloatRect &borderRect, ParticleSystemProp &prop);

        bool isDestroyed() const;                                 //回傳是否該被消除
        int getThickness() const;                                 //回傳線寬
        float getAngle() const;                                   //回傳角度
        ParticleSystem &getParticleSystem();                      //回傳對應的粒子特效
        virtual bool isCollided(const Pattern &player) const = 0; //檢查是否被撞到

    protected:
        int thickness;             //線寬
        void destroy();            //改為可刪除
        sf::FloatRect &borderRect; //邊界

    private:
        bool destroyed = false;                                                         //是否該被刪除
        float angle;                                                                    //角度
        ParticleSystem particleSystem;                                                  //附加的粒子效果
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0; //渲染
    };
};