#include <SFML/Graphics.hpp>
#include "Ball.h"
#include <optional>

#include "Paddle.h"

int main() {
    sf::VideoMode VM({1280u, 720u});
    sf::RenderWindow window(VM, "Pong Game");
    sf::Clock clock;

    Ball ball(1280/2, 0);
    Paddle leftPaddle(50, 50);
    Paddle rightPaddle(1280 - 50, 50);

    sf::Time dt;

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        dt = clock.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }


        if (ball.getPosition().position.y < 0.f || ball.getPosition().position.y + ball.getPosition().size.y > 720)
        {
            ball.bounceSide();
        }

        if (ball.getPosition().position.x < 0.f)
        {
            ball.bounceTop();
        }

        if (ball.getPosition().position.x + ball.getPosition().size.x > 1280)
        {
            ball.missSide();
        }

        window.clear(sf::Color::Black);

        using Key = sf::Keyboard::Key;
        sf::Keyboard::isKeyPressed(Key::W) ? leftPaddle.moveUp() : leftPaddle.stopUp();
        sf::Keyboard::isKeyPressed(Key::S) ? leftPaddle.moveDown() : leftPaddle.stopDown();
        sf::Keyboard::isKeyPressed(Key::Up) ? rightPaddle.moveUp() : rightPaddle.stopUp();
        sf::Keyboard::isKeyPressed(Key::Down) ? rightPaddle.moveDown() : rightPaddle.stopDown();

        // Left paddle
        leftPaddle.update(dt);
        window.draw(leftPaddle.getShape());
        // Right paddle
        rightPaddle.update(dt);
        window.draw(rightPaddle.getShape());

        ball.updateBall(dt);
        window.draw(ball.getBallShape());

        window.display();
    }

    return 0;
}
