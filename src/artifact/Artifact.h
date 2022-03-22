//============================================================================
// Name        : Artifact.h
// Author      : Federico Carne 1059865
// Date		   : 25 feb 2022
// Description : 
//============================================================================
#ifndef ARTIFACT_ARTIFACT_H_
#define ARTIFACT_ARTIFACT_H_

#include <string>
#include <functional>
#include <memory>

class Hero;

class Artifact {
private:
	std::string name;
	std::string description;
	bool automaticActivation;
	std::function<void(std::shared_ptr<Hero>)> _effect;
public:
	Artifact(std::string name, std::string description, bool automaticActivation, std::function<void(std::shared_ptr<Hero>)> effect);
	virtual ~Artifact() = default;

	std::string getName() const;
	std::string getDescription() const;
	virtual std::string toString();
	bool isAutomatic();

	virtual void activate(std::shared_ptr<Hero>) final;
};

#endif /* ARTIFACT_ARTIFACT_H_ */
