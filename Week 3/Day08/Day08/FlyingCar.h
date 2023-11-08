#pragma once
#include "Car.h"

class FlyingCar : public Car
{
private:
	int maxAltitude_;
public:
	FlyingCar(int maxAltitude, int year, std::string make, std::string model) :
		Car(year,make,model),  //call the base class ctor
		maxAltitude_(maxAltitude)
	{

	}
};
