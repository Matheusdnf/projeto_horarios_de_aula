#include "global.h" //incluede para deixar opc global 
#include "professor.h"
#include "valida.h"
#include "diciplina.h"
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
    char telefone[15],nome[100],cpf[15],email[225];
    printf("\n");
    printf("========================================================\n\n");
    printf("   *************** Cadastrar Professor ***************  \n\n");
    ler_cpf(cpf);
    ler_nome(nome);
    ler_email(email);
    ler_telefone(telefone);
    printf("                                                        \n");
    printf("Dados cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
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
    printf("             O que deseja atualizar?                    \n");
    printf("             Telefone(0) - Email(1)                     \n");
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

