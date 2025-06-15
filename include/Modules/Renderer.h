#include <Module.h>

#pragma once

class Renderer : public Module {
private:
	//pointer to model
public:
	void Init();
	void Update(float deltaTime);
	void Draw();
};