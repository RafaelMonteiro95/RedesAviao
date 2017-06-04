// C includes
#include <netinet/in.h> // Coisas de socket

// C++ includes
#include <string> // strings

//header include
#include "PplSensor.hpp"

using namespace std; //strings

PplSensor::PplSensor() {
}

PplSensor::~PplSensor() {
}

    // Envia Mensagem
string PplSensor::getData(){
    return "test";
}

    // Recebe Mensagem
void PplSensor::updateData(string msg){
}