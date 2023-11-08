#include <iostream>
#include "Weapon.h"

Weapon::Weapon(int range, int damage) : mRange(range), mDamage(damage)
{
}

void Weapon::showMe()
{
	std::cout << "\n\nRange: " << mRange << " Damage: " << mDamage << "\n";
}

int Weapon::calcDamage()
{
	return rand() % (mDamage+1);
}

int Weapon::calcDamage(int modifier)
{
	return rand() % (mDamage + modifier + 1);
}
