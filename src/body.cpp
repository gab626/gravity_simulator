#include "body.hpp"

using grv::Body;

Body::Body() {}

Body::Body(float mass, vector2 position, vector2 velocity, sf::Color color)
    : mass_{mass}, position_{position}, velocity_{velocity} {
  shape_.setFillColor(color);
  shape_.setRadius(5.f);
  shape_.setPosition(position_);
}

Body::~Body() {}

float Body::getMass() const { return mass_; }

sf::CircleShape Body::getShape() const { return shape_; }

vector2 Body::getPosition() const { return position_; }

vector2 Body::getVelocity() const { return velocity_; }

void Body::setPosition(vector2 position) { position_ = position; }

void Body::setVelocity(vector2 velocity) { velocity_ = velocity; }