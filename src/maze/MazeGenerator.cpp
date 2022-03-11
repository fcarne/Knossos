//============================================================================
// Name        : MazeGenerator.cpp
// Author      : Federico Carne 1059865
// Date		   : 25 gen 2022
// Description : MazeGenerator implementation
//============================================================================

#include <maze/MazeGenerator.h>

MazeGenerator::MazeGenerator(std::unique_ptr<MazeAlgorithm> &alg) {
	setAlgorithm(alg);
}

std::unique_ptr<Maze> MazeGenerator::generate(uint16_t height, uint16_t width,
		bool showConstruction, const Coordinates &startingCell,
		const Room &cellValue, const uint32_t seed) {
	if (width < 1 || height < 1)
		return nullptr;

	return algorithm->generate(height, width, showConstruction, startingCell,
			cellValue, seed);
}

void MazeGenerator::setAlgorithm(std::unique_ptr<MazeAlgorithm> &alg) {
	algorithm = std::move(alg);
}
