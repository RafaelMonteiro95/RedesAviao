// C includes
#include <netinet/in.h> // Coisas de socket
#include <iterator> // std::istream_iterator
// C++ includes
#include <string> // strings

//header include
#include "PplSensor.hpp"

using namespace std; //strings

PplSensor::PplSensor() {
	for(int i = 0; i < this->max_sensors; i++){
		data.push_back(this->initial);
	}
}

PplSensor::~PplSensor() {
}

    // Envia Mensagem
string PplSensor::getData(){
	int num_of_ppl = 0;

	for(int i = 0; i < this->max_sensors; i++) {

		if(data[i].first <= this->x_max and data[i].second <= this->y_max
		and data[i].first >= this->x_min and data[i].second >= this->y_min) {
			num_of_ppl++;
		}
	}

	string result = to_string(num_of_ppl);
	result += " moradores na casa.";
    return result;
}

    // Recebe Mensagem
void PplSensor::updateData(int id, string msg){
	// forma melhor de fazer split ?
	string::size_type sz;

  	double x = stod (msg,&sz);
  	double y = stod (msg.substr(sz));

	data[id] = make_pair(x, y);
}