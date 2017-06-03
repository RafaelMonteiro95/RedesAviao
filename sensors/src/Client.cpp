// C includes
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h> // Coisas de socket
#include <string.h> // memset()

// C++ includes
#include <string> // strings
#include <iostream>

//header include
#include "Client.hpp"

using namespace std; //strings

Client::Client(string server, int port) {

    const char* srv = server.c_str();
    // Criação do Socket
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // Preparando a estrutura que guarda meu endereço
    memset((char *) &other, 0, sizeof(other));
    other.sin_family = AF_INET;
    other.sin_port = htons(port);
    inet_aton(srv, &other.sin_addr);
}

Client::~Client(void) {
}

    // Envia Mensagem
void Client::send_data(string& msg){
    const char* temp = msg.c_str();
    sendto(sock, temp, msg.size(), 0, (struct sockaddr*)&other, sizeof(other));
}
