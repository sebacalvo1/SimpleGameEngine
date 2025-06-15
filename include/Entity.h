#include <vector>
#include <Module.h>

#pragma once

class Entity {
private:
	std::vector<Module> modules;
public:
	void Init();
	void Update(float deltaTime);
};