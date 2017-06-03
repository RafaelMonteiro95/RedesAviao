#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Client.hpp"

void exit_error(string error_str, int Exception){
	error_str += Exception;
	printf("%s\n", error_str.c_str());
	exit(Exception);
}


/* Arguemntos:
		1. Server
		2. Port
		3. Sensor ID
		4. Tipo de atributo
		5. Others parameters

*/
int main(int argc, char const *argv[]){
	if(argc < 4){
		exit_error("ERRO, falta algum Arguemntos\nArguemntos necessarios:\n\t1. Server\n\t2. Port\n\t3. Sensor ID\n\t4. Tipo de atributo\n", 0);
	}
 	
	// Criando conexão com o servidor e a porta passados por parametros da std arg
	//		Nota: ela ira mandar a mensagem para a porta do servidor especificado
	//		idependente se existe algum servidor ouvindo a essa porta
	Client* s;
	try{
		s = new Client(argv[1], atoi(argv[2]));
	}catch(int e){
		exit_error("ERRO ao se conectar Exception: ", e);
	}

	srand(time(NULL));

	string msg; 
	while(true){
		sleep( 1 + (rand()/RAND_MAX) );
		msg = "";
		
		//n = "Sensor ID: ";
		msg += argv[3];
		//n += "\n\t";
		msg += " ";
		msg += argv[4];
		msg += " ";
		// Função para chutar os valores da humidade
		// se for mudar o dado passado mudar AQUI:
		
		for (int i = 0; i < 3; i++){
			msg += (char)(rand()%(10) + 48);
		}

		//enviando a mensagem
		try{
			s->send_data(msg);
		}catch(int e){
			exit_error("ERRO ao enviar mensagem, Exception: ", e);
		}
	}

	delete s;
	return 0;
}