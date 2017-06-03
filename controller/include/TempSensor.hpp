#ifndef _TEMPSENSOR_HPP_
#define _TEMPSENSOR_HPP_

#include <string>

using namespace std; //string

class TempSensor {
private:

public:
    TempSensor();
    ~TempSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(string msg);
};

#endif