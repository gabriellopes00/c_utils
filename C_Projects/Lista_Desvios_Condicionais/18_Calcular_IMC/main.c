#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float peso, altura, imc;

    printf("Digite o seu peso em quilogramas: ");
    scanf("%f", &peso);

    printf("Digite a sua altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Seu IMC �: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Voc� est� abaixo do peso.\n");
    } else if (imc < 24.9) {
        printf("Seu peso est� dentro da faixa saud�vel.\n");
    } else if (imc < 29.9) {
        printf("Voc� est� com sobrepeso.\n");
    } else if (imc < 34.9) {
        printf("Voc� est� com obesidade grau 1.\n");
    } else if (imc < 39.9) {
        printf("Voc� est� com obesidade grau 2.\n");
    } else {
        printf("Voc� est� com obesidade grau 3 (obesidade m�rbida).\n");
    }
	
	system("pause");
	return 0;
}
