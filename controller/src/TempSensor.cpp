// C includes
#include <netinet/in.h> // Coisas de socket

// C++ includes
#include <string> // strings

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