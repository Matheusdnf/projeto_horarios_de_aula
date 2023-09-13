#include "global.h" //incluede para deixar opc global 
#include "professor.h"
#include <stdio.h>
#include <stdlib.h>

//variáveis 

void menu_professor(void) {
    while (opc!=0){
        system("clear||cls");   
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Professor ******************   \n");
        printf("          1 - Cadastrar Professor                          \n");
        printf("          2 - Pesquisar Professor                          \n");
        printf("          3 - Atualizar informações do Professor           \n");
        printf("          4 - Excluir Professor                            \n");
        printf("          5 - Relatório dos Professores                    \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                cadastrar_professor();
                break;
            case '2':
                buscar_professor();
                break;
            case '3':
                atualizar_professor();
                break;
            case '4':
                excluir_professor();
                break;
            case '5':
                relatorio_professor();
                break;
            case '0':
                opc=0;
                break;
            default:
                printf("Opção Inválida!\n");
                getchar(); printf("Digite enter para continuar...");getchar(); 
                break;
        }
    }
}

void cadastrar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n\n");
    printf("   *************** Cadastrar Professor ***************  \n\n");
    printf("         CPF (apenas números):                            \n");
    printf("         Nome completo:                                   \n");
    printf("         E-mail:                                          \n");
    printf("         Celular (apenas números):                        \n");
    printf("         Matéria Lecionada:                              \n\n");
    printf("=========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void buscar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Buscar Professor *************    \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void atualizar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Professor *************   \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void excluir_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Professor *************     \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void relatorio_professor(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("   *************** Relatório Professor *************  \n\n");
    printf("                                                        \n");
    printf("       (informar todos os Professores cadastrado)       \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

