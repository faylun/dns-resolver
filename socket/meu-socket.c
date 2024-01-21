#include <stdio.h>
#include <netdb.h>

int main(){
	int meuSocket;
	int conecta;

	struct sockaddr_in alvo;

	meuSocket = socket(AF_INET, SOCK_STREAM, 0);

	alvo.sin_family = AF_INET;
	alvo.sin_port = htons(80);
	alvo.sin_addr.s_addr = inet_addr("10.0.0.1");

	conecta = connect(meuSocket, (struct sockaddr *)&alvo, sizeof alvo);

	if (conecta == 0){
		printf("Porta Aberta!\n");
		close(conecta);
		close(meuSocket);
	} else {
		printf("Porta Fechada.\n");
	}
}
