// C includes
#include <netinet/in.h> // Coisas de socket
#include <string.h> // memset()

// C++ includes
#include <string> // strings
#include <iostream>

//header include
#include "PwrSensor.hpp"

using namespace std; //strings

PwrSensor::PwrSensor() {
}

PwrSensor::~PwrSensor() {
}

    // Envia Mensagem
string PwrSensor::getData(){
    return "test";
}

    // Recebe Mensagem
void PwrSensor::updateData(string msg){
	cout << "updating" << msg << endl;
}