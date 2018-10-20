#include "Parser.h"
#include <fstream>
#include <string>
#include <utility>

std::pair<std::map<std::pair<std::string, std::string>, int>,std::vector<std::string>> Parser::prepareData(const char * path)
{
	std::string token = " ";
	std::fstream file(path, std::ios::in);
	std::string line;

	std::map < std::pair < std::string, std::string>, int> distances;
	std::vector<std::string> cities;

	while (!file.eof()) {
		std::getline(file, line);
		std::size_t position;
		std::vector<std::string> words;
		for (int i = 0; i < 5; ++i) {
			position = line.find(token);
			words.emplace_back(line.substr(0, position));
			line.erase(0, position + token.length());

		}
		distances[std::pair<std::string,std::string>(words[0], words[2])] = std::stoi(words[4]);
		distances[std::pair<std::string, std::string>(words[2], words[0])] = std::stoi(words[4]);

		if (cities.end() == std::find(cities.begin(), cities.end(), words[0])) {
			cities.push_back(words[0]);
		}
		if (cities.end() == std::find(cities.begin(), cities.end(), words[2])) {
			cities.push_back(words[2]);
		}

	}

	file.close();

	return{ std::move(distances), std::move(cities) };
}
