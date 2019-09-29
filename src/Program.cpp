#include "Program.h"

// float Program::offset[] = { 0,0 };

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

	mousePosition = new glm::vec3(0);

	InputHandler::setUp(renderEngine, mousePosition);
	mainLoop();
}

// Creates GLFW window for the program and sets callbacks for input
void Program::setupWindow() {
	glfwSetErrorCallback(Program::error);
	if (glfwInit() == 0) {
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_SAMPLES, 16);
	window = glfwCreateWindow(1920, 1080, "CPSC 589 A1 - hypocycloids & polynomial curve", NULL, NULL);
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

		float fontSize = 1.75f;
		ImGui::SetWindowFontScale(fontSize);

		ImGui::ColorEdit3("clear color", (float*)&clear_color);
		ImGui::ColorEdit4("line color", (float*)&lineColor);
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
			enablePoints = false;
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
			enablePoints = false;
			offset[0] = 0;
			offset[1] = 0;


			theta = 0;
			thetaCi = 0;
			thetaCo = 0;
		}

		ImGui::SameLine();

		ImGui::Checkbox("pause animation", (bool*)&pauseAnimation);

		ImGui::SameLine();

		ImGui::Checkbox("view hypocycloid", (bool*)&viewHypocycloid);

		ImGui::DragInt("circle resolutions", (int*)&circleDetail, 1);
		if (circleDetail < 1) {
			circleDetail = 1;
		}
		ImGui::Checkbox("hide inner circle", (bool*)&hideInnerCircle);

		ImGui::SameLine();

		ImGui::Checkbox("hide outer circle", (bool*)&hideOuterCircle);

		ImGui::SameLine();

		ImGui::Checkbox("hide leading dot", (bool*)&hideDot);



		if (ImGui::Button("apply scale & translation to points")) {
			applyPolynomialScale = true;
		}

		ImGui::SameLine();

		ImGui::Checkbox("enable placing control points", (bool*)&enablePoints);
		if(enablePoints) {
			mousePosition->z = 0;
		}

		ImGui::DragFloat("polynomial point scale", (float*)&polynomialScale, 0.001f);

		ImGui::DragFloat2("translate the model", (float*)&offset, 0.01f);

		ImGui::End();
	}
}

void Program::createCycloid() {
	hypocycloid = new Geometry;
	renderEngine->assignBuffers(*hypocycloid);
	updateCycloid();
	geometryObjects.push_back(hypocycloid);
}

int resumeValue = 1;
void Program::updateCycloid() {
	if(parametersChanged){
		hypocycloid->verts.clear();
	}
	if (theta > (PI * 2 * cycles) || pauseAnimation) {
		if(amount>0) {
			resumeValue = amount;
		}
		amount = 0;
	}
	else {
		if (amount == 0) {
			amount = resumeValue;
		}

	}
	// draw the hypocycloid
	for (int x = 0; x < amount; x++){
		if (theta < (PI * 2 * cycles)) {
			theta += (float)1 / (float)step;
		}

		float radiusDif = (outerRadius - innerRadius);
		float ratio = ((radiusDif / innerRadius) / innerRadius) * theta;
		hypocycloid->verts.push_back(glm::vec3(
			(radiusDif*cos(theta) + innerRadius * cos(ratio)),
			(radiusDif*sin(theta) - innerRadius * sin(ratio)),
			0.f));
	}

	// scale or rotate the hypocycloid
	hypocycloid->modelMatrix = glm::mat4(1.f);
	hypocycloid->modelMatrix = glm::translate(hypocycloid->modelMatrix, glm::vec3(offset[0], offset[1], 0.0f));
	hypocycloid->modelMatrix = glm::scale(hypocycloid->modelMatrix, glm::vec3(scale));
	hypocycloid->modelMatrix = glm::rotate(hypocycloid->modelMatrix, glm::radians(rotation), glm::vec3(0, 0, 1.0f));

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

	// draw the inner circle
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

	// scale or rotate the inner circle
	innerCircle->modelMatrix = glm::mat4(1.f);
	innerCircle->modelMatrix = glm::translate(innerCircle->modelMatrix, glm::vec3(offset[0], offset[1], 0.0f));
	innerCircle->modelMatrix = glm::scale(innerCircle->modelMatrix, glm::vec3(scale));
	innerCircle->modelMatrix = glm::rotate(innerCircle->modelMatrix, glm::radians(rotation), glm::vec3(0, 0, 1.0f));

	renderEngine->updateBuffers(*innerCircle);
}

void Program::updateOuterCircle() {
	if (hideOuterCircle) {
		outerCircle->verts.clear();
		return;
	}
	if (parametersChanged) {
		outerCircle->verts.clear();
	}

	// draw the outer circle
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
	// scale or rotate the outer circle
	outerCircle->modelMatrix = glm::mat4(1.f);
	outerCircle->modelMatrix = glm::translate(outerCircle->modelMatrix, glm::vec3(offset[0], offset[1], 0.0f));
	outerCircle->modelMatrix = glm::scale(outerCircle->modelMatrix, glm::vec3(scale));
	outerCircle->modelMatrix = glm::rotate(outerCircle->modelMatrix, glm::radians(rotation), glm::vec3(0, 0, 1.0f));

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

	// scale or rotate the line indicator point with everything else
	lastPoint->modelMatrix = glm::mat4(1.f);
	lastPoint->modelMatrix = glm::translate(lastPoint->modelMatrix, glm::vec3(offset[0], offset[1], 0.0f));
	lastPoint->modelMatrix = glm::scale(lastPoint->modelMatrix, glm::vec3(scale));
	lastPoint->modelMatrix = glm::rotate(lastPoint->modelMatrix, glm::radians(rotation), glm::vec3(0, 0, 1.0f));

	renderEngine->updateBuffers(*lastPoint);
}

