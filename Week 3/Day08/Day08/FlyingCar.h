#pragma once
#include "Car.h"
#include <iostream>

class FlyingCar : public Car
{
private:
	int maxAltitude_;
public:
	FlyingCar(int maxAltitude, int year, std::string make, std::string model) :
		Car(year,make,model),  //call the base class ctor
		maxAltitude_(maxAltitude)
	{
		//mMake = make;
		//mModel = model;//DON'T DO what the base ctor does
		std::cout << mMake << mModel << mModelYear;
	}
};

