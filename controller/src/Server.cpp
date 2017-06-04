// C includes
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <cstring>

// C++ includes
#include <string>

//header include
#include "Server.hpp"

using namespace std;

Server::Server(int port) {
    // Criação do Socket
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // Preparando a estrutura que guarda meu endereço
    memset((char *)&me, 0, sizeof(me));
    me.sin_family = AF_INET;
    me.sin_port = htons(port);
    me.sin_addr.s_addr = htonl(INADDR_ANY); 

    // Dou bind no socket criado
    bind(sock , (struct sockaddr*)&me, sizeof(me));
}

Server::~Server() {

}

// Envia Mensagem
void Server::send_data(string &msg) {
    const char *temp = msg.c_str();
    
    sendto(sock, temp, msg.size(), 0, (struct sockaddr*)&other, otherLen);
}

// Recebe Mensagem
void Server::read_data(string &msg) {
    // Limpa o buffer de mensagem
    memset((char *) &buf, 0, BUFLEN);
    // Lê mensagem do socket
    recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr*)&other, &otherLen);

    msg += buf;
}