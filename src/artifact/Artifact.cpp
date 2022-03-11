//============================================================================
// Name        : Artifact.cpp
// Author      : Federico Carne 1059865
// Date		   : 25 feb 2022
// Description : 
//============================================================================
#include <artifact/Artifact.h>

Artifact::Artifact(std::string name, std::string description,
		bool automaticActivation,
		std::function<void(std::shared_ptr<Hero>)> effect) :
		name(name), description(description), automaticActivation(
				automaticActivation), _effect(effect) {
}

std::string Artifact::getName() const {
	return name;
}

void Artifact::activate(std::shared_ptr<Hero> hero) {
	_effect(hero);
}
