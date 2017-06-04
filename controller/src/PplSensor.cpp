// C
#include <netinet/in.h>

// C++
#include <string>
#include <sstream>

// System
#include "PplSensor.hpp"

using namespace std;

PplSensor::PplSensor() {
	int i;

	for (i = 0; i < this->max_sensors; i++) {
		data.push_back(this->initial);
	}
}

PplSensor::~PplSensor() {

}

// Envia Mensagem
string PplSensor::getData(){
	int num_of_ppl, i;
	string ans;

	for(i = 0, num_of_ppl = 0; i < this->max_sensors; i++) {

		if(data[i].first <= this->x_max and data[i].second <= this->y_max
		and data[i].first >= this->x_min and data[i].second >= this->y_min) {
			num_of_ppl++;
		}
	}

	ans = to_string(num_of_ppl);
	ans += " moradores na casa.";

    return ans;
}

    // Recebe Mensagem
void PplSensor::updateData(int id, string msg){
	stringstream ss;
	double x, y;

	ss.str(msg);

	ss >> x >> y;

	data[id] = make_pair(x, y);
}