#include <vector>
#include <Entity.h>
#include <Modules/Renderer.h>

#pragma once

//Singleton
class Engine {
private:
	static Engine* enginePtr;
	std::vector<Entity> entities;
	std::vector<Renderer> renderers;

	void DrawScene();
	void CallUpdates(float deltaTime);
public:
	Engine();
	Engine(const Engine& obj) = delete;
	static Engine* GetInstance();
	int Init();
	void Close();
	void GameLoop();
};