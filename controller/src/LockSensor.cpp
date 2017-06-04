// C includes
#include <netinet/in.h> // Coisas de socket

// C++ includes
#include <string> // strings
#include <iostream>
#include "LockSensor.hpp"
//header include

using namespace std; //strings

LockSensor::LockSensor() {
    int i;

	for (i = 0; i < this->max_sensors; i++) {
		data.push_back(this->initial);
	}
}

LockSensor::~LockSensor() {
}

// Envia Mensagem
string LockSensor::getData(){
    string result = "Casa ";
    bool unlocked, locked;
    int i;

    unlocked = locked = false;

    for(i = 0; i < this->max_sensors; i++){
    	if (data[i]) {
    		unlocked = true;
    	}
        else{
            locked = true;
        }
    }
    
    if (locked and unlocked) {
    	result += "parcialmente trancada";
    }
    else if (locked == false and unlocked == true) {
    	result += "totalmente aberta";
    }
    else {
    	result += "trancada";
    }

    return result;
}

// Recebe Mensagem
void LockSensor::updateData(int id, string msg){
    data[id] = msg == "1";
}