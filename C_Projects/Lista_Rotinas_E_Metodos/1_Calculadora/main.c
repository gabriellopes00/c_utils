#include <stdio.h>
#include <math.h>

// Procedimento para somar dois números
void somar(float a, float b) {
    printf("Resultado: %.2f\n", a + b);
}

// Procedimento para subtrair dois números
void subtrair(float a, float b) {
    printf("Resultado: %.2f\n", a - b);
}

// Procedimento para multiplicar dois números
void multiplicar(float a, float b) {
    printf("Resultado: %.2f\n", a * b);
}

// Procedimento para dividir dois números
void dividir(float a, float b) {
    if (b != 0) {
        printf("Resultado: %.2f\n", a / b);
    } else {
        printf("Erro: Divisao por zero.\n");
    }
}

// Procedimento para calcular o quadrado de um número
void quadrado(float a) {
    printf("Resultado: %.2f\n", a * a);
}

// Procedimento para calcular a raiz quadrada de um número
void raizQuadrada(float a) {
    if (a >= 0) {
        printf("Resultado: %.2f\n", sqrt(a));
    } else {
        printf("Erro: Nao existe raiz quadrada de numero negativo.\n");
    }
}

int main() {
    int opcao;
    float num1, num2;

    do {
        // Exibe o menu
        printf("\nCALCULADORA\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("5 - Quadrado\n");
        printf("6 - Raiz quadrada\n");
        printf("9 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        // Realiza a operação de acordo com a opção escolhida
        switch (opcao) {
            case 1:
                printf("Digite dois numeros: ");
                scanf("%f %f", &num1, &num2);
                somar(num1, num2);
                break;
            case 2:
                printf("Digite dois numeros: ");
                scanf("%f %f", &num1, &num2);
                subtrair(num1, num2);
                break;
            case 3:
                printf("Digite dois numeros: ");
                scanf("%f %f", &num1, &num2);
                multiplicar(num1, num2);
                break;
            case 4:
                printf("Digite dois numeros: ");
                scanf("%f %f", &num1, &num2);
                dividir(num1, num2);
                break;
            case 5:
                printf("Digite um numero: ");
                scanf("%f", &num1);
                quadrado(num1);
                break;
            case 6:
                printf("Digite um numero: ");
                scanf("%f", &num1);
                raizQuadrada(num1);
                break;
            case 9:
                printf("Saindo da calculadora.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}

