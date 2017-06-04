#pragma once

#include <netinet/in.h> // Coisas de socket
#include <string> // strings

#define BUFLEN 512

using namespace std; //string

class Server {
private:
    int sock; // Socket para conexão
    struct sockaddr_in me; // Essa struct salva informações sobre o meu endereço
    struct sockaddr_storage other; // Essa struct salva informações sobre o endereço de quem mandou a ultima mensagem
    socklen_t otherLen; // Salva o tamanho de "other"
    char buf[BUFLEN]; // Buffer que salva as msgs recebidas

public:
    Server(int port);
    ~Server(void);

	// Envia Mensagem
    void send_data(string& msg);

    // Recebe Mensagem
    void read_data(string& msg);
};