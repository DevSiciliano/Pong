#include <SFML/Graphics.hpp>
#include "Ball.h"
#include <optional>

int main() {
    sf::VideoMode VM({1280u, 720u});
    sf::RenderWindow window(VM, "Pong Game");
    sf::Clock clock;
    Ball ball(1280/2, 0);

    sf::Time dt;

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        dt = clock.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window.close();
        }


        if (ball.getPosition().position.x < 0.f || ball.getPosition().position.x + ball.getPosition().size.x > 1280)
        {
            ball.bounceSide();
        }

        if (ball.getPosition().position.y < 0.f)
        {
            ball.bounceTop();
        }

        if (ball.getPosition().position.y + ball.getPosition().size.y > 720)
        {
            ball.missBottom();
        }

        window.clear(sf::Color::Black);
        ball.updateBall(dt);
        window.draw(ball.getBallShape());
        window.display();
    }

    return 0;
}