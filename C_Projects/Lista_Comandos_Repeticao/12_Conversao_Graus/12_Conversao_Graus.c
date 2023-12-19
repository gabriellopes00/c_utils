#include <stdio.h>

int main() {
    int celsius;

    printf("Conversão de graus Celsius para Fahrenheit de 10 em 10 graus:\n");
    
    for (celsius = 10; celsius <= 100; celsius += 10) {
        double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
        printf("%d graus Celsius = %.2lf graus Fahrenheit\n", celsius, fahrenheit);
    }

    return 0;
}
