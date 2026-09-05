//
// Created by Massimo on 05.09.2026.
//

#include "Paddle.h"

Paddle::Paddle(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setSize(sf::Vector2f(10, 100));
    m_Shape.setPosition(m_Position);
}

sf::RectangleShape Paddle::getShape()
{
    return m_Shape;
}

sf::Vector2f Paddle::getPosition()
{
    return m_Position;
}

float Paddle::getSpeed()
{
    return m_Speed;
}

void Paddle::moveLeft()
{
}

void Paddle::moveRight()
{
}

void Paddle::stopLeft()
{
}

void Paddle::stopRight()
{
}

void Paddle::update(sf::Time dt)
{
}
