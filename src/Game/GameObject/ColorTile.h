#pragma once

#include "Game/GameObject/Text.h"
#include "Game/GameObject/Pantone.h"

namespace GameObject
{
    class ColorTile : public GameObject
    {
    private:
        int tileWidth;   //磁磚容器的寬度
        int tileHeight;  //磁磚容器的高度
        Text text;       //文字
        Pantone pantone; //色票
        bool pressed;    //是否被按著
        bool hover;      //是否被覆蓋

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //渲染

    public:
        ColorTile(sf::Vector2f position, sf::Font &font, Color &color, sf::SoundBuffer& soundBuffer, std::function<void()> onClick, int tileWidth = 250, int tileHeight = 120);

        void setColor(Color &color) override;             //設定顏色
        void setPosition(sf::Vector2f position) override; //設定位置

        void updateMouseMove(sf::Vector2f &point) override;    //滑鼠移動
        void updateMousePress(sf::Vector2f &point) override;   //滑鼠點擊
        void updateMouseRelease(sf::Vector2f &point) override; //滑鼠放開
    };
}
