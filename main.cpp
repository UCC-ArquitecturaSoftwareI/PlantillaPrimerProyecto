#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <tmxlite/Layer.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  std::vector<sf::Sprite> map_sprites;

  tmx::Map ma p;
  if (map.load("assets/mapas/mapa.tmx")) {
    std::cout << "encontré mapa" << std::endl;
    const auto &layers = map.getLayers();
    for (const auto &layer : layers) {
      std::cout << "encontré layer " << layer->getName() << std::endl;
      if (layer->getType() == tmx::Layer::Type::Object) {
        const auto &objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
        const auto &objects = objectLayer.getObjects();
        for (const auto &object : objects) {
          std::cout << object.getName() << std::endl;
        }

      } else if (layer->getType() == tmx::Layer::Type::Tile) {
        const auto &tileLayer = layer->getLayerAs<tmx::TileLayer>();
      }
      const auto &tilesets = map.getTilesets();
      for (const auto &tileset : tilesets) {
        std::cout << tileset.getName() << std::endl;
      }
    }
  }

  sf::Clock globalClock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    // sf::Time duration = globalClock.restart();

    window.clear(sf::Color::Black);
    window.display();
  }

  return 0;
}
