#pragma once

using namespace std;

#include "Client.hpp"

class TempSensor {
private:
	Client *c;
	int id, t;

public:
	TempSensor();
    TempSensor(int, string, int);
    ~TempSensor();

    void start();
};
