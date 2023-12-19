#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float nota1, nota2, nota3, nota4, media, notaExame, novaMedia;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("Digite a quarta nota: ");
    scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4.0;

    if (media >= 7.0) {
        printf("Aprovado! Media obtida: %.2f\n", media);
    } else {
        printf("Informe a nota do exame: ");
        scanf("%f", &notaExame);

        novaMedia = (media + notaExame) / 2.0;

        if (novaMedia >= 5.0) {
            printf("Aprovado em exame! Nova media obtida: %.2f\n", novaMedia);
        } else {
            printf("Reprovado. Nova media obtida: %.2f\n", novaMedia);
        }
    }
	
	system("pause");
	return 0;
}
