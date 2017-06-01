#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vars.h" 

class Client {
private:
    // ID do socket (funciona como file descriptor (?))
    int socket_id = 0;
    // Struct que armazena o ip, porta e protocolo IP que está sendo utilizado
    struct sockaddr_in address;

public:
    Client(){
        memset(&address, '0', sizeof(address));

        // Definindo porta e protocolo IPv4 
        address.sin_family = IPv4;
        address.sin_port = htons(PORT);

        // Criação do socket
        if ((socket_id = socket(IPv4, TPC, IP_PROTOCOL)) < 0){
            perror("\n Socket creation error \n");
        }
    
        // Convert IPv4 and IPv6 addresses from text to binary form
        // ""127.0.0.1"" -> int(127001)
        if(inet_pton(IPv4, SERVER_IP, &address.sin_addr) <= 0){
            perror("\nInvalid address/ Address not supported \n");
        }
    }
    
    // Connecta ao servidor
    void connect_to_server(){
        if (connect(socket_id, (struct sockaddr *)&address, sizeof(address)) < 0){
            perror("\nConnection Failed \n");
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
    Client c;
    char* client_connection = "client id";
    char* buffer = (char*) malloc (BUFFER_SIZE*sizeof(char));
   
    c.connect_to_server();
    // Enviando mensagem de boas viadas ao servidor
    c.send_data(client_connection, strlen(client_connection));
    // Recebendo mensagem de boas vindas do servidor
    c.read_data(buffer, BUFFER_SIZE);
    printf("Client: %s\n", buffer);

    // Iniciando troca de mensagens
    while(strcmp(buffer, "exit") != 0){

        // Enviando mensagem
        printf("\t\t");
        scanf("%[^\n]%*c", buffer);
        c.send_data(buffer, strlen(buffer));
        
        memset(buffer, 0, sizeof(buffer));
        // Recebendo mensagem
        c.read_data(buffer, BUFFER_SIZE);
        printf("%s\n", buffer);
    }

    free(buffer);
    return 0;
}