#include "Boundary.h"

namespace engine {
	Boundary::Boundary(const glm::vec2& size, const glm::mat4x4 transform) {
		this->size = shared_ptr<glm::vec2>(new glm::vec2(size));
		this->transform = shared_ptr<glm::mat4x4>(new glm::mat4x4(transform));
	}

	/**
	 * A quad is rendered to update the internal cells and 4 lines are rendered to update the borders cells and apply
	 * boundary conditions.
	 */
	void Boundary::update() {

	}
}