// C includes
#include <netinet/in.h> // Coisas de socket
#include <string.h> // memset()

// C++ includes
#include <string> // strings
#include <iostream>

//header include
#include "TempSensor.hpp"

using namespace std; //strings

TempSensor::TempSensor() {
}

TempSensor::~TempSensor() {
}

    // Envia Mensagem
string TempSensor::getData(){
    return "test";
}

    // Recebe Mensagem
void TempSensor::updateData(string msg){
}