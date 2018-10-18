#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
	std::ifstream memory_reading("file.txt");
	std::string str_m((std::istreambuf_iterator<char>(memory_reading)),std::istreambuf_iterator<char>());
	memory_reading.close();
	int memory_len = str_m.size();
	int char_len;
	int toSub = 0;
	int spaces = 0;
	int toAdd = 0;
	int doubledMem;
	for (auto it = str_m.cbegin(); it != str_m.cend(); ++it) {
		if (*it == '\\') {
			if (*(it + 1) == 'x') { 
				toSub += 3; 
				++toAdd;
			}
			else if (*(it + 1) == '\\') {
				++it;
				++toSub;
				toAdd += 2;
			}
			else {
				++toSub;
				++toAdd;
			}
			
		}
		else if (*it == '\"')
			toAdd++;

		else if (*it == '\n') {
			++spaces;
		}

	}

	// pamiec - faktyczna ilosc zwyklych znakow

	std::cout << memory_len << std::endl;
	memory_len -= spaces;
	doubledMem = memory_len + toAdd + 2 * (spaces + 1);
	//memory_len = memory_len - spaces;
	char_len = memory_len - (2 * (spaces+1)   + toSub);
	std::cout << memory_len << " - " << char_len << " = " << memory_len - char_len << std::endl;
	std::cout <<doubledMem << " - " << memory_len << " = " << doubledMem - memory_len << std::endl;
	




	system("pause");

	/*
	std::ifstream is("file.txt");
	is.seekg(0, std::ios::end);
	int len = is.tellg();
	is.seekg(0, std::ios::beg);
	char* buffer = new char[len];
	is.read(buffer, len);
	is.close();
	std::cout.write(buffer, len);

	std::cout << std::endl;
	system("pause");
	*/



	
}