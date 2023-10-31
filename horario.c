#include "global.h"    //incluede para deixar opc global 
#include "horario.h"
#include "valida.h"    //arquivos com as assinaturas das validações
#include "diciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Apelido Struct 
Horario* h; //horario


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
                h=cadastrar_horario();
                gravar_h(h);
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

Horario* cadastrar_horario(void) {
    system("clear||cls");
    h=(Horario*)malloc(sizeof(Horario));
    printf("========================================================\n");
    printf(" **************** Cadastrar Horário ******************  \n\n");
    printf("                                                        \n");
    ler_periodo(h->periodo); 
    ler_tempo(h->tempo);
    ler_dia(h->dia);
    diciplinas();
    ler_diciplina(h->diciplina);
    h->id=criar_id_h();
    h->status='A';
    printf("                                                        \n");
    printf("Dados cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
    return h;
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
    int cont=0;
    if (!(tam >= 1 && tam <= 6)) {
        return 0;
    }
    //evitar que o usuário digite dias que não estejam entre 1 e 6
    for (int i = 0; i < tam; i++) {
        //feito com a ajuda do gpt
        if (periodo[i] < '1' || periodo[i] > '6') {
            return 0;
        }
    //impedir que o usuário digite números repetidos
    for (int i=0 ; i<tam;i++){
        if(periodo[i]==periodo[i+1]){
            cont++;
        }
        if (cont>=1){
            return 0;
        }
    }
    }
    return 1;
}

int valida_tempo(char* tempo) {
    int tam = strlen(tempo);
    char *t[]={"M","T","N"};
    //impedir que o usário digite mais do que um caracter
    if (tam!=1){
        return 0;
    }
    // que o caracter digitado seja um dos presentes da lista
    for (int i=0 ; i<3;i++){
        if (strcmp(tempo, t[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int valida_dia(char* dia) {
    int tam = strlen(dia);
    int cont=0;
    if (!(tam >= 1 && tam <= 5)) {
        return 0;
    }
    //fazer com que o usuário só digite números entre 2 e 6
    for (int i = 0; i < tam; i++) {
        //feito com a ajuda do gpt
        if (dia[i] < '2' || dia[i] > '6') {
            return 0;
        }
    //evitar que o usuário digitei dois dias repetidos
    for (int i=0 ; i<tam;i++){
        if(dia[i]==dia[i+1]){
            cont++;
        }
        if (cont>=1){
            return 0;
        }
    }
    }
    return 1;
}
