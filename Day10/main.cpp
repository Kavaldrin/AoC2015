#include <iostream>
#include <string>

///////////////////
// COMPILE WITH REALEASE FLAG!!
// OR WAIT
//////////////////

constexpr int ITERATIONS = 50;

int main()
{
	std::string input = "3113322113"; // my input
	std::string output;
	for (int i = 0; i < ITERATIONS; ++i) {
		output.clear();
		char lastLetter = input[0];
		int counter = 0;
		for (const auto& letter : input) {
			if (letter == lastLetter) ++counter;
			else {
				output += std::to_string(counter);
				output += lastLetter;
				counter = 1;
				lastLetter = letter;
			}
		}
		output += std::to_string(counter);
		output += lastLetter;
		input = output;
	}
	std::cout << output.length() << std::endl;
	system("pause");

}