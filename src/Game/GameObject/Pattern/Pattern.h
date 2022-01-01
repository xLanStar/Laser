#pragma once

#include "Game/GameObject/GameObject.h"

namespace GameObject
{
    class Pattern : public GameObject
    {
    public:
        Pattern(Color &color, std::string name, int radius = 52, int boundRoundThickness = 5);

        const std::string &getName() const; //取得 Pattern 的名稱
        int getRadius() const;              //取得 Pattern 的半徑

        void setName();                                //設定 Pattern 的名稱
        void setRadius(int radius);                    //設定半徑
        void setColor(Color &color) override;          //設定顏色
        void setPosition(sf::Vector2f point) override; //設定位置

        virtual void updateMouseMove(sf::Vector2f &point); //滑鼠移動的觸發事件

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    protected:
        int radius; //半徑長

    private:
        int boundRoundThickness; //外圓線寬
        std::string name;        // Pattern 的名稱

        sf::CircleShape boundRound; //外圓

        void setupShape(); //設定圖形
    };
};