#pragma once

class Module {
private:
public:
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
};