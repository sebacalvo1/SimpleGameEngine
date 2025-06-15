#include <Entity.h>

void Entity::Init() {
	int size = modules.size();
	for (int i = 0; i < size; i++) {
		//Change to iterator later on
		modules.at(i).Init();
	}
}

void Entity::Update(float deltaTime) {
	int size = modules.size();
	for (int i = 0; i < size; i++) {
		//Change to iterator later on
		modules.at(i).Update(deltaTime);
	}
}