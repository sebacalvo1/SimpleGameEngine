#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Engine.h>

Engine* Engine::enginePtr = nullptr;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Engine::Engine() {
	enginePtr = this;
}

int Engine::Init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "SimpleOpenGLWindow", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	//Setup View Window
	glViewport(0, 0, 800, 600);

	return 0;
}

void Engine::Close() {
	glfwTerminate();
}

Engine* Engine::GetInstance() {
	if (enginePtr == NULL) {
		enginePtr = new Engine();
	}
	return enginePtr;
}

void Engine::GameLoop() {
	double currentFrame = glfwGetTime();
	double lastFrame = 0;
	double deltaTime;

	bool exitGame = false;
	while (!exitGame) {
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		float deltaTime = 0;
		CallUpdates(deltaTime);
		DrawScene();
	}
}

void Engine::DrawScene() {
	int size = renderers.size();
	//To change for iterator like loop
	for (int i = 0; i < size; i++) {
		renderers.at(i).Draw();
	}
}

void Engine::CallUpdates(float deltaTime) {
	int size = entities.size();
	//To change for iterator like loop
	for (int i = 0; i < size; i++) {
		entities.at(i).Update(deltaTime);
	}
}