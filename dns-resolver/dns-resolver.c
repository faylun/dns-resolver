#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

void printTitle(){
	printf("-=-=-=-=-=-=-=- FAYLUN DNS RESOLVER -=-=-=-=-=-=-=-=\n\n");
        printf("./dns-resolver alvo texto.txt || ./dns-resolver alvo\n\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
}

int main(int argc, char *argv[]){

        char txt[50];
        char *result;
        FILE *file = fopen(argv[2], "r");
        char *alvo;

        if (argc < 2 || argc > 3){

                printTitle();
                return(0);

        }

	if (argc == 3){

        	printf("============ ALVOS ENCONTRADOS ============\n\n");

		while(fscanf(file, "%s", &txt) != EOF){
		        result = (char *) strcat(txt, argv[1]);
		        struct hostent *target = gethostbyname(result);

		        if (target == NULL){
		                continue;
		        }

		        printf("   HOST: %s     ======>    IP: %s\n", result, inet_ntoa(*((struct in_addr *) target -> h_addr)));

		        }
        } else{

        	struct hostent *target = gethostbyname(argv[1]);
        	printf("   HOST: %s     ======>    IP: %s\n", argv[1], inet_ntoa(*((struct in_addr *) target -> h_addr)));

	}

}

