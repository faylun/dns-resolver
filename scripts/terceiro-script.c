#include <stdio.h>

int main(int argc, char *argv[]){

	char *ip = argv[1];

	if (argc < 2) {
		printf("Exemplo de Uso: ./program 192.168.0");
	} else {
		for (int i = 0; i < 10; i++){
			printf("Varrendo host %s.%i\n", ip, i);
		}
	}
}
