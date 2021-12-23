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
        sf::FloatRect &borderRect;     //依賴邊界
        int &thickness;                //線寬
        bool destroyed = false;        //是否該被刪除
        ParticleSystem particleSystem; //附加的粒子效果
    protected:
        void destroy(); //改為可刪除

    public:
        // Constructor
        Laser(sf::Vector2f position, Color &color, int &thickness, sf::FloatRect &borderRect, ParticleSystemProp &prop);

        // Accessors
        bool isDestroyed() const;                                                       //回傳是否該被消除
        int getThickness() const;                                                       //回傳線寬
        void setColor(Color &color);                                                    //設定顏色
        void setPosition(sf::Vector2f position);                                        //設定位置
        sf::FloatRect &getBorderRect();                                                 //回傳
        ParticleSystem &getParticleSystem();                                            //回傳對應的粒子特效
        virtual bool isCollided(sf::Vector2f &point, int &radius) const = 0;            //是否被撞到
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0; //渲染
    };
};