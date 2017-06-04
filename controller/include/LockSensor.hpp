#pragma once

#include <string>

using namespace std; //string

class LockSensor {
private:

public:
    LockSensor();
    ~LockSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(string msg);
};
