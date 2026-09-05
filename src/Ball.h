#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::Vector2f m_Position;
    sf::RectangleShape m_BallShape;

    float m_Speed = 500;
    float m_DirectionX = 1.f;
    float m_DirectionY = 1.f;

public:
    Ball(float startX, float startY);

    sf::FloatRect getPosition();
    sf::RectangleShape getBallShape();

    float getXVelocity();

    void bounceSide();

    void bounceTop();

    void missSide();

    void hitBall();

    void updateBall(sf::Time dt);

};
