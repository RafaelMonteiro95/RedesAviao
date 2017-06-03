// C includes
#include <netinet/in.h> // Coisas de socket
#include <string.h> // memset()

// C++ includes
#include <string> // strings

//header include
#include "PplSensor.hpp"

using namespace std; //strings

PplSensor::PplSensor() {
	for(int i = 0; i < this->max_sensors; i++){
		data.push_back(this->initial);
	}
}

PplSensor::~PplSensor() {
}

    // Envia Mensagem
string PplSensor::getData(){
	int num_of_ppl = 0;
	for(int i = 0; i < this->max_sensors; i++){
		if(data[i] == true){
			num_of_ppl++;
		}
	}
	string result = to_string(num_of_ppl);
	result += " moradores na casa.";
    return result;
}

    // Recebe Mensagem
void PplSensor::updateData(int id, string msg){
	data[id] = msg.compare("0") == 0 ? false : true;
}