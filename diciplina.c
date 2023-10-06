#include "global.h" //incluede para deixar opc global 
#include "diciplina.h"
#include "valida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void menu_diciplina(void) {
    while (opc!=0){
        system("clear||cls");   
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Aluno ******************       \n");
        printf("          1 - Cadastrar Diciplina                          \n");
        printf("          2 - Pesquisar Diciplina                          \n");
        printf("          3 - Atualizar informações da Diciplina           \n");
        printf("          4 - Excluir Diciplina                            \n");
        printf("          5 - Relatório das Diciplinas                     \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                cadastrar_diciplina();
                break;
            case '2':
                buscar_diciplina();
                break;
            case '3':
                atualizar_diciplina();
                break;
            case '4':
                excluir_diciplina();
                break;
            case '5':
                relatorio_diciplina();
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


void cadastrar_diciplina(void) {
    system("clear||cls");   
    char nome[100];
    char diciplina[3];
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Cadastrar Diciplina *************   \n\n");
    printf("                                                        \n");
    printf("Pode ser 1 ou 2 diciplinas\n"); 
    ler_diciplina(diciplina);
    printf("Digite o nome do professor\n");
    ler_nome(nome);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
}

void buscar_diciplina(void) {
    system("clear||cls");
    printf("\n");  
    printf("========================================================\n");
    printf("    *************** Pesquisar Aluno *************     \n\n");
    printf("                                                        \n");
    printf("            Informe a diciplina:                        \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 

}

void atualizar_diciplina(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Diciplina *************   \n\n");
    printf("                                                        \n");
    printf("            Informe a diciplina:                        \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void excluir_diciplina(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Diciplina *************     \n\n");
    printf("                                                        \n");
    printf("            Informe a diciplina:                        \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void relatorio_diciplina(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf(" *************** Relatório Das Diciplinas ************* \n\n");
    printf("                                                        \n");
    printf("       (informar todos as diciplinas cadastrado)        \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void diciplinas(void) {
    printf("\n");
    printf("P-Português\n");
    printf("I-Inglês\n");
    printf("E-Espanhol\n");
    printf("A-Artes\n");
    printf("H-História\n");
    printf("G-Geografia\n");
    printf("L-Literatura\n");
    printf("É-Filosofia\n");
    printf("S-Sociologia\n");
    printf("M-Matemática\n");
    printf("B-Biologia\n");
    printf("Q-Química\n");
    printf("F-Física\n");
}

//funções para a validação da diciplina
void ler_diciplina(char *diciplina) {
    int t;
    bool v=true,f=false;
    while (v) {
        diciplinas();
        printf("\n");
        printf("Digite a disciplina (somente maiúsculas):");
        limpar_buffer();
        fgets(diciplina, 3 , stdin);
        limpar_buffer();
        t = valida_diciplina(diciplina);
        if (t == 1) {
            printf("válido\n");
            v = f; // Saia do loop quando a disciplina for válida
        } else if (t == 0) {
            printf("inválido\n");
        }
    }
}

int valida_diciplina(char *diciplina) {
    int tam = strlen(diciplina);
    //string que contem todas as iniciais referentes as diciplinas
    char *materia[]=   
    {"P","I","E","É","A",
    "H","G","L","F",
    "S","M","B","Q","F"};
    for (int i=0 ; i<14;i++){
        //compara se ambos os caracteres digitados estão presente no que foi digitado
        if (strcmp(diciplina, materia[i]) == 0) {  
            return 0;
        }
    }
    //Só é permitidos 1 ou 2 matérias por vez
    if( tam!=2 && tam!=3){
        return 0;
    }
    //verificar a questão dos espaços e a ocorrência de números
    for (int i = 0; i < tam; i++) {
        if (!isalpha(diciplina[i]) && !isspace(diciplina[i])) {
            return 0;
        }
    }

    return 1;
}