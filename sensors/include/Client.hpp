#pragma once

#include <netinet/in.h> // Coisas de socket
#include <string.h> // memset()

#include <string> // strings

#define BUFLEN 512

using namespace std; //string

class Client {
private:
    int sock; // Socket para conexão
    struct sockaddr_in other; // Essa struct salva informações sobre o meu endereço
    char buf[BUFLEN]; // Buffer que salva as msgs recebidas

public:
    Client(string server, int port);
    ~Client(void);

	// Envia Mensagem
    void send_data(string& msg);
};
