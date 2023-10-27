#include "ThemeSongs.h"
#include <iostream>

void ThemeSongs::BatTheme(int numberOfNas)
{
	for (size_t i = 0; i < numberOfNas; i++)
	{
		std::cout << "na ";
	}
	std::cout << "Batman!\n";
}
