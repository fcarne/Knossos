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

class Artifact {
private:
	std::string name;
	std::function<void(void)> _effect;
public:
	virtual ~Artifact() = default;
	virtual void effect();
};

#endif /* ARTIFACT_ARTIFACT_H_ */
