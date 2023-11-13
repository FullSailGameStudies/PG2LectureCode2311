#include "Hero.h"

Hero::Hero(std::string name, std::string secret, int age) :
	name_(name), secret_(secret), age_(age)
{
}

void Hero::Serialize(std::ostream& outputFile, char delimiter)
{
	outputFile << name_ << delimiter << secret_ << delimiter << age_;
}
