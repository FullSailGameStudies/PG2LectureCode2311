#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
	//pistol ctor that calls a weapon ctor

private:
	int rounds_, magCapacity_;

public:
	Pistol(int rounds, int magCap, int range, int damage);
};

