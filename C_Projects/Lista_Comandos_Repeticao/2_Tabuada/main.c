#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int numero, i;

    printf("Digite um número para a tabuada: ");
    scanf("%d", &numero);

    printf("Tabuada do %d:\n", numero);

    for (i = 1; i <= 10; i++) {
        int resultado = numero * i;
        printf("%d x %d = %d\n", numero, i, resultado);
    }	
	
	system("pause");
	return 0;
}
