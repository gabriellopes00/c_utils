#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float altura, raio, volume;

    printf("Digite a altura da lata (em metros): ");
    scanf("%f", &altura);

    printf("Digite o raio da lata (em metros): ");
    scanf("%f", &raio);

    volume = 3.14149 * raio * raio * altura;

    printf("O volume da lata �: %.2f metros c�bicos\n", volume);
	
	system("pause");
	return 0;
}
