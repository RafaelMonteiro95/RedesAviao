// C includes
#include <netinet/in.h> // Coisas de socket

// C++ includes
#include <string> // strings

//header include
#include "TempSensor.hpp"

using namespace std; //strings

TempSensor::TempSensor() {
	for(int i = 0; i < this->max_sensors; i++){
		data.push_back(this->initial);
	}
}

TempSensor::~TempSensor() {
}

    // Envia Mensagem
string TempSensor::getData(){
	double sum = 0;
	string result = "Temp. média: ";
	
	for(int i = 0; i < this->max_sensors; i++){
		sum += data[i];
	}
	result += to_string(sum/(double)this->max_sensors);
 	result += " ºC";
    return result;
}

    // Recebe Mensagem
void TempSensor::updateData(int id, string msg){
	data[id] = stof(msg);
}