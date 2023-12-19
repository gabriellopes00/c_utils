#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float atividades_np1, avaliacao1_np1;
    float atividades_np2, avaliacao2_np2;
    float media_np1, media_np2, media_final;

    printf("Digite a nota das Atividades da NP1: ");
    scanf("%f", &atividades_np1);

    printf("Digite a nota da Avaliacao 1 da NP1: ");
    scanf("%f", &avaliacao1_np1);

    media_np1 = (atividades_np1 * 0.5) + (avaliacao1_np1 * 0.5);

    printf("Digite a nota das Atividades da NP2: ");
    scanf("%f", &atividades_np2);

    printf("Digite a nota da Avaliacao 2 da NP2: ");
    scanf("%f", &avaliacao2_np2);

    media_np2 = (atividades_np2 * 0.5) + (avaliacao2_np2 * 0.5);

    media_final = (media_np1 * 0.4) + (media_np2 * 0.6);

    printf("A media final do aluno e: %.2f\n", media_final);
	
	system("pause");
	return 0;
}
