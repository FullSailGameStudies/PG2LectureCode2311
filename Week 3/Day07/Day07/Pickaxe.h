#pragma once

#include "enums.h"

class Pickaxe
{
public:

protected:

private:
	float durability_;
	Material material_;


public:
	void MineSomething(int x, int y, int z);
	void DoSomething(int value)
	{
		bool bob;

		switch (material_)
		{
		case Wood:
			break;
		case Stone:
			break;
		case Iron:
			break;
		case Gold:
			break;
		case Diamond:
			break;
		case Netherite:
			break;
		default:
			break;
		}

	}
};

