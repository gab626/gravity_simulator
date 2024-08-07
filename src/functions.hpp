#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>

#include "body.hpp"

namespace grv {

float norm(const vector2&);

vector2 unitVector(const Body&, const Body&);

vector2 gravityForce(const Body&, const Body&);

vector2 totalForce(const Body&, const std::vector<Body>&);

void updateSystem(std::vector<Body>&);

// float randomFloat(float, float);

// vector2 randomVelocity(float, float);

}  // namespace grv

#endif