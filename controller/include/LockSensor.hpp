#ifndef _LOCKSENSOR_HPP_
#define _LOCKSENSOR_HPP_


#include <string>
#include <vector>
#include <queue>

using namespace std; //string

class LockSensor {
private:
	vector<bool> data;
	const bool initial = false;
	const int max_sensors = 9;

public:
    LockSensor();
    ~LockSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(int id, string msg);
};

#endif