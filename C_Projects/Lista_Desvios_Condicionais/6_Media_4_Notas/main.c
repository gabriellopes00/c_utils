#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float nota1, nota2, nota3, nota4, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Digite a quarta nota: ");
    scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4.0;

    if (media >= 6.0) {
        printf("Aprovado! Media obtida: %.2f\n", media);
    } else {
        printf("Reprovado. Media obtida: %.2f\n", media);
    }
	
	system("pause");
	return 0;
}
