#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include <string>
#include <sstream>

#include "Client.hpp"
#include "TempSensor.hpp"

#include <iostream>

using namespace std;

TempSensor::TempSensor() {
	this->c = NULL;
	this->id = 0;
	this->t = 25;
}

TempSensor::TempSensor(int id, string server, int port) {
	srand(time(NULL));

	this->c = new Client(server, port);
	this->id = id;
	this->t = 25;
}

TempSensor::~TempSensor() {
	delete this->c;
}

void TempSensor::start() {
	stringstream s;
	string str;

	while (true) {
		// Generating random values
		this->t += rand() % 7 - 3;
		this->t = min(this->t, 40);
		this->t = max(this->t, 5);

		// Filling stream
		s.str("");
		s << id << " " << this->t;
		str = s.str();

		// Sending data
		this->c->send_data(str);
		cout << str << endl;

		sleep(3);
	}
}