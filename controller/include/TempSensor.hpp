#ifndef _TEMPSENSOR_HPP_
#define _TEMPSENSOR_HPP_


#include <string>
#include <vector>

using namespace std; //string

class TempSensor {
private:
	const float initial = 26.0;
	const int max_sensors = 5;
	vector<float> data;

public:
    TempSensor();
    ~TempSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(int id, string msg);
};

#endif