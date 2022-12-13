#pragma once
#include <random>


class Random
{
private:


public:
	Random(std::mt19937 gen);
	std::string selectRandom(const std::vector<std::string>& values);
};