#include <iostream>
#include "Parser.h"
#include "Solver.h"



int main()
{
	
	auto pr = Parser::prepareData("file.txt");
	Solver solver(std::move(pr.first), std::move(pr.second));
	//solver.naiveRSolution();
	solver.naiveISolution();
	solver.printSolution();
	system("pause");
	return 0;
}

