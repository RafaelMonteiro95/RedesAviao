// C includes
#include <netinet/in.h> // Coisas de socket

// C++ includes
#include <string> // strings
#include <iostream>

//header include
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
	int sum = 0;
	for(int i = 0; i < this->max_sensors; i++){
		sum += data[i];
	}
	string result = to_string(sum);
 	result += " kW/h";
    return result;
}

    // Recebe Mensagem
void PwrSensor::updateData(int id, string msg){
	data[id] = stoi(msg);
}