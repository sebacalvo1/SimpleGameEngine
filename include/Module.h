#pragma once

//Ill have to rethink this name, module is reserved word
class Module {
private:
public:
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
};