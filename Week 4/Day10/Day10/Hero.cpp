#include "Hero.h"
#include <sstream>

Hero::Hero(std::string name, std::string secret, int age) :
	name_(name), secret_(secret), age_(age)
{
}

Hero::Hero(std::string data, char delim)
{
    Deserialize(data, delim);
}

void Hero::Serialize(std::ostream& outputFile, char delimiter)
{
	outputFile << name_ << delimiter << secret_ << delimiter << age_;
}

void Hero::Deserialize(std::string data, char delimiter)
{
    std::stringstream heroStream(data);
    std::string ageString;
    std::getline(heroStream, name_, delimiter);
    std::getline(heroStream, secret_, delimiter);
    std::getline(heroStream, ageString, delimiter);
    age_ = std::stoi(ageString);
}
