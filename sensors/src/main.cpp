#include <cstring>
#include <cstdlib>
#include <cstdio>

#include "TempSensor.hpp"
#include "PlugSensor.hpp"
#include "LockSensor.hpp"
#include "LocationSensor.hpp"

int main(int argc, char *argv[]){
	TempSensor *ts;
	PlugSensor *ps;
	LockSensor *ls;
	LocationSensor *locs;

	if (argc != 2){
		printf("Erro\n");
	}
	else{
		if (strlen(argv[1]) != 2){
			printf("Erro\n");
		}
		else{
			switch (argv[1][0]){
				case '1':
					ls = new LockSensor(atoi(argv[1]), "127.0.0.1", 8888);
					ls->start();

					break;
				case '2':
					locs = new LocationSensor(atoi(argv[1]), "127.0.0.1", 8888);
					locs->start();

					break;
				case '3':
					ps = new PlugSensor(atoi(argv[1]), "127.0.0.1", 8888);
					ps->start();

					break;
				case '4':
					ts = new TempSensor(atoi(argv[1]), "127.0.0.1", 8888);
					ts->start();

					break;
				default:
					break;
			}
		}
	}

	// if(argc < 4){
	// 	exit_error("ERRO, falta algum Arguemntos\nArguemntos necessarios:\n\t1. Server\n\t2. Port\n\t3. Sensor ID\n\t4. Tipo de atributo\n", 0);
	// }
 	
	// Criando conexão com o servidor e a porta passados por parametros da std arg
	//		Nota: ela ira mandar a mensagem para a porta do servidor especificado
	//		idependente se existe algum servidor ouvindo a essa porta


	return 0;
}