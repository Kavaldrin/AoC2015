#pragma once
#include <map>
#include <vector>
class Parser
{
public:
	Parser() = delete;
	static std::pair<std::map<std::pair<std::string, std::string>, int>, std::vector<std::string>> prepareData(const char * path);

};

