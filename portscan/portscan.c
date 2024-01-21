#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define GREEN   "\x1b[32m"
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"
#define BOLD    "\x1b[1m"

int main(int argc, char *argv[]){
	int meuSocket;
	int conecta;
	int porta;
	int inicio = 0;
	int final = 65535;
	char *destino;

	struct sockaddr_in alvo;

	if (argc != 2){
		printf(BOLD GREEN "-*-*-*-*-*-*-*-*-*-*-*-*- Faylun - Portscan -*-*-*-*-*-*-*-*-*-*-*-*-\n\n" RESET);
		printf(BOLD "   Uso:" RESET " %s <ALVO>\n", argv[0]);
		printf(BOLD "   Exemplo:" RESET " %s 192.168.0.1\n", argv[0]);
		printf(BOLD GREEN "\n-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-\n" RESET);
		return(0);
	} else {
		destino = argv[1];
		printf("Iniciando varredura em %s...\n", destino);
		printf("--------------------------------------------------------------\n\n");

		for (porta = inicio; porta < final; porta++){

			meuSocket = socket(AF_INET, SOCK_STREAM, 0);

			alvo.sin_family = AF_INET;
			alvo.sin_port = htons(porta);
			alvo.sin_addr.s_addr = inet_addr(destino);

			conecta = connect(meuSocket, (struct sockaddr *)&alvo, sizeof alvo);

			if (conecta == 0){
				printf("Porta " BOLD "%d " RESET"- status [" GREEN "Aberta" RESET "]\n", porta);
			}
			close(meuSocket);
		}

                printf("\n--------------------------------------------------------------\n");
		printf("Varredura Concluída.");

	}
}
