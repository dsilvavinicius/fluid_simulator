#include "engine\Boundary.h"

namespace engine {
	Boundary::Boundary(const glm::vec2& size, const glm::mat4x4 transform) {
		this->size = shared_ptr<glm::vec2>(new glm::vec2(size));
		this->transform = shared_ptr<glm::mat4x4>(new glm::mat4x4(transform));
	}
}