#include "Geometry.h"

Geometry::Geometry() {
	drawMode = GL_LINE_STRIP;
	vao = 0;
	vertexBuffer = 0;
	modelMatrix = glm::mat4(1.f);
}
