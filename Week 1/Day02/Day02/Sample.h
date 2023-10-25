#pragma once
#include <string>
#include <iostream>
class Sample
{

public:
	std::string name;
	void PrintMyName() const
	{
		//name = "Bruce";
		std::cout << name << "\n";
	}
};

