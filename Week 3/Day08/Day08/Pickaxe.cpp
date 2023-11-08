#include "Pickaxe.h"

Pickaxe::Pickaxe(Material material) : //starting the member initialization list
	material_(material),
	durability_(100)
{
}

Pickaxe::Pickaxe(Material material, float durability)
{
	material_ = material;
	Durability(durability);//using the setter
}

void Pickaxe::MineSomething(int x, int y, int z)
{
	//check the world x,y,z for a hit
}
