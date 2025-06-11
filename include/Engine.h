

#pragma once

//Singleton
class Engine {
private:
	static Engine* enginePtr;
public:
	Engine();
	Engine(const Engine& obj) = delete;
	static Engine* GetInstance();
	int Init();
	void Close();
};