#ifndef _PPLSENSOR_HPP_
#define _PPLSENSOR_HPP_

#include <string>

using namespace std; //string

class PplSensor {
private:

public:
    PplSensor();
    ~PplSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(string msg);
};

#endif