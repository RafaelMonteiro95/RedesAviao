#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include <string>
#include <sstream>

#include "Client.hpp"
#include "LockSensor.hpp"

LockSensor::LockSensor() {
	this->c = NULL;
	this->id = 0;
	this->l = false;
}

LockSensor::LockSensor(int id, string server, int port) {
	srand(time(NULL));

	this->c = new Client(server, port);
	this->id = id;
	this->l = false;
}

LockSensor::~LockSensor() {
	delete this->c;
}

void LockSensor::start() {
	stringstream s;
	string str;

	while (true) {
		// Generating random values
		if (rand() % 100 < 20){
			this->l = !this->l;
		}

		// Filling stream
		s.str("");
		s << id << " " << this->l;
		str = s.str();

		// Sending data
		this->c->send_data(str);

		sleep(3);
	}
}