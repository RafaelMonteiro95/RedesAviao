#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include <string>
#include <sstream>

#include "Client.hpp"
#include "LocationSensor.hpp"

LocationSensor::LocationSensor() {
	this->c = NULL;
	this->id = 0;
	this->x = this->y = 0.0;
}

LocationSensor::LocationSensor(int id, string server, int port) {
	srand(time(NULL));

	this->c = new Client(server, port);
	this->id = id;
	this->x = this->y = 0.0;
}

LocationSensor::~LocationSensor() {
	delete this->c;
}

double rand_pos(double posmin, double posmax){
	double r = (double)rand() / (double)RAND_MAX;
	
	return r * (posmax - posmin) + posmin;
}

bool inside(double x, double y){
	return x >= 0.0 and x <= 30.0 and y >= 0.0 and y <= 30.0;
}

void LocationSensor::start() {
	double xmin, xmax, ymin, ymax, tgtx, tgty, vx, vy;
	stringstream s;
	string str;
	int t = 0;

	xmin = ymin = 0.0;
	xmax = ymax = 30.0;

	while (true) {
		if (!t){
			if (rand() % 100 < 20){
				// Fora de casa
				do{
					tgtx = rand_pos(-500.0, 500.0);
					tgty = rand_pos(-500.0, 500.0);
				}while (inside(tgtx, tgty));
			}
			else if (rand() % 100 < 80){
				// Dentro de casa
				tgtx = rand_pos(0.0, 30.0);
				tgty = rand_pos(0.0, 30.0);
			}
			else{
				// Parado
				tgtx = this->x;
				tgty = this->y;
			}

			t = rand() % 51 + 50;

			vx = (tgtx - this->x) / (double)t;
			vy = (tgty - this->y) / (double)t;
		}
		else{
			t--;
		}

		// Speed
		this->x += vx;
		this->y += vy;

		// Filling stream
		s.str("");
		s << id << " " << this->x << " " << this->y;
		str = s.str();

		// Sending data
		this->c->send_data(str);

		sleep(1);
	}
}