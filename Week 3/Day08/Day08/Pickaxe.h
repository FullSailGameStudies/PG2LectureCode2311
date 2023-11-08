#pragma once

#include "enums.h"

class Pickaxe
{
public:
	//ctors
	//Pickaxe(); //default ctor
	Pickaxe(Material material);
	Pickaxe(Material material, float durability);

	//getters
	Material GetMaterial() const
	{
		return material_;
	}
	float Durability() const { return durability_; }

	//setters
	void SetMaterial(Material newMaterial)
	{
		if (material_ == Material::Diamond && newMaterial == Material::Netherite)
		{
			material_ = newMaterial;
		}
	}
	void Durability(float newDurability)
	{
		if (newDurability > 0 && newDurability <= 100) //protect the data!
			durability_ = newDurability;
	}


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

