#include "global.h" //incluede para deixar opc global 
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
//variáveis 

void menu_aluno(void) {
    while (opc!=0){
        system("clear||cls");   
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Aluno ******************       \n");
        printf("          1 - Cadastrar aluno                              \n");
        printf("          2 - Pesquisar aluno                              \n");
        printf("          3 - Atualizar informações do aluno               \n");
        printf("          4 - Excluir aluno                                \n");
        printf("          5 - Relatório dos alunos                         \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                cadastrar_aluno();
                break;
            case '2':
                buscar_aluno();
                break;
            case '3':
                atualizar_aluno();
                break;
            case '4':
                excluir_aluno();
                break;
            case '5':
                relatorio_aluno();
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


void cadastrar_aluno(void) {
    system("clear||cls");   //aqui ser� onde ir� cadastrar um aluno que estuda na escola
    printf("\n");
    
    printf("========================================================\n");
    printf("    *************** Cadastrar Aluno *************     \n\n");
    printf("         CPF (apenas números):                          \n");
    printf("         Nome completo:                                 \n");
    printf("         E-mail:                                        \n");
    printf("         Celular (apenas números):                      \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele n�o sair rapidamente
}

void buscar_aluno(void) {
    system("clear||cls");
    printf("\n");   //quando o usuário informar o cpf do aluno irá mostrar os dados atrelados a aquelas pessoa,planejo implementar um menu que de outras opções de procura
    printf("========================================================\n");
    printf("    *************** Pesquisar Aluno *************     \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 

}

void atualizar_aluno(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Aluno *************     \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void excluir_aluno(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Aluno *************       \n\n");
    printf("                                                        \n");
    printf("            Informe o CPF(apenas números):              \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void relatorio_aluno(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Relatório Aluno *************       \n\n");
    printf("                                                        \n");
    printf("       (informar todos os alunos cadastrado)            \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}