#include "global.h" //incluede para deixar opc global 
#include "diciplina.h"
#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Cadastrar Diciplina *************   \n\n");
    printf("                                                        \n");
    printf("         Digite qual ou quais diciplinas:                \n");
    printf("         Informe o nome do professor:                   \n");
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
    printf("/n");
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
