#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int valor;

    printf("Digite um valor inteiro (entre 1 e 9): ");
    scanf("%d", &valor);

    if (valor >= 1 && valor <= 9) {
        printf("O valor esta na faixa permitida!\n");
    } else {
        printf("O valor informado nao e permitido, pois nao esta na faixa de 1 a 9.\n");
    }
	
	system("pause");
	return 0;
}
