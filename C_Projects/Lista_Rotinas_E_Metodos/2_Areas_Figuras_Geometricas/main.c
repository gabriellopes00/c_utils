#include <stdio.h>
#include <math.h>

// Fun��o para calcular a �rea do ret�ngulo
float calcularAreaRetangulo(float base, float altura) {
    return base * altura;
}

// Fun��o para calcular a �rea do tri�ngulo
float calcularAreaTriangulo(float base, float altura) {
    return 0.5 * base * altura;
}

// Fun��o para calcular a �rea do quadrado
float calcularAreaQuadrado(float lado) {
    return lado * lado;
}

// Fun��o para calcular a �rea do c�rculo
float calcularAreaCirculo(float raio) {
    return M_PI * raio * raio;
}

// Fun��o para calcular a �rea do paralelep�pedo
float calcularAreaParalelepipedo(float comprimento, float largura, float altura) {
    return 2 * (comprimento * largura + comprimento * altura + largura * altura);
}

// Fun��o para calcular a �rea do losango
float calcularAreaLosango(float diagonalMaior, float diagonalMenor) {
    return (diagonalMaior * diagonalMenor) / 2;
}

// Fun��o para calcular a �rea do cone
float calcularAreaCone(float raio, float altura) {
    return M_PI * raio * (raio + sqrt(altura * altura + raio * raio));
}

// Fun��o para calcular a �rea do trap�zio
float calcularAreaTrapezio(float baseMaior, float baseMenor, float altura) {
    return ((baseMaior + baseMenor) / 2) * altura;
}

int main() {
    int opcao;
    float base, altura, lado, raio, comprimento, largura, diagonalMaior, diagonalMenor, baseMaior, baseMenor;

    do {
        // Exibe o menu
        printf("\nAREAS DE FIGURAS GEOMETRICAS\n");
        printf("1 - Retangulo\n");
        printf("2 - Triangulo\n");
        printf("3 - Quadrado\n");
        printf("4 - Circulo\n");
        printf("5 - Paralelepipedo\n");
        printf("6 - Losango\n");
        printf("7 - Cone\n");
        printf("8 - Trapezio\n");
        printf("9 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        // Realiza a opera��o de acordo com a op��o escolhida
        switch (opcao) {
            case 1:
                printf("Digite a base e a altura do retangulo: ");
                scanf("%f %f", &base, &altura);
                printf("Area do retangulo: %.2f\n", calcularAreaRetangulo(base, altura));
                break;
            case 2:
                printf("Digite a base e a altura do triangulo: ");
                scanf("%f %f", &base, &altura);
                printf("Area do triangulo: %.2f\n", calcularAreaTriangulo(base, altura));
                break;
            case 3:
                printf("Digite o lado do quadrado: ");
                scanf("%f", &lado);
                printf("Area do quadrado: %.2f\n", calcularAreaQuadrado(lado));
                break;
            case 4:
                printf("Digite o raio do circulo: ");
                scanf("%f", &raio);
                printf("Area do circulo: %.2f\n", calcularAreaCirculo(raio));
                break;
            case 5:
                printf("Digite o comprimento, largura e altura do paralelepipedo: ");
                scanf("%f %f %f", &comprimento, &largura, &altura);
                printf("Area do paralelepipedo: %.2f\n", calcularAreaParalelepipedo(comprimento, largura, altura));
                break;
            case 6:
                printf("Digite as diagonais maior e menor do losango: ");
                scanf("%f %f", &diagonalMaior, &diagonalMenor);
                printf("Area do losango: %.2f\n", calcularAreaLosango(diagonalMaior, diagonalMenor));
                break;
            case 7:
                printf("Digite o raio e a altura do cone: ");
                scanf("%f %f", &raio, &altura);
                printf("Area do cone: %.2f\n", calcularAreaCone(raio, altura));
                break;
            case 8:
                printf("Digite as bases maior e menor e a altura do trapezio: ");
                scanf("%f %f %f", &baseMaior, &baseMenor, &altura);
                printf("Area do trapezio: %.2f\n", calcularAreaTrapezio(baseMaior, baseMenor, altura));
                break;
            case 9:
                printf("Saindo do programa de calculo de areas.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}

