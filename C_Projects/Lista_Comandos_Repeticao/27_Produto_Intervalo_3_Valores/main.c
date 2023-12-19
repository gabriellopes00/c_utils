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

    int produto_a = 1, produto_b = 1, produto_c = 1;

    for (i = 1; i <= a; i++) {
        produto_a *= i;
    }

    for (i = 1; i <= b; i++) {
        produto_b *= i;
    }

    for (i = 1; i <= c; i++) {
        produto_c *= i;
    }

    printf("Resultado do produto para a: %d\n", produto_a);
    printf("Resultado do produto para b: %d\n", produto_b);
    printf("Resultado do produto para c: %d\n", produto_c);

    int menor = produto_a;
    int maior = produto_a;

    if (produto_b < menor) menor = produto_b;
    if (produto_b > maior) maior = produto_b;

    if (produto_c < menor) menor = produto_c;
    if (produto_c > maior) maior = produto_c;

    printf("Menor valor de produto: %d\n", menor);
    printf("Maior valor de produto: %d\n", maior);

    printf("Valores ordenados do menor para o maior: ");
    if (produto_a <= produto_b && produto_a <= produto_c) {
        printf("%d, ", produto_a);
        if (produto_b <= produto_c) {
            printf("%d, %d\n", produto_b, produto_c);
        } else {
            printf("%d, %d\n", produto_c, produto_b);
        }
    } else if (produto_b <= produto_a && produto_b <= produto_c) {
        printf("%d, ", produto_b);
        if (produto_a <= produto_c) {
            printf("%d, %d\n", produto_a, produto_c);
        } else {
            printf("%d, %d\n", produto_c, produto_a);
        }
    } else {
        printf("%d, ", produto_c);
        if (produto_a <= produto_b) {
            printf("%d, %d\n", produto_a, produto_b);
        } else {
            printf("%d, %d\n", produto_b, produto_a);
        }
    }
	
	system("pause");
	return 0;
}
