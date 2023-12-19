#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor1, valor2;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    if (valor1 == valor2) {
        printf("Os valores sao iguais.\n");
    } else {
        printf("Os valores sao diferentes.\n");
    }	
	
	system("pause");
	return 0;
}
