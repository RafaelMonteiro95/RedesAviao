// C includes
#include <netinet/in.h> // Coisas de socket
#include <string.h> // memset()
#include <arpa/inet.h>


// C++ includes
#include <string> // strings

//header include
#include "Server.hpp"

#include <iostream>

using namespace std; //strings

Server::Server(int port) {

    // Criação do Socket
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // Preparando a estrutura que guarda meu endereço
    memset((char *) &me, 0, sizeof(me));
    me.sin_family = AF_INET;
    me.sin_port = htons(port);
    me.sin_addr.s_addr = htonl(INADDR_ANY); 

    // Dou bind no socket criado
    bind(sock , (struct sockaddr*)&me, sizeof(me));
}

Server::~Server(void) {
}

    // Envia Mensagem
void Server::send_data(string& msg){
    const char* temp = msg.c_str();
    sendto(sock, temp, msg.size(), 0, (struct sockaddr*)&other, otherLen);
}

    // Recebe Mensagem
void Server::read_data(string& msg){
    // Limpa o buffer de mensagem
    memset((char *) &buf, 0, BUFLEN);
    // Lê mensagem do socket
    recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr*)&other, &otherLen);

    msg += buf;
}