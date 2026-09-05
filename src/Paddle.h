#pragma once
#include <SFML/Graphics.hpp>

class Paddle
{
private:
    sf::RectangleShape m_Shape;
    sf::Vector2f m_Position;

    float m_Speed = 1100.0f;

    bool m_MovingUp = false;
    bool m_MovingDown = false;

public:
    Paddle(float startX, float startY);

    sf::RectangleShape getShape();
    sf::Vector2f getPosition();

    float getSpeed();

    void moveUp();
    void moveDown();
    void stopUp();
    void stopDown();

    void update(sf::Time dt);


};
