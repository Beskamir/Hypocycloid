#include "Program.h"

Program::Program() {
	window = nullptr;
	renderEngine = nullptr;
}

// Error callback for glfw errors
void Program::error(int error, const char* description) {
	std::cerr << description << std::endl;
}

// Called to start the program
void Program::start() {
	setupWindow();
	GLenum err = glewInit();
	if (glewInit() != GLEW_OK) {
		std::cerr << glewGetErrorString(err) << std::endl;
	}

	/*
	bool err = gl3wInit() != 0;

	if (err)
	{
		fprintf(stderr, "Failed to initialize OpenGL loader!\n");
	}
	*/
	renderEngine = new RenderEngine(window);
	InputHandler::setUp(renderEngine);
	mainLoop();
}

// Creates GLFW window for the program and sets callbacks for input
void Program::setupWindow() {
	glfwSetErrorCallback(Program::error);
	if (glfwInit() == 0) {
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_SAMPLES, 16);
	window = glfwCreateWindow(1024, 1024, "CPSC 589 A1 - hypocycloids", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // V-sync on

	glfwSetKeyCallback(window, InputHandler::key);
	glfwSetMouseButtonCallback(window, InputHandler::mouse);
	glfwSetCursorPosCallback(window, InputHandler::motion);
	glfwSetScrollCallback(window, InputHandler::scroll);
	glfwSetWindowSizeCallback(window, InputHandler::reshape);

	// Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();

	const char* glsl_version = "#version 430 core";

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

// Creates an object from specified vertices - no texture. Default object is a 2D triangle.
void Program::createTestGeometryObject() {
	Geometry* testObject = new Geometry();

	testObject->verts.push_back(glm::vec3(-5.f, -3.f, 0.f));
	testObject->verts.push_back(glm::vec3(5.f, -3.f, 0.f));
	testObject->verts.push_back(glm::vec3(0.f, 5.f, 0.f));
	renderEngine->assignBuffers(*testObject);
	renderEngine->updateBuffers(*testObject);
	geometryObjects.push_back(testObject);
}


void Program::drawUI() {
	// Start ImGui frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// Setup all the buttons for ImGui interaction
	{
		ImGui::Begin("UI Controls");
		ImGui::ColorEdit3("clear color", (float*)&clear_color);
		ImGui::DragFloat("small circle radius", (float*)&innerRadius, 0.001f);
		ImGui::DragFloat("large circle radius", (float*)&outerRadius, 0.001f);
		ImGui::DragInt("number of cycles", (int*)&cycles);
		if (cycles < 1) {
			cycles = 1;
		}
		
		ImGui::DragFloat("rotation", (float*)&rotation, 0.1f);
		ImGui::DragFloat("scale factor", (float*)&scale, 0.001f);
		ImGui::DragInt("hypocycloid resolution", (int*)&step, 1);
		if (step < 1) {
			step = 1;
		}
		ImGui::DragInt("draws before updating", (int*)&amount, 1);
		if(amount<0) {
			amount = 0;
		}

		if (ImGui::Button("refresh")) {
			parametersChanged = true;
			theta = 0;
			thetaCi = 0;
			thetaCo = 0;
		}

		ImGui::SameLine();

		if (ImGui::Button("reset to defaults")) {
			outerRadius = 4;
			innerRadius = 1;
			cycles = 1;
			rotation = 0;
			scale = 1;
			amount = 1;
			step = 100;
			circleDetail = 100;
			parametersChanged = true;
			hideInnerCircle = false;
			hideOuterCircle = false;
			hideDot = false;

			theta = 0;
			thetaCi = 0;
			thetaCo = 0;
		}

		ImGui::DragInt("circle resolutions", (int*)&circleDetail, 1);
		if (circleDetail < 1) {
			circleDetail = 1;
		}
		ImGui::Checkbox("hide inner circle", (bool*)&hideInnerCircle);

		ImGui::SameLine();

		ImGui::Checkbox("hide outer circle", (bool*)&hideOuterCircle);

		ImGui::SameLine();

		ImGui::Checkbox("hide leading dot", (bool*)&hideDot);

	

		ImGui::End();
	}
}

void Program::createCycloid() {
	hypocycloid = new Geometry;
	renderEngine->assignBuffers(*hypocycloid);
	updateCycloid();
	geometryObjects.push_back(hypocycloid);
}

void Program::updateCycloid() {
	if(parametersChanged){
		hypocycloid->verts.clear();
		// parametersChanged = false;
	}

	// draw the hypocycloid
	for (int x = 0; x < amount; x++){
		theta += (float) 1 / (float) step;
		if (theta > (PI * 2 * cycles)) {
			theta = 0;
		}
		float radiusDif = (outerRadius - innerRadius);
		float ratio = ((radiusDif / innerRadius) / innerRadius) * theta;
		hypocycloid->verts.push_back(glm::vec3(
			(radiusDif*cos(theta) + innerRadius * cos(ratio)),
			(radiusDif*sin(theta) - innerRadius * sin(ratio)),
			0.f));
	}

	// scale or rotate the hypocycloid
	hypocycloid->modelMatrix = glm::scale(glm::mat4(1.f), glm::vec3(scale));
	hypocycloid->modelMatrix *= glm::rotate(glm::mat4(1.f), glm::radians(rotation), glm::vec3(0, 0, 1.0f));

	renderEngine->updateBuffers(*hypocycloid);
}

void Program::createInnerCircle(){
	innerCircle = new Geometry;
	renderEngine->assignBuffers(*innerCircle);
	updateInnerCircle();
	geometryObjects.push_back(innerCircle);
}

void Program::createOuterCircle() {
	outerCircle = new Geometry;
	renderEngine->assignBuffers(*outerCircle);
	updateOuterCircle();
	geometryObjects.push_back(outerCircle);
}



void Program::updateInnerCircle() {
	innerCircle->verts.clear();
	
	if (hideInnerCircle) {
		return;
	}

	// draw the hypocycloid
	for (int x = 0; x < (PI * 2 * circleDetail) + 1; x++) {
		thetaCi += (float) 1 / (float) circleDetail;
		if (thetaCi > (PI * 2)) {
			thetaCi = 0;
		}
		innerCircle->verts.push_back(glm::vec3(
			innerRadius*(cos(thetaCi)) + (outerRadius - innerRadius) * cos(theta),
			innerRadius*(sin(thetaCi)) + (outerRadius - innerRadius) * sin(theta),
			0.f));
	}

	// scale or rotate the hypocycloid
	innerCircle->modelMatrix = glm::scale(glm::mat4(1.f), glm::vec3(scale));
	innerCircle->modelMatrix *= glm::rotate(glm::mat4(1.f), glm::radians(rotation), glm::vec3(0, 0, 1.0f));

	renderEngine->updateBuffers(*innerCircle);
}

void Program::updateOuterCircle() {
	if (hideOuterCircle) {
		outerCircle->verts.clear();
		return;
	}
	if (parametersChanged) {
		outerCircle->verts.clear();
		// parametersChanged = false;
	}

	// draw the hypocycloid
	for (int x = 0; x < (PI * 2 * circleDetail) + 1; x++) {
		thetaCo += (float) 1 / (float) circleDetail;
		if (thetaCo > (PI * 2)) {
			thetaCo = 0;
		}
		outerCircle->verts.push_back(glm::vec3(
			outerRadius*(cos(thetaCo)),
			outerRadius*(sin(thetaCo)),
			0.f));
	}

	// scale or rotate the hypocycloid
	outerCircle->modelMatrix = glm::scale(glm::mat4(1.f), glm::vec3(scale));
	outerCircle->modelMatrix *= glm::rotate(glm::mat4(1.f), glm::radians(rotation), glm::vec3(0, 0, 1.0f));

	renderEngine->updateBuffers(*outerCircle);
}

void Program::createLastPoint() {
	lastPoint = new Geometry;
	lastPoint->drawMode = GL_POINTS;
	renderEngine->assignBuffers(*lastPoint);
	updateLastPoint();
	geometryObjects.push_back(lastPoint);
}

void Program::updateLastPoint() {
	lastPoint->verts.clear();
	if(hideDot)	{
		return;
	}
	float radiusDif = (outerRadius - innerRadius);
	float ratio = ((radiusDif / innerRadius) / innerRadius) * theta;
	lastPoint->verts.push_back(glm::vec3(
		(radiusDif*cos(theta) + innerRadius * cos(ratio)),
		(radiusDif*sin(theta) - innerRadius * sin(ratio)),
		0.f));

	// scale or rotate the hypocycloid
	lastPoint->modelMatrix = glm::scale(glm::mat4(1.f), glm::vec3(scale));
	lastPoint->modelMatrix *= glm::rotate(glm::mat4(1.f), glm::radians(rotation), glm::vec3(0, 0, 1.0f));

	renderEngine->updateBuffers(*lastPoint);
}

// Main loop
void Program::mainLoop() {

	// createTestGeometryObject();
	createCycloid();

	createOuterCircle();
	createInnerCircle();
	createLastPoint();

	// Our state
	show_test_window = false;
	clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		updateCycloid();
		updateInnerCircle();
		updateOuterCircle();
		updateLastPoint();
		if(parametersChanged){
			parametersChanged = false;
		}

		drawUI();

		// Rendering
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);

		renderEngine->render(geometryObjects, glm::mat4(1.f));
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	// Clean up, program needs to exit
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	delete renderEngine;
	glfwTerminate();
}
