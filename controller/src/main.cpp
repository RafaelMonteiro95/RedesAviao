#include <iostream>
#include <string>
#include "Server.hpp"
#include "LockSensor.hpp"
#include "PplSensor.hpp"
#include "PwrSensor.hpp"
#include "TempSensor.hpp"

int parseMsgId(string msg){
    //copies the 1st 2 bytes of msg to ID
    char id[3] = {0};
    msg.copy(id,2,0);
    id[3] = '\0';
    return atoi(id);
}

int main(void){

    string msg;

    //Starting my server
    Server* s = new Server(8888);

    //Creating all my sensors
    LockSensor* lock = new LockSensor();
    PplSensor* ppl = new PplSensor();
    PwrSensor* pwr = new PwrSensor();
    TempSensor* temp = new TempSensor();

    while(true){
        //Read a message
        msg.erase();
        s->read_data(msg);
        cout << "Msg received: " << msg << endl;

        //Parse message
        switch(parseMsgId(msg) / 10){

            //ID 1x: LockSensor
            case 1:
                lock->updateData(msg.substr(3));
                break;

            //ID 2x: PplSensor
            case 2:
                ppl->updateData(msg.substr(3));
                break;

            //ID 1x: PwrSensor
            case 3:
                pwr->updateData(msg.substr(3));
                break;

            //ID 1x: TempSensor
            case 4:
                temp->updateData(msg.substr(3));
                break;

            default:
                break;
        }

        // updates results
        cout << "Locks Sensor:" << lock->getData() << endl;
        cout << "People Sensor:" << ppl->getData() << endl;
        cout << "Power Sensor:" << pwr->getData() << endl;
        cout << "Temperature Sensor:" << temp->getData() << endl;
    }


    delete s;
    return 0;
}