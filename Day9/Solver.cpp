#include "Solver.h"
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

Solver::Solver(std::map<std::pair<std::string, std::string>, int> &&data, std::vector<std::string> &&cities)
{
	m_data = data;
	m_cities = cities;
	prepareData();
}

void Solver::naiveRSolution()
{
	for (int i = 0; i < m_cities.size(); ++i) {
		m_visited = 0;
		m_visited[i] = true;
		m_currPath.push_back(i);
		Rfun(1,0);
		
	}

	auto solution = std::min_element(m_distances.begin(), m_distances.end());
	m_finalAnswer = *solution;
	m_finalPath = m_paths[solution - m_distances.begin()];

	auto solution2 = std::max_element(m_distances.begin(), m_distances.end());
	m_secondFinalAnswer = *solution2;
	m_secondFinalPath = m_paths[solution2 - m_distances.begin()];

}

void Solver::Rfun(int rLevel,int currDistance)
{
	if (rLevel == m_cities.size()) {
		m_distances.push_back(currDistance);
		m_paths.push_back(m_currPath);
		m_visited[m_currPath.back()] = false;
		m_currPath.pop_back();
	}
	else {

		int lastCity = m_currPath.back();

		for (int i = 0; i < m_cities.size(); ++i) {
			if (!m_visited[i]) {
				m_visited[i] = true;
				m_currPath.push_back(i);
				Rfun(rLevel + 1, currDistance + m_graph[lastCity][i]);
			}
		}
		m_visited[lastCity] = false;
		m_currPath.pop_back();
	}

}

void Solver::naiveISolution()
{

	std::vector<int> cities;
	for (int i = 0; i < m_cities.size(); ++i) {
		cities.push_back(i);
	}

	do {
		m_currPath.clear();
		int distance = 0;

		for (int i = 0; i < m_cities.size() - 1; ++i) {
			distance += m_graph[cities[i]][cities[i + 1]];
			m_currPath.push_back(cities[i]);
		}

		m_currPath.push_back(cities.back());
		m_paths.push_back(m_currPath);
		m_distances.push_back(distance);


	} while (std::next_permutation(cities.begin(), cities.end()));


	auto solution = std::min_element(m_distances.begin(), m_distances.end());
	m_finalAnswer = *solution;
	m_finalPath = m_paths[solution - m_distances.begin()];

	auto solution2 = std::max_element(m_distances.begin(), m_distances.end());
	m_secondFinalAnswer = *solution2;
	m_secondFinalPath = m_paths[solution2 - m_distances.begin()];

	
}


void Solver::printSolution()
{
	std::cout << "Shortest path:";
	for (const auto& index : m_finalPath) {
		std::cout << " " << m_cities[index];
	}
	std::cout << std::endl << "Distance: " << m_finalAnswer << std::endl << std::endl;

	std::cout << "Longest path:";
	for (const auto& index : m_secondFinalPath) {
		std::cout << " " << m_cities[index];
	}
	std::cout << std::endl << "Distance: " << m_secondFinalAnswer << std::endl;


}

void Solver::printCities()
{
	for (const auto &city : m_cities) {
		std::cout << city << " ";
	}
}
void Solver::prepareData()
{
	for (auto it = m_cities.cbegin(); it != m_cities.cend(); ++it) {
		std::vector<int> distances;
		const std::string &currentCity = *it;
		for (auto jt = m_cities.cbegin(); jt != m_cities.cend(); ++jt) {
			if (jt != it) {
				distances.push_back(m_data[std::pair<std::string, std::string>(*it, *jt)]);
			}
			else {
				distances.push_back(0);
			}
		}
		m_graph.emplace_back(distances);
	}
}
void Solver::printGraph()
{
	for (const auto& vec : m_graph) {
		for (const auto& num : vec) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
}