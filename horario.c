#include "global.h"    //incluede para deixar opc global 
#include "horario.h"
#include "valida.h"    //arquivos com as assinaturas das validações
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


//funções referente a validação dos horários
void ler_periodo(char* periodo){ 
    int n; 
    bool v=true,f=false;
    while (v){ 
        printf("Digite em que horários serão [1,2...6] horário\n");
        printf("Digite o periodo (só números):"); 
        scanf("%s",periodo);
        limpar_buffer();
        n=valida_periodo(periodo);
        if (n==1){ 
            printf("válido\n"); 
            v=f;
        }else if (n==0){ 
            printf("inválido\n"); 
        } 
    } 
}
void ler_tempo(char* tempo){ 
    int t; 
    bool v=true,f=false;
    while (v){ 
        printf("Escolha se será manhã,tarde ou noite\n");
        printf("Digite o tempo (M,T,N):"); 
        scanf("%s",tempo);
        limpar_buffer();
        t=valida_tempo(tempo);
        if (t==1){ 
            printf("válido\n");
            v=f; 
        }else if (t==0){ 
            printf("inválido\n"); 
            
        } 
    } 
}    
 

void ler_dia(char* dia){ 
    int d; 
    bool v=true,f=false;
    while (v){ 
        printf("Escolha se será: \n2-Segunda \n3-Terça \nAté 6-Sexta\n");
        printf("Digite o dia:"); 
        scanf("%s",dia);
        limpar_buffer();
        d=valida_dia(dia);
        if (d==1){ 
            printf("válido\n");
            v=f; 
        }else if (d==0){ 
            printf("inválido\n"); 
            
        } 
    } 
}    
 

int valida_periodo(char* periodo) {
    int tam = strlen(periodo);
    if (!(tam >= 1 && tam <= 6)) {
        return 0;
    }
    for (int i = 0; i < tam; i++) {
        //feito com a ajuda do gpt
        if (periodo[i] < '1' || periodo[i] > '6') {
            return 0;
        }
    }
    return 1;
}

int valida_tempo(char* tempo) {
    int tam = strlen(tempo);
    char *t[]={"M","T","N"};
    if (tam!=1){
        return 0;
    }
    for (int i=0 ; i<3;i++){
        if (strcmp(tempo, t[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int valida_dia(char* dia) {
    int tam = strlen(dia);
    if (!(tam >= 1 && tam <= 5)) {
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (dia[i] < '2' || dia[i] > '6') {
            return 1;
        }
    }
    return 0;
}