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

void update_data(Server* s, LockSensor* lock, PplSensor* ppl, PwrSensor* pwr, TempSensor* temp, bool *exit){
    while(!(*exit)){
        string msg;
        //Read a message
        msg.erase();
        s->read_data(msg);
        cout << "Msg received: " << msg << endl;
        int id = parseMsgId(msg);
        //Parse message
        switch(id / 10){
            //ID 1x: LockSensor
            case 1:
                lock->updateData(id % 10, msg.substr(3));
                break;

            //ID 2x: PplSensor
            case 2:
                ppl->updateData(id % 10, msg.substr(3));
                break;

            //ID 1x: PwrSensor
            case 3:
                pwr->updateData(id % 10, msg.substr(3));
                break;

            //ID 1x: TempSensor
            case 4:
                temp->updateData(id % 10, msg.substr(3));
                break;

            default:
                break;
        }
    }
}

void get_data(LockSensor* lock, PplSensor* ppl, PwrSensor* pwr, TempSensor* temp){
        // updates results
        cout << "Locks Sensor:" << lock->getData() << endl;
        cout << "People Sensor:" << ppl->getData() << endl;
        cout << "Power Sensor:" << pwr->getData() << endl;
        cout << "Temperature Sensor:" << temp->getData() << endl;
}

int main(void){


    //Starting my server
    Server* s = new Server(8882);

    //Creating all my sensors
    LockSensor* lock = new LockSensor();
    PplSensor* ppl = new PplSensor();
    PwrSensor* pwr = new PwrSensor();
    TempSensor* temp = new TempSensor();
    bool exit = false;
    thread update_data_thread (update_data, s, lock, ppl, pwr, temp, &exit);

    string in;
    while(!exit){
        cin >> in ;
        if(in.compare("update") == 0){
            get_data(lock, ppl, pwr, temp);
        }
        if(in.compare("exit") == 0){
            exit = true;
        }

    }

    // espera a thread terminar
    update_data_thread.join();
    delete s;
    return 0;
}