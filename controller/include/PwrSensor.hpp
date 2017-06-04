#pragma once

#include <string>

using namespace std; //string

class PwrSensor {
private:

public:
    PwrSensor();
    ~PwrSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(string msg);
};
