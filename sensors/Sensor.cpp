#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Client.cpp"

#define SERVER "127.0.0.1"
#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to send data
 
int main(int argc, char const *argv[]){
	printf("%d Argumentos:\n", );
	for (int i = 0; i < argc; i++)
	{
		printf("\targv[%d]: %s\n", i, argv[i]);
	}

	char* buffer = (char*) malloc (BUFFER_SIZE * sizeof(char));
	Client* c = new Client(SERVER, PORT);

	// Iniciando troca de mensagens
	while(c != NULL and strcmp(buffer, "exit") != 0){
		sleep(1f);
		scanf("%[^\n]%*c", buffer);
		
		c->send_data(buffer, strlen(buffer));
	}

	delete(c);
	free(buffer);
	return 0;
}