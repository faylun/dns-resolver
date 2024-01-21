#include <stdio.h>
#include <stdlib.h>

int main(void){
	printf("Portas Abertas: \n");
	system("netstat -nlpt");
	return 0;
}
