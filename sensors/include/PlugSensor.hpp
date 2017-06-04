#pragma once

using namespace std;

#include "Client.hpp"

class PlugSensor {
private:
	Client *c;
	int id, w;

public:
	PlugSensor();
    PlugSensor(int, string, int);
    ~PlugSensor();

    void start();
};
