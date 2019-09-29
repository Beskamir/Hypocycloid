#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "Geometry.h"
#include "InputHandler.h"
#include "RenderEngine.h"

class Program {

public:
	Program();
	void start();

private:
	GLFWwindow* window;
	RenderEngine* renderEngine;

	std::vector<Geometry*> geometryObjects;

	bool show_test_window;
	ImVec4 clear_color;

	static void error(int error, const char* description);
	void setupWindow();
	void mainLoop();
	void drawUI();

	void createTestGeometryObject();

	// draw the cycloid 
	void createCycloid();
	void updateCycloid();

	// draw the circles
	void createInnerCircle();
	void createOuterCircle();
	void updateInnerCircle();
	void updateOuterCircle();

	// draw a dot on the last point
	void createLastPoint();
	void updateLastPoint();


	void createPolynomial();
	void updatePolynomialPoints();
	void updatePolynomialLines();
	// PI constant since I'm too lazy to use a library when I can just copy paste
	float PI = 3.14159265358979323846264338327950288;
	
	// Class variables for controlling the hypocycloid.
	float outerRadius = 4;
	float innerRadius = 1;
	int cycles = 1;
	float rotation = 0;
	float scale = 1;
	int amount = 1;
	int step = 100;
	int circleDetail = 100;
	bool hideInnerCircle = false;
	bool hideOuterCircle = false;
	bool hideDot = false;
	bool enablePoints = false;

	bool pauseAnimation = false;

	bool viewHypocycloid = true;

	float theta = 0;
	float thetaCi = 0;
	float thetaCo = 0;

	bool parametersChanged = true;

	// Class variable for the hypocycloid
	Geometry* hypocycloid;
	Geometry* innerCircle;
	Geometry* outerCircle;
	Geometry* lastPoint;
	Geometry* polynomialPoints;
	Geometry* polynomialLine;

	glm::vec3 *mousePosition;

	float polynomialScale = 1;
	bool applyPolynomialScale = false;

	float offset[2] = { 0, 0 };

	ImVec4 lineColor;
};
