#include "Pistol.h"

Pistol::Pistol(int rounds, int magCap, int range, int damage) :
	Weapon(range, damage),
	rounds_(rounds),
	magCapacity_(magCap)
{
}
