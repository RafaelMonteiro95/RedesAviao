#include <iostream>
#include <string>
#include "Server.hpp"

int main(void){

    string msg;
    Server* s = new Server(8888);

    while(true){
        msg.erase();
        s->read_data(msg);
        cout << msg << endl;
    }

    delete s;
    return 0;
}