#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float nota1, nota2, notaTrabalho, media;

    printf("Digite a nota da avaliacao 01: ");
    scanf("%f", &nota1);

    printf("Digite a nota da avaliacao 02: ");
    scanf("%f", &nota2);

    printf("Digite a nota do trabalho: ");
    scanf("%f", &notaTrabalho);
    
    if(nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10 || notaTrabalho < 0 || notaTrabalho > 10){
    	printf("Valor invalido.\n");	
	} else {
		media = (nota1 * 0.30) + (nota2 * 0.40) + (notaTrabalho * 0.30);

    	if (media >= 0.0 && media < 5.0) {
        	printf("Reprovado\n");
    	} else if (media >= 5.0 && media < 7.5) {
       		printf("Aprovado\n");
    	} else if (media >= 7.5) {
        	printf("Parabens, você foi aprovado com excelencia\n");
    	} else {
        	printf("Nota invalida\n");
    	}
	}

    system("pause");
	return 0;
}