void Program::createPolynomial(){
	polynomialPoints = new Geometry;
	polynomialLine = new Geometry;
	polynomialPoints->drawMode = GL_POINTS;
	renderEngine->assignBuffers(*polynomialPoints);
	renderEngine->assignBuffers(*polynomialLine);
	updatePolynomialPoints();
	updatePolynomialLines();
	geometryObjects.push_back(polynomialPoints);
	geometryObjects.push_back(polynomialLine);
}

//Keeps track of how many mouse clicks there were
int pointCounter = 0;
void Program::updatePolynomialLines() {

	polynomialLine->verts.clear();

	float polyLineStep = 0.0001;
	float uValue = 0;
	if(pointCounter>2)	{
		while (uValue<=1){
			glm::vec3 curveValues = polynomialPoints->verts[0] + polynomialPoints->verts[1] * glm::vec1(uValue) + polynomialPoints->verts[2] * glm::vec1(uValue * uValue);
			polynomialLine->verts.push_back(curveValues);

			// Update uValue
			uValue+=polyLineStep;
		}
	}
	polynomialLine->modelMatrix = glm::mat4(1.f);
	polynomialLine->modelMatrix = glm::scale(polynomialLine->modelMatrix, glm::vec3(scale));
	polynomialLine->modelMatrix = glm::rotate(polynomialLine->modelMatrix, glm::radians(rotation), glm::vec3(0, 0, 1.0f));

	renderEngine->updateBuffers(*polynomialLine);

}

void Program::updatePolynomialPoints(){
	if (parametersChanged) {
		polynomialPoints->verts.clear();
		pointCounter = 0;
	}
	// std::cout << mousePosition->x << "," << mousePosition->y << "," << mousePosition->z << std::endl;
	//check that a click has been done
	int width, height;
	if(mousePosition->z==1 && pointCounter<3 && enablePoints){
		glfwGetWindowSize(window, &width, &height);
		glm::vec2 mousePosFix = glm::vec2(
			((mousePosition->x - (float)width/2)/((float)width/2)) * 10 * (float)width / (float)height,
			(((float)height/2 - mousePosition->y)/((float)height/2)) * 10
		);
		// std::cout << mousePosFix.x << "," << mousePosFix.y << std::endl;

		// Add the point and a curve from that point
		polynomialPoints->verts.push_back(glm::vec3(mousePosFix.x, mousePosFix.y, 0.f));
		// polynomialLine->verts.push_back(glm::vec3(mousePosFix.x, mousePosFix.y, 0.f));

		// Reset the click counter
		mousePosition->z = 0;
		pointCounter++;
	}


	if (pointCounter > 2 && applyPolynomialScale) {
		for (int i = 0; i < pointCounter; i++) {
			polynomialPoints->verts[i] *= polynomialScale;
			polynomialPoints->verts[i] += glm::vec3(offset[0], offset[1], 0.0f);
			// std::cout << polynomialPoints->verts[i][0] << ", " << polynomialPoints->verts[i][1] << ", "<<i << std::endl;
		}
		polynomialScale = 1;
		offset[0] = 0;
		offset[1] = 0;
		applyPolynomialScale = false;
	}

	// scale or rotate the polynomial
	polynomialPoints->modelMatrix = glm::mat4(1.f);
	polynomialPoints->modelMatrix = glm::scale(polynomialPoints->modelMatrix, glm::vec3(scale));
	polynomialPoints->modelMatrix = glm::rotate(polynomialPoints->modelMatrix, glm::radians(rotation), glm::vec3(0, 0, 1.0f));

	renderEngine->updateBuffers(*polynomialPoints);
}
// Main loop
void Program::mainLoop() {
	// createTestGeometryObject();
	createCycloid();

	createOuterCircle();
	createInnerCircle();
	createLastPoint();

	createPolynomial();

	// Our state
	show_test_window = false;
	clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);
	lineColor = ImVec4(1.0f, 1.0f, 0.0f, 1.00f);

	while(!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		if(viewHypocycloid) {
			updateCycloid();
			updateInnerCircle();
			updateOuterCircle();
			updateLastPoint();
			mousePosition->z = 0;
		}
		else {
			lastPoint->verts.clear();
			outerCircle->verts.clear();
			innerCircle->verts.clear();
			hypocycloid->verts.clear();

			theta = 0;
			thetaCi = 0;
			thetaCo = 0;

			updatePolynomialPoints();
			updatePolynomialLines();
		}
		if (parametersChanged) {
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

		renderEngine->render(geometryObjects, glm::mat4(1.f), glm::vec4(lineColor.x,lineColor.y,lineColor.z,lineColor.w));
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
