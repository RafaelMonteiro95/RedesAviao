// C
#include <netinet/in.h>

// C++
#include <string>
#include <iostream>

// System
#include "PwrSensor.hpp"

using namespace std; //strings

PwrSensor::PwrSensor() {
	for(int i = 0; i < this->max_sensors; i++){
		data.push_back(this->initial);
	}
}

PwrSensor::~PwrSensor() {

}

// Envia Mensagem
string PwrSensor::getData(){
	string ans;
	int sum, i;

	for(i = 0, sum = 0; i < this->max_sensors; i++){
		sum += data[i];
	}

	ans = to_string(sum);
 	ans += " kW/h";
 	
    return ans;
}

    // Recebe Mensagem
void PwrSensor::updateData(int id, string msg){
	data[id] = stoi(msg);
}