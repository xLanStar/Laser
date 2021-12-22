// Laser 的抽象類別
#pragma once

#include "SFML/Graphics.hpp"

#include "Game/Game.h"
#include "Game/GameObject/GameObject.h"
#include "Game/Particle/ParticleSystem.h"
#include "Game/Particle/ParticleSystemProp.h"

namespace GameObject
{
    class Laser : public GameObject
    {
    private:
        sf::FloatRect &borderRect;
        int &thickness;                //線寬
        bool destroyed = false;        //是否該被刪除
        ParticleSystem particleSystem; //附加的粒子效果

    public:
        // Constructor
        Laser(sf::Vector2f position, Color &color, int &thickness, sf::FloatRect &borderRect, ParticleSystemProp &prop);

        // Accessors
        bool &isDestroyed();                                           //回傳是否該被消除
        void destroy();                                                //改為可刪除
        int getThickness() const;                                      //回傳線寬
        sf::FloatRect &getBorderRect();                                //回傳
        ParticleSystem &getParticleSystem();                           //回傳對應的粒子特效
        virtual void setColor(Color &color) = 0;                       //設定顏色
        virtual void setPosition(sf::Vector2f &point) = 0;             //設定位置
        virtual bool isCollided(sf::Vector2f &point, int &radius) = 0; //是否被撞到

        // Update Events
        virtual void update(float &deltaTime); //更新 要覆寫
    };
};