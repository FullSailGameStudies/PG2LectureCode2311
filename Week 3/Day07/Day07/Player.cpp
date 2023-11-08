#include "Player.h"

void Player::PickupItem(std::string item)
{
	if(inventory_.size() < 36)
		inventory_.push_back(item);
}

Player::Player(std::string gamerTag, float health, float experience, float armorLevel) :
	gamerTag_(gamerTag),
	health_(health),
	experience_(experience),
	armorLevel_(armorLevel)
{
	gamerTag_ = gamerTag;
}
