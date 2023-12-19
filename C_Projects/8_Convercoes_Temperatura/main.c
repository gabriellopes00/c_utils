#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float celsius, fahrenheit;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("%.2f graus Celsius equivalem a %.2f graus Fahrenheit.\n", celsius, fahrenheit);

    system("pause");
	return 0;
}
