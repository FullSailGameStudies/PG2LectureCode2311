#pragma once
#include <string>
#include <vector>

class Player
{
public:
	void PickupItem(std::string item);

	Player(std::string gamerTag, float health, float experience, float armorLevel);
private:
	std::string gamerTag_;
	float health_, experience_, armorLevel_;

	std::vector<std::string> inventory_;
};

