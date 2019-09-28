#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

#include <vector>

class Geometry {

public:
	Geometry();

	GLuint drawMode;

	GLuint vao;
	GLuint vertexBuffer;
	std::vector<glm::vec3> verts;
	glm::mat4 modelMatrix;
};

