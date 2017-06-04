// C
#include <netinet/in.h>

// C++
#include <string>

// System
#include "TempSensor.hpp"

using namespace std;

TempSensor::TempSensor() {
	int i;

	for (i = 0; i < this->max_sensors; i++) {
		data.push_back(this->initial);
	}
}

TempSensor::~TempSensor() {

}

// Envia Mensagem
string TempSensor::getData(){
	string ans = "Temp. média: ";
	double sum = 0.0;
	int i;
	
	for (i = 0; i < this->max_sensors; i++) {
		sum += data[i];
	}

	ans += to_string(sum / (double)this->max_sensors);
 	ans += " ºC";

    return ans;
}

// Recebe Mensagem
void TempSensor::updateData(int id, string msg){
	data[id] = stof(msg);
}