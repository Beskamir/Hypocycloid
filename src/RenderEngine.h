#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "Geometry.h"
#include "ShaderTools.h"

class RenderEngine {

public:
	RenderEngine(GLFWwindow* window);

	void render(const std::vector<Geometry*>& objects, glm::mat4 view);
	void assignBuffers(Geometry& object);
	void updateBuffers(Geometry& object);
	void deleteBuffers(Geometry& object);
	void setWindowSize(int width, int height);

private:
	GLFWwindow* window;

	GLuint mainProgram;

	glm::mat4 ortho;
};

