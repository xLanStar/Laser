#pragma once

#include <functional>
#include "SFML/Audio.hpp"
#include "Game/GameObject/Text.h"

namespace GameObject
{
    class Button : public GameObject
    {
    public:
        Button(sf::Vector2f position, Color &color, sf::Font &font, std::string str, int characterSize, sf::SoundBuffer &soundBuffer, std::function<void()> onClick, float characterScaler = 1.2);

        void setColor(Color &color) override;             // 設定顏色
        void setPosition(sf::Vector2f position) override; // 設定位置

        void updateMouseMove(sf::Vector2f &point) override;    // 滑鼠移動
        void updateMousePress(sf::Vector2f &point) override;   // 滑鼠按下
        void updateMouseRelease(sf::Vector2f &point) override; // 滑鼠放開
        void update(float deltaTime) override;                 // 更新

    private:
        bool pressed;          // 是否滑鼠按著
        bool hover;            // 是否物件被點擊
        Text text;             // 文字
        int characterSize;     // 字元大小
        float characterScaler; // 放大倍率
        sf::Sound sound;       // 聲音

        std::function<void()> onClick; // 被點擊時要觸發的 function

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; // 渲染
    };
};