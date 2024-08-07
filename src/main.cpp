#include <algorithm>
#include <vector>

#include "body.hpp"
#include "functions.hpp"

using grv::Body;

int main() {
  sf::RenderWindow window(sf::VideoMode(1600, 900), "Window");
  window.setPosition(sf::Vector2i(10, 10));
  window.setFramerateLimit(60);
  std::vector<Body> system;
  system.push_back(
      Body{10000.f, {800.f, 450.f}, {0.f, 0.f}, sf::Color::Green});
  system.push_back(
      Body{1000.f, {800.f, 50.f}, {1000.f, 0.f}, sf::Color::Red});
  system.push_back(
      Body{1000.f, {800.f, 850.f}, {-1000.f, 0.f}, sf::Color::Blue});
  system.push_back(
      Body{1000.f, {400.f, 450.f}, {0.f, -1000.f}, sf::Color::Yellow});
  system.push_back(
      Body{1000.f, {1200.f, 450.f}, {0.f, 1000.f}, sf::Color::Magenta});

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear(sf::Color::Black);
    std::for_each(system.begin(), system.end(),
                  [&](const Body& body) { window.draw(body.getShape()); });
    grv::updateSystem(system);
    window.display();
  }
}