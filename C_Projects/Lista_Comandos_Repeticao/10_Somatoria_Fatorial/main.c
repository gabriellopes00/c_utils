#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int tabuleiro = 8, i; 
    int total_graos = 1; 
    int graos_no_quadro = 1; 

    for (i = 2; i <= tabuleiro * tabuleiro; i++) {
        graos_no_quadro *= 2;
        total_graos += graos_no_quadro;
    }

    printf("Total de graos no tabuleiro de %dx%d: %lld\n", tabuleiro, tabuleiro, total_graos);

	
	system("pause");
	return 0;
}
