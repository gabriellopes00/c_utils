#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if (idade >= 0 && idade <= 10) {
        printf("Ola crianca!\n");
    } else if (idade >= 11 && idade <= 14) {
        printf("Ola, voce e um(a) pre-adolescente.\n");
    } else if (idade >= 15 && idade <= 18) {
        printf("Parabens, voce ja pode ser um eleitor.\n");
    } else if (idade >= 19 && idade <= 21) {
        printf("Hummm, voce ja e um adulto.\n");
    } else {
        printf("Bem, agora ja esta na hora de sair de casa e seguir sua vida...\n");
    }	
	
	system("pause");
	return 0;
}
