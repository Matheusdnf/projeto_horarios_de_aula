#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"

//código turms  6A
//nome da turma pequenas pragas

void menu_turma(void){
    int opc=-1;
    do{
        opc=-1;
        system("clear||cls");
        Turma* t; //t-turma
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Turma ******************       \n");
        printf("          1 - Cadastrar Turma                              \n");
        printf("          2 - Pesquisar Turma                              \n");
        printf("          3 - Atualizar informações da Turma               \n");
        printf("          4 - Excluir Turma                                \n");
        printf("          5 - Relatório da Turma                         \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\nDigite o que deseja fazer: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                t=cadastrar_turma();
                gravar_turma(t);
                break;
            case 2:
                buscar_turma();
                break;
            case 3:
                atualizar_turma();
                break;
            case 4:
                excluir_turma();
                break;
            case 5:
                relatorio_turma();
                break;
            case 0:
                break;
            default:
                printf("Opção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                break;
        }
    } while (opc != 0);
}

Turma *cadastrar_turma(void){
    system("clear||cls");
    Turma* t; //t-turm
    t = (Turma *)malloc(sizeof(Turma));
    printf("\n");
    printf("========================================================\n");
    printf("    ************* Cadastrar Turma *************     \n\n");
    ler_turma(t->cod);
    ler_nome(t->nome);
    t->status = 'A';
    printf("                                                        \n");
    printf("Dados da Turma cadastrada!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar(); // para aparecer o menu e ele não sair rapidamente
    return t;
    free(t);
}

void buscar_turma(void){
    system("clear||cls");
    char cpf[15];
    printf("\n");  
    printf("========================================================\n");
    printf("    *************** Pesquisar Turma *************     \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    procura_turma(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void atualizar_turma(void){
    system("clear||cls");
    char cpf[15];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Turma *************     \n\n");
    printf("                                                        \n");
    printf("      Informe o código da Turma que será atualizada     \n");
    printf("                                                        \n");
    ler_cpf(cpf);
    printf("                                                        \n");
    att_turma(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void excluir_turma(){
    system("clear||cls");
    char cpf[15];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Turma *************       \n\n");
    printf("                                                        \n");
    ler_cpf(cpf);
    remover_turma(cpf);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void relatorio_turma(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Relatório Turma *************       \n\n");
    printf("                                                        \n");
    printf("(informar todas as Turmas cadastradas)                   \n");
    listar_todos_turma();
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}
