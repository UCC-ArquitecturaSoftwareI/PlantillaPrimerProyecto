#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  window.setFramerateLimit(60);

  sf::Texture tx_player;
  sf::Sprite player;

  if (!tx_player.loadFromFile("assets/images/player.png")) {
    std::cout << "Error loading player.png" << std::endl;
  }
  player.setTexture(tx_player);
  player.setTextureRect(sf::IntRect(0, 0, 265 / 2, 558 / 4));
  player.setPosition(sf::Vector2f(400.f, 300.f));

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    // Key Management
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      player.move(-2, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      player.move(2, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      player.move(0, 2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      player.move(0, -2);
    }

    window.clear(sf::Color::White);
    // Draw all entities.
    window.draw(player);
    window.display();
  }

  return 0;
}
