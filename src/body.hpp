#ifndef BODY_HPP
#define BODY_HPP

#include <SFML/Graphics.hpp>

using vector2 = sf::Vector2f;

namespace grv {

class Body {
 private:
  float mass_;
  vector2 position_;
  vector2 velocity_;
  sf::CircleShape shape_;

 public:
  Body();
  Body(float, vector2, vector2, sf::Color);
  ~Body();
  float getMass() const;
  sf::CircleShape getShape() const;
  vector2 getPosition() const;
  vector2 getVelocity() const;
  void setPosition(vector2);
  void setVelocity(vector2);
};

}  // namespace grv

#endif