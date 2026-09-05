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

void Paddle::moveUp()
{
    m_MovingUp = true;
}

void Paddle::moveDown()
{
    m_MovingDown = true;
}

void Paddle::stopUp()
{
    m_MovingUp = false;
}

void Paddle::stopDown()
{
    m_MovingDown = false;
}

void Paddle::update(sf::Time dt)
{
    if (m_MovingUp)
        m_Position.y -= m_Speed * dt.asSeconds();

    if (m_MovingDown)
        m_Position.y += m_Speed * dt.asSeconds();

    const float height = m_Shape.getSize().y;
    if (m_Position.y < 0.0f)
        m_Position.y = 0.0f;
    if (m_Position.y + height > 720.0f)
        m_Position.y = 720.0f - height;

    m_Shape.setPosition(m_Position);
}
