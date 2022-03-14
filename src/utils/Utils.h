//============================================================================
// Name        : Utils.h
// Author      : Federico Carne 1059865
// Date		   : 14 mar 2022
// Description : 
//============================================================================
#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#include <libs/nlohmann/json.hpp>
#include <vector>
#include <unordered_map>
#include <functional>
#include <fstream>

namespace utils {
inline void clear_screen() {
#ifdef _WIN32
	std::system("cls");
#else
	// Assume POSIX
	std::system("clear");
#endif
}

template<class K, class V>
inline std::vector<K> keyList(std::unordered_map<K, V> map) {
	std::vector<K> keys;

	std::transform(map.begin(), map.end(), std::back_inserter(keys),
			[](const std::pair<K, V> &pair) {
				return pair.first;
			});

	return keys;
}

inline nlohmann::json readJsonFile(std::string filename) {
	std::ifstream i(filename);
	nlohmann::json j;
	i >> j;
	i.close();

	return j;
}

template<class E>
inline void parseJsonIntoList(std::string filename, std::vector<E> list,
		std::function<E(nlohmann::json)> parser) {

	auto j = readJsonFile(filename);

	list.clear();
	list.reserve(j.size());

	std::transform(j.begin(), j.end(), list.begin(), parser);
}

template<class K, class V>
inline void parseJsonIntoMap(std::string filename, std::unordered_map<K, V> map,
		std::function<std::pair<K, V>(nlohmann::json)> parser) {

	auto j = readJsonFile(filename);

	map.clear();
	map.reserve(j.size());

	std::transform(j.begin(), j.end(), std::inserter(map, map.end()), parser);
}
}

#endif /* UTILS_UTILS_H_ */
