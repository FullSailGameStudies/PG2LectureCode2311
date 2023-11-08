#include "Pistol.h"
#include <iostream>

Pistol::Pistol(int rounds, int magCap, int range, int damage) :
	Weapon(range, damage),
	rounds_(rounds),
	magCapacity_(magCap)
{
}

void Pistol::showMe()
{
	Weapon::showMe();
	std::cout << "I'm a pistol with " << rounds_ << " rounds with a capacity to hold " << magCapacity_ << ".\n";
}
