#include <iostream>
#include <string>
#include "Client.hpp"

int main(void){

    string msg;
    Client* s = new Client("127.0.0.1",8888);

    while(true){
        cin >> msg;
        s->send_data(msg);
    }

    delete s;
    return 0;
}