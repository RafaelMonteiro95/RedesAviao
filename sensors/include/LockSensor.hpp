#pragma once

using namespace std;

#include "Client.hpp"

class LockSensor {
private:
	Client *c;
	int id;
	bool l;

public:
	LockSensor();
    LockSensor(int, string, int);
    ~LockSensor();

    void start();
};
