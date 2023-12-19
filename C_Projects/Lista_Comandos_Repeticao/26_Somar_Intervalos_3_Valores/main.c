#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a, b, c, i;

    printf("Digite o valor inteiro para a: ");
    scanf("%d", &a);

    printf("Digite o valor inteiro para b: ");
    scanf("%d", &b);

    printf("Digite o valor inteiro para c: ");
    scanf("%d", &c);

    int soma_a = 0, soma_b = 0, soma_c = 0;

    for (i = 1; i <= a; i++) {
        soma_a += i;
    }

    for (i = 1; i <= b; i++) {
        soma_b += i;
    }

    for (i = 1; i <= c; i++) {
        soma_c += i;
    }

    printf("Resultado da soma para a: %d\n", soma_a);
    printf("Resultado da soma para b: %d\n", soma_b);
    printf("Resultado da soma para c: %d\n", soma_c);

    int menor = soma_a;
    int maior = soma_a;

    if (soma_b < menor) menor = soma_b;
    if (soma_b > maior) maior = soma_b;

    if (soma_c < menor) menor = soma_c;
    if (soma_c > maior) maior = soma_c;

    printf("Menor valor de soma: %d\n", menor);
    printf("Maior valor de soma: %d\n", maior);

    printf("Valores ordenados do menor para o maior: ");
    if (soma_a <= soma_b && soma_a <= soma_c) {
        printf("%d, ", soma_a);
        if (soma_b <= soma_c) {
            printf("%d, %d\n", soma_b, soma_c);
        } else {
            printf("%d, %d\n", soma_c, soma_b);
        }
    } else if (soma_b <= soma_a && soma_b <= soma_c) {
        printf("%d, ", soma_b);
        if (soma_a <= soma_c) {
            printf("%d, %d\n", soma_a, soma_c);
        } else {
            printf("%d, %d\n", soma_c, soma_a);
        }
    } else {
        printf("%d, ", soma_c);
        if (soma_a <= soma_b) {
            printf("%d, %d\n", soma_a, soma_b);
        } else {
            printf("%d, %d\n", soma_b, soma_a);
        }
    }
	
	system("pause");
	return 0;
}
