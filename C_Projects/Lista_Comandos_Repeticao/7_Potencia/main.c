#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	long long int resultado = 1;
	int expoente;
	
    printf("Potências de 3 de 0 a 15:\n");

    for (expoente = 0; expoente <= 15; expoente++) {
        printf("3^%d = %lld\n", expoente, resultado);
        resultado *= 3;
    }
	
	system("pause");
	return 0;
}
