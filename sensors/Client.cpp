#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



class Client {
private:
	// ID do socket (funciona como file descriptor (?))
	int _socket_id = 0;
	// Struct que armazena o ip, porta e protocolo IP que está sendo utilizado
	struct sockaddr_in _address;

public:
	Client(const char* Server, int Port){
		// Conectando..
		if (_socket_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP) == -1){
			perror("\nSocket creation error \n");
			throw -1;
		}

		memset((char *) &_address, 0, sizeof(_address));
		_address.sin_family = AF_INET;
		_address.sin_port = htons(Port);
		 
		if (inet_aton(Server , &_address.sin_addr) == 0) {
			perror("inet_aton() failed\n");
			throw -2;
		}
	}

	// Envia Mensagem
	int send_data(void* data, size_t data_length){
		sendto(_address, data, data_length, 0 , (struct sockaddr *) &_address, sizeof(_address));	
	}
};