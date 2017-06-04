#pragma once

#include <string>

using namespace std;

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