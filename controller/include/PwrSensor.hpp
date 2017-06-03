#ifndef _PWRSENSOR_HPP_
#define _PWRSENSOR_HPP_

#include <string>
#include <vector>


using namespace std; //string

class PwrSensor {
private:
	const int initial = 0;
	const int max_sensors = 9;
	vector<int> data;
public:
    PwrSensor();
    ~PwrSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(int id, string msg);
};

#endif