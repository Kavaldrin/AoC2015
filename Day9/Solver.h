#pragma once
#include <map>
#include <vector>
#include <bitset>
#include <utility>

class Solver
{
public:
	Solver(std::map<std::pair<std::string, std::string>, int> &&data,std::vector<std::string> &&cities);
	void naiveRSolution();
	void naiveISolution();
	void printSolution();

	//////////////DEBUG FUN///////////////
	void printCities();
	void printGraph();
	//////////////////////////////////////

private:
	
	void Rfun(int rLevel,int currDistance);

	
	std::vector<int> m_distances;
	std::vector<std::vector<int>> m_paths;
	std::vector<int> m_currPath;
	std::bitset<16> m_visited;
	

	void prepareData();
	std::map<std::pair<std::string, std::string>, int> m_data;
	std::vector<std::string> m_cities;
	std::vector<std::vector<int>> m_graph;

	std::vector<int> m_finalPath;
	int m_finalAnswer = 0;

	std::vector<int> m_secondFinalPath;
	int m_secondFinalAnswer = 0;
};

