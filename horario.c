#include "global.h"    //incluede para deixar opc global 
#include "horario.h"
#include "valida.h"
#include <stdio.h>
#include <stdlib.h>


void menu_horario(void) {
    while (opc!=0){
        system("clear||cls");   
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Horários ******************   \n");
        printf("          1 - Cadastrar Horário                          \n");
        printf("          2 - Pesquisar Horário                          \n");
        printf("          3 - Atualizar Horário                          \n");
        printf("          4 - Excluir Horário                            \n");
        printf("          5 - Relatório dos Horários                     \n");
        printf("          0 - Voltar                                     \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                cadastrar_horario();
                break;
            case '2':
                buscar_horario();
                break;
            case '3':
                atualizar_horario();
                break;
            case '4':
                excluir_horario();
                break;
            case '5':
                relatorio_horario();
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

void cadastrar_horario(void) {
    system("clear||cls");
    char periodo[7]; //1,2,3 horários
    char dia[7]; //segunda,terça...
    char tempo[3]; //dia,tarde,noite
    printf("========================================================\n");
    printf(" **************** Cadastrar Horário ******************  \n\n");
    printf("                                                        \n");
    ler_periodo(periodo); 
    ler_tempo(tempo);
    ler_dia(dia);
    printf("                                                        \n\n");
    printf("========================================================\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void buscar_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Pesquisar Horário *************   \n\n");
    printf("                                                        \n");
    printf("          Informe o horário:                            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void atualizar_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Horário *************   \n\n");
    printf("                                                        \n");
    printf("          Informe o horário:                            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void excluir_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Horário *************     \n\n");
    printf("                                                        \n");
    printf("          Informe o horário:                            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void relatorio_horario(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("   *************** Relatório dos Horários ************* \n\n");
    printf("                                                        \n");
    printf("       (informar todos os horários cadastrado)          \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

