#pragma once

using namespace std;

#include "Client.hpp"

class LocationSensor {
private:
	Client *c;
	double x, y;
	int id;

public:
	LocationSensor();
    LocationSensor(int, string, int);
    ~LocationSensor();

    void start();
};
