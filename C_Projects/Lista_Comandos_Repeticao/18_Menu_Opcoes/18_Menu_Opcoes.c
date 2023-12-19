#include <stdio.h>

int main() {
    int escolha_principal, escolha_submenu;

    while (1) {
        printf("..:: MENU SISTEMA CLIENTES ::..\n");
        printf("1. CLIENTES\n");
        printf("2. FORNECEDORES\n");
        printf("3. CIDADES\n");
        printf("9. SAIR\n");

        printf("Digite a opção principal: ");
        scanf("%d", &escolha_principal);

        switch (escolha_principal) {
            case 1:
                while (1) {
                    printf("..:: MENU CLIENTES ::..\n");
                    printf("11. CADASTRAR CLIENTE\n");
                    printf("12. ALTERAR CLIENTE\n");
                    printf("13. PESQUISAR CLIENTE\n");
                    printf("14. EXCLUIR CLIENTE\n");
                    printf("19. SAIR\n");

                    printf("Digite a opção do submenu CLIENTES: ");
                    scanf("%d", &escolha_submenu);

                    switch (escolha_submenu) {
                        case 11:
                            printf("Pressionada a opção 11 (CADASTRAR CLIENTE)\n");
                            break;
                        case 12:
                            printf("Pressionada a opção 12 (ALTERAR CLIENTE)\n");
                            break;
                        case 13:
                            printf("Pressionada a opção 13 (PESQUISAR CLIENTE)\n");
                            break;
                        case 14:
                            printf("Pressionada a opção 14 (EXCLUIR CLIENTE)\n");
                            break;
                        case 19:
                            printf("Saindo do submenu CLIENTES...\n");
                            goto submenu_fim;
                        default:
                            printf("Opção inválida no submenu CLIENTES.\n");
                            break;
                    }
                }
            submenu_fim:
                break;

            case 2:
                printf("Pressionada a opção 2 (FORNECEDORES)\n");
                break;

            case 3:
                printf("Pressionada a opção 3 (CIDADES)\n");
                break;

            case 9:
                printf("Saindo do programa...\n");
                return 0;

            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}
