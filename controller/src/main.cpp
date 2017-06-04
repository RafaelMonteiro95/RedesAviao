#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>

#include "Server.hpp"
#include "LockSensor.hpp"
#include "PplSensor.hpp"
#include "PwrSensor.hpp"
#include "TempSensor.hpp"

using namespace std;

int parseMsgId(string msg){
    return atoi(msg.substr(0, 2).c_str());
}

void get_data(LockSensor* lock, PplSensor* ppl, PwrSensor* pwr, TempSensor* temp){
    // Prints updates
    cout << "Locks Sensor:" << lock->getData() << endl;
    cout << "People Sensor:" << ppl->getData() << endl;
    cout << "Power Sensor:" << pwr->getData() << endl;
    cout << "Temperature Sensor:" << temp->getData() << endl;
}

void update_data(Server* s, LockSensor* lock, PplSensor* ppl, PwrSensor* pwr, TempSensor* temp, int *status){
    string msg;
    int id;

    while ((*status) >= 0){
        if ((*status) == 1){
            get_data(lock,ppl,pwr,temp);
            (*status) = 0;
        }

        // Read a message
        msg = "";
        s->read_data(msg);
        id = parseMsgId(msg);

        // Parse message
        switch(id / 10){
            // ID 1x: LockSensor
            case 1:
                lock->updateData(id % 10, msg.substr(3));
                break;

            // ID 2x: PplSensor
            case 2:
                ppl->updateData(id % 10, msg.substr(3));
                break;

            // ID 3x: PwrSensor
            case 3:
                pwr->updateData(id % 10, msg.substr(3));
                break;

            // ID 4x: TempSensor
            case 4:
                temp->updateData(id % 10, msg.substr(3));
                break;

            default:
                break;
        }
    }
}

int main(int argc, char *argv[]){
    // Starting my server
    Server* s = new Server(8888);

    // Creating all sensors
    LockSensor* lock = new LockSensor();
    PplSensor* ppl = new PplSensor();
    PwrSensor* pwr = new PwrSensor();
    TempSensor* temp = new TempSensor();

    // Creating and lauching my thread
    int status = 0;
    thread update_data_thread(update_data, s, lock, ppl, pwr, temp, &status);

    string in;
    while (status >= 0){
        cin >> in ;
        if (in == "update"){
            status = 1;
        }
        if (in == "exit"){
            status = -1;
        }
    }

    // Espera a thread terminar
    update_data_thread.join();
    delete s;

    return 0;
}