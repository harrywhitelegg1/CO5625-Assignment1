#pragma once
#include<vector>
#include<string>
#include<map>
#include <iostream>
#include <random>


namespace nmountain
{
		extern std::mt19937 gen;
}

class Mountains
{
	
private:
	
	std::map<std::string, std::vector<std::string>> mountain_ranges;



public:


	//Time complexity: O(N) where N is the total amount of lines in the files, this is because the code loops through each file,
	//so if the input becomes larger, the program will take longer to execute.
	Mountains(std::vector<std::string>& filenames);

	//Time complexity: O(1) because the size of the input does not affect the amount of time to execute.
	std::string getRandomMountain();

	//Time complexity: 0(N) because the code loops through key value pairs in the map and compares it to the mountain range inputted,
	//this operation will take longer depending on the amount of key value pairs.
	bool checkRange(const std::string& mountain, const std::string& range);
};
