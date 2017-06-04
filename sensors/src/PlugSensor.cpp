#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include <string>
#include <sstream>

#include "Client.hpp"
#include "PlugSensor.hpp"

#include <iostream>

using namespace std;

PlugSensor::PlugSensor() {
	this->c = NULL;
	this->id = 0;
	this->w = 0;
}

PlugSensor::PlugSensor(int id, string server, int port) {
	srand(time(NULL));

	this->c = new Client(server, port);
	this->id = id;
	this->w = 0;
}

PlugSensor::~PlugSensor() {
	delete this->c;
}

void PlugSensor::start() {
	stringstream s;
	int i, var, n;
	string str;

	while (true) {
		// Generating random values
		n = rand() % 31 + 20;

		if (rand() % 3 != 0){
			this->w = rand() % 151 + 50;
		}
		else{
			this->w = -500;
		}

		for (i = 0; i < n; i++){
			var = 2 * (rand() % 11 + 10) + 1;

			// Filling stream
			s.str("");
			s << id << " " << max(0, this->w + rand() % var - (var - 1) / 2);
			str = s.str();

			// Sending data
			this->c->send_data(str);

			cout << str << endl;

			sleep(1);
		}
	}
}