#ifndef _PPLSENSOR_HPP_
#define _PPLSENSOR_HPP_

#include <string>
#include <vector>


using namespace std; //string

class PplSensor {
private:
	vector<bool> data;
	const bool initial = false;
	const int max_sensors = 4;

public:
    PplSensor();
    ~PplSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(int id, string msg);
};

#endif