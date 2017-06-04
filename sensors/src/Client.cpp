// C includes
#include <stdio.h>
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
	if (sock == -1){
		printf("ERRO scoket() returned '-1'\n");
		throw -1;
	}

	// Preparando a estrutura que guarda meu endereço
	memset((char *) &other, 0, sizeof(other));
	other.sin_family = AF_INET;
	other.sin_port = htons(port);

	if(inet_aton(srv, &other.sin_addr) == 0){
		printf("ERRO inet_aton() returned '0'\n");
		throw -2;
	}
}

Client::~Client(void) {
	
}

// Envia Mensagem
void Client::send_data(string& msg){
	const char* temp = msg.c_str();
	if(sendto(sock, temp, msg.size(), 0, (struct sockaddr*)&other, sizeof(other)) == -1){
		printf("ERRO sendto() returned '-1'\n");
		throw -3;
	}
}
