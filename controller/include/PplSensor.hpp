#pragma once

#include <string>
#include <vector>


using namespace std; //string

class PplSensor {
private:
	vector<pair<double, double>> data;
	const pair<double, double> initial = make_pair(0,0);
	const int max_sensors = 4;
	
	const double x_max = 30.0;
	const double y_max = 30.0;
	const double x_min = 0.0;
	const double y_min = 0.0;

public:
    PplSensor();
    ~PplSensor();

	// Envia Mensagem
    string getData();

    // Recebe Mensagem
    void updateData(int id, string msg);
};
