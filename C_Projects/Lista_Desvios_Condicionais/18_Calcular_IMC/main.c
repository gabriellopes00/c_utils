#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float peso, altura, imc;

    printf("Digite o seu peso em quilogramas: ");
    scanf("%f", &peso);

    printf("Digite a sua altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Seu IMC é: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Você está abaixo do peso.\n");
    } else if (imc < 24.9) {
        printf("Seu peso está dentro da faixa saudável.\n");
    } else if (imc < 29.9) {
        printf("Você está com sobrepeso.\n");
    } else if (imc < 34.9) {
        printf("Você está com obesidade grau 1.\n");
    } else if (imc < 39.9) {
        printf("Você está com obesidade grau 2.\n");
    } else {
        printf("Você está com obesidade grau 3 (obesidade mórbida).\n");
    }
	
	system("pause");
	return 0;
}
