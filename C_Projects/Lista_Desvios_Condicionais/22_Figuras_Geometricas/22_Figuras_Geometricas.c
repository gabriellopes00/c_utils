#include <stdio.h>
#include <math.h>

int main() {
    int opcao;
    double area_retangulo, area_triangulo, area_quadrado, area_circulo;
    double menor_area, maior_area;
    
    printf("Escolha uma figura geométrica:\n");
    printf("1. Retângulo\n");
    printf("2. Triângulo\n");
    printf("3. Quadrado\n");
    printf("4. Círculo\n");
    printf("Digite o número da opção: ");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1:
            double base, altura;
            printf("Digite a base do retângulo: ");
            scanf("%lf", &base);
            printf("Digite a altura do retângulo: ");
            scanf("%lf", &altura);
            
            area_retangulo = base * altura;
            printf("A área do retângulo é: %.2lf\n", area_retangulo);
            break;
        case 2:
            double base_tri, altura_tri;
            printf("Digite a base do triângulo: ");
            scanf("%lf", &base_tri);
            printf("Digite a altura do triângulo: ");
            scanf("%lf", &altura_tri);
            
            area_triangulo = (base_tri * altura_tri) / 2.0;
            printf("A área do triângulo é: %.2lf\n", area_triangulo);
            break;
        case 3:
            double lado;
            printf("Digite o lado do quadrado: ");
            scanf("%lf", &lado);
            
            area_quadrado = lado * lado;
            printf("A área do quadrado é: %.2lf\n", area_quadrado);
            break;
        case 4:
            double raio;
            printf("Digite o raio do círculo: ");
            scanf("%lf", &raio);
            
            area_circulo = M_PI * raio * raio;
            printf("A área do círculo é: %.2lf\n", area_circulo);
            break;
        default:
            printf("Opção inválida.\n");
            return 1;
    }
    
    menor_area = area_retangulo;
    if (area_triangulo < menor_area) menor_area = area_triangulo;
    if (area_quadrado < menor_area) menor_area = area_quadrado;
    if (area_circulo < menor_area) menor_area = area_circulo;
    
    maior_area = area_retangulo;
    if (area_triangulo > maior_area) maior_area = area_triangulo;
    if (area_quadrado > maior_area) maior_area = area_quadrado;
    if (area_circulo > maior_area) maior_area = area_circulo;
    
    printf("A figura com a menor área é %.2lf\n", menor_area);
    printf("A figura com a maior área é %.2lf\n", maior_area);
    
    printf("Áreas em ordem crescente:\n");
    if (area_retangulo < area_triangulo && area_retangulo < area_quadrado && area_retangulo < area_circulo)
        printf("%.2lf, ", area_retangulo);
    if (area_triangulo < area_retangulo && area_triangulo < area_quadrado && area_triangulo < area_circulo)
        printf("%.2lf, ", area_triangulo);
    if (area_quadrado < area_retangulo && area_quadrado < area_triangulo && area_quadrado < area_circulo)
        printf("%.2lf, ", area_quadrado);
    if (area_circulo < area_retangulo && area_circulo < area_triangulo && area_circulo < area_quadrado)
        printf("%.2lf, ", area_circulo);
    
    printf("\n");
    
    system("pause");
    return 0;
}
