#include "Mountains.h"
#include <fstream>
#include <random>
#include <algorithm>
#include <map>
#include <string>
#include <vector>





Mountains::Mountains(std::vector<std::string>& filenames) //allows input from main for a vector of file names
{


	for (const auto& filename : filenames) // starts a loop through the vector of file names
	{
		std::string file_name = filename; // creating a variable file name.

		std::vector<std::string> mountains; // creating a vector of mountains from the specific mountain range to be inserted into the map

		std::ifstream stream(file_name); //creating the input stream to read the selected file in the loop
		if (stream.is_open()) // ensuring that the file has been opened
		{
			std::string currentLine; //variable to store the current line
			while (getline(stream, currentLine)) // looping through the lines in the file until there are no more lines to be read (one line being one element)
			{
				mountains.push_back(currentLine); //pushing the variable currentLine on to the vector mountains
			}
			stream.close(); //closing the stream
		}
		else //if the file is unable to be read, we should inform the user that there was an error reading the file.
		{
			std::cout << "Error: file was unable to be read." << std::endl;
		}
		std::string mountainRange = file_name.substr(0, file_name.length() - 4); //we want to name the string value in the map the name of the..
		//mountain range, to do this we can use substr to remove the last 4 characters of the filename

		mountain_ranges.insert({ mountainRange, mountains }); //here we input the name of the mountain range, also the mountains that belong to that range.
	}
	
}







std::string selectRandom(const std::vector<std::string>& values) //this function passes a vector of strings and will return a random value.
{
	std::uniform_int_distribution<> randNumberDist(0, values.size() - 1); // this ensures that the random number is within the scope of the provided vector
	int index = randNumberDist(nmountain::gen);
	return values[index]; //returns a string of the random value within the vector

}







std::string Mountains::getRandomMountain()
{

	std::vector<std::string> mountainRangesNames; //stores the names of the mountain range names.

	for (const auto& key : mountain_ranges) //loops through the keys within the mountains map container
	{
		mountainRangesNames.push_back(key.first); //adds the mountain range names to the vector.
	}

	std::string randomMountianRange; //defining a random mountain range string.
	randomMountianRange = selectRandom(mountainRangesNames); //calling the random mountain function, which will return a random string from the supplied vector.
	std::vector<std::string> randomMountains = mountain_ranges[randomMountianRange]; //this creates a vector containing all of the mountains that belong to the mountain range that was randomly chosen above.
	return selectRandom(randomMountains); //this returns a string to the main, of a random mountain contained in the randomMountains vector.

}



















bool Mountains::checkRange(const std::string& mountain, const std::string& range) //this function passes two constant string pointers, the mountain that has been selected, and the mountain range the user has inputted. 
{
	for (const auto& [key, values] : mountain_ranges) //this loop, will loop through each key value pair inside of the mountain_ranges map object.
	{
		if (std::find(values.begin(), values.end(), mountain) != values.end()) //this if statement will use the find class in the standard template library to find the inputted variable mountain, with the key that it belongs to.
		{
			if (key == range) // this if statement compares the key that is in memory inside the loop and compare it to the mountain range variable that has been defined.
			{
				return true; //if the statement is true, true will be returned.
			}
		}
	}
	return false; //else false will be returned.
}

