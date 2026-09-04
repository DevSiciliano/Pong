#include <SFML/Graphics.hpp>

#include <optional>

int main() {
    sf::VideoMode VM({1280u, 720u});
    sf::RenderWindow window(VM, "Pong Game");

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}