#include <stdio.h>

int main(void){
	int port;
	char address[16];
	float ver = 1.1;
	printf("-=-=-=-=- Faylun -=-=-=-=-\n\n");
	printf("Digite um IP: ");
	fgets(address,16,stdin);
	printf("Digite uma Porta: ");
	scanf("%i", &port);
	printf("Porta %i | Endereco %s | Versão %.1f", port, address, ver);
	return 0;
}
