#include "../include/sensor.h"
#include <cstdlib>
#include <ctime>

Sensor::Sensor()
{
	std::srand(std::time(nullptr));
}

double Sensor::read()
{
	return 20 + (std::rand() % 1000) / 10.0;
}