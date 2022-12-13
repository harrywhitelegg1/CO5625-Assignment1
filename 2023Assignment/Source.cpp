#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <random>

#include "Mountains.h"

std::random_device rd; // create a random seed value
unsigned int seed = rd(); // generate the seed value





std::string transformToLowerCase(std::string inputValue)
{

	std::string lowerCaseInputRange;
	std::transform(inputValue.begin(), inputValue.end(), inputValue.begin(), [](unsigned char c) { return std::tolower(c); });
	lowerCaseInputRange = inputValue;
	return lowerCaseInputRange;
}





int main()
	{

	std::mt19937 gen(seed);


	std::vector<std::string> fileNames = { "alps.txt", "carpathians.txt", "icelandic highlands.txt", "pyrenees.txt" }; //here we initialize the file names
	Mountains mountains(fileNames); //here we create an instance of the class Mountains and provide the constructor the files names.
	std::cout << "--------------------------\n-GUESS THE MOUNTAIN RANGE-\n--------------------------" << std::endl;
	std::cout << "\nBelow is a random mountain, you will have to guess which mountain range it belongs to...\n" << std::endl;
	std::string inputRange;

	int score = 0;
	do
	{
		std::string randomMountain =  mountains.getRandomMountain();
		std::cout << randomMountain << std::endl;
		std::cout << "Please enter a mountain range:" << std::endl;
		getline(std::cin, inputRange);
		inputRange = transformToLowerCase(inputRange);
		bool check = mountains.checkRange(randomMountain, inputRange);
		if (check)
		{
			std::cout << "Correct!" << "\n" << std::endl;
			score++;
		}
		else if (inputRange == "exit")
		{
			std::cout << "Score: " << score << std::endl;
			break;
		}
		else 
		{
			std::cout << "Incorrect!" << "\n" << std::endl;
		}


	} while (inputRange != "exit");

	
}
