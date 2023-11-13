#pragma once
#include <string>
#include <fstream>
class Hero
{
public:
	Hero(std::string name, std::string secret, int age);

	std::string GetName() const { return name_; }
	void SetName(std::string name) { name_ = name; }

	std::string GetSecret() const { return secret_; }
	void SetSecret(std::string secret) { secret_ = secret; }
	
	int GetAge() const { return age_; }
	void SetAge(int age) { age_ = age; }

	void Serialize(std::ostream& outputFile, char delimiter);

private:
	std::string name_, secret_;
	int age_;
};

