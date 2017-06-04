// C includes
#include <netinet/in.h> // Coisas de socket

// C++ includes
#include <string> // strings

//header include
#include "LockSensor.hpp"

using namespace std; //strings

LockSensor::LockSensor() {
}

LockSensor::~LockSensor() {
}

    // Envia Mensagem
string LockSensor::getData(){
    return "test";
}

    // Recebe Mensagem
void LockSensor::updateData(string msg){
}