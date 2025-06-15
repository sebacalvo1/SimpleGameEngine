#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Engine.h>
#include <iostream>

int main()
{
	Engine* engine = new Engine();
	int res = engine->Init();
	if (res == -1) {
		return -1;
	}
	engine->GameLoop();
	engine->Close();

	return 0;
}