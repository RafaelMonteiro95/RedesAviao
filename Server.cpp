#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vars.h"

class Server {
private:
    // ID do socket
    int socket_fd = 0; // Socket para conexão
	int socket_id = 0; // Socket para nova conexão com um determinado cliente

    // Struct que armazena o ip, porta e protocolo IP que está sendo utilizado
    struct sockaddr_in address;

public:
    Server() {
        int opt = 1;
        // Criação do Socket
        if ((socket_fd = socket(IPv4, TPC, IP_PROTOCOL)) == 0){
            perror("\n Socket creation error \n");
            exit(EXIT_FAILURE);
        }

        // Forcefully attaching socket to the port 8080
        // Seta alguma configuração sobre protocolo que não entendi ao cerot o que.
        if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        
        address.sin_addr.s_addr = INADDR_ANY; //Alguma coisa sobre não limitar apenas ao localhost
        address.sin_family = IPv4;
        address.sin_port = htons(PORT);
          
        // Atribui o endereço de socket local para o socket indetificado pelo descritor.
        if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
            perror("bind failed");
            exit(EXIT_FAILURE);
        }

        // Deixa o socket em modo de conexão. (o q é backlog -> '3' ?)
        if (listen(socket_fd, 3) < 0){
            perror("listen");
            exit(EXIT_FAILURE);
        }

	}
    void start(){
        int addrlen = sizeof(address);
        // Aguardando conexão do cliente, cria um novo socket com a conexão direta ao cliente
        // OBS: sockaddr é como se fosse uma generalização de sockaddr_in (especifica para comunicação IP)
        if ((socket_id = accept(socket_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0){
            perror("accept");
            exit(EXIT_FAILURE);
        }
    }
	// Envia Mensagem
    int send_data(void* data, size_t data_length){
        return send(socket_id, data, data_length, 0);
    }

    // Recebe Mensagem
    int read_data(void* data, size_t data_length){
        return read(socket_id, data, data_length);
    }

};


int main(int argc, char const *argv[]){
    Server s;
    char* buffer = (char*) malloc (BUFFER_SIZE*sizeof(char));
    char* server_connection = "server id";
    
    s.start();
    // Recebendo mensagem de boas vidas do client
    s.read_data(buffer, BUFFER_SIZE);
    // Enviando mensagem de boas vindas ao cliente
    s.send_data(server_connection, strlen(server_connection));
    printf("Server: %s\n", buffer);

    // Iniciando troca de mensagens
    while(strcmp(buffer, "exit") != 0){
        memset(buffer, 0, sizeof(buffer));
        // Recebendo mensagem
        s.read_data(buffer, BUFFER_SIZE);
        printf("%s\n", buffer);

        // Enviando mensagem
        printf("\t\t");
        scanf("%[^\n]%*c", buffer);
        s.send_data(buffer, strlen(buffer));

    }

    free(buffer);
    return 0;

}