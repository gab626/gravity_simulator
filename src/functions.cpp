#include "functions.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

float grv::norm(const vector2& vector) {
  return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

vector2 grv::unitVector(const Body& firstBody, const Body& secondBody) {
  return (secondBody.getPosition() - firstBody.getPosition()) /
         grv::norm(secondBody.getPosition() - firstBody.getPosition());
}

vector2 grv::gravityForce(const Body& firstBody, const Body& secondBody) {
  vector2 direction = grv::unitVector(firstBody, secondBody);
  float distance2 = grv::norm(direction) * grv::norm(direction);
  return direction *
         (firstBody.getMass() * secondBody.getMass() / distance2);
}

vector2 grv::totalForce(const Body& body, const std::vector<Body>& system) {
  vector2 sumAccelerations =
      std::accumulate(system.begin(), system.end(), vector2{0.f, 0.f},
                      [&](const vector2& sum, const Body& otherBody) {
                        if (&body != &otherBody) {
                          return sum + grv::gravityForce(body, otherBody);
                        } else {
                          return sum;
                        }
                      });
  return sumAccelerations;
}

void grv::updateSystem(std::vector<Body>& system) {
  std::vector<Body> newStates;
  std::for_each(system.begin(), system.end(), [&](Body& body) {
    vector2 acceleration = grv::totalForce(body, system) / body.getMass();
    vector2 velocity = body.getVelocity() + acceleration * 0.001f;
    vector2 position = body.getPosition() + body.getVelocity() * 0.001f +
                       acceleration * 0.5f * 0.001f * 0.001f;
    newStates.push_back(Body{body.getMass(), position, velocity,
                             body.getShape().getFillColor()});
  });
  std::move(newStates.begin(), newStates.end(), system.begin());
}

/* float grv::randomFloat(float minimum, float maximum) {
  std::random_device seed;
  std::default_random_engine engine(seed());
  std::uniform_real_distribution<float> unif(minimum, maximum);
  return unif(engine);
}

vector2 grv::randomVelocity(float minimum, float maximum) {
  float rho = grv::randomFloat(minimum, maximum);
  float theta = grv::randomFloat(0, 2.f * M_PI);
  return {rho * std::cos(theta), rho * std::sin(theta)};
} */