#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//
// Assinatura das funções
void menu_principal(void);
void menu_sobre(void);
void menu_equipe(void);
void menu_aluno(void);
void cadastrar_aluno(void);
void buscar_aluno(void);
void atualizar_aluno(void);
void excluir_aluno(void);
//
// Programa principal
int main(void) {
    setlocale(LC_ALL,"Portuguese_Brazil");
    menu_principal();
    menu_sobre();
    menu_equipe();
    menu_aluno();
    cadastrar_aluno();
    buscar_aluno();
    atualizar_aluno();
    excluir_aluno();
    return 0;
}

// Funções
void menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===============================================================================\n");
    printf("            Universidade Federal do Rio Grande do Norte (UFRN)                 \n");
    printf("                 Centro de Ensino Superior do Seridó                           \n");
    printf("              Departamento de Computação e Tecnologia                          \n");
    printf("                  Disciplina DCT1106 -- Programação                            \n");
    printf("                  Projeto controle de horários de aula                         \n");
    printf("              Desenvolvido por Matheus Diniz Fernandes                         \n");
    printf("===============================================================================\n");
    printf("|                                                                             |\n");
    printf("|            ************* Menu principal ***************                     |\n");
    printf("|            1 - Módulo alunos                                               |\n");
    printf("|            2 - Módulo Aulas                                                |\n");
    printf("|            3 - Módulo professores                                            \n");
    printf("|            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("|                                                                             |\n");
    printf("==============================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void menu_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("|                                                                               |\n");
    printf("|            ********* Gestão de Horário de aula *********                      |\n");
    printf("|                                                                               |\n");
    printf("|  Projeto realizado para a diciplina de programação a qual buscar incoporar    |\n");
    printf("|  os principais módulos para uma gestão de horário de aula, sendo eles alunos, |\n");
    printf("|  professores e horários de aula.                                              |\n");
    printf("=================================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void menu_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            ********* Sistema de Gestão Escolar **********               |\n");
    printf("|                                                                         |\n");
    printf("|            Este projeto foi desenvolvido por;                           |\n");
    printf("|                                                                         |\n");
    printf("|            Aluno:Matheus Diniz Fernandes                                |\n");
    printf("|            E-mail:matheusdiniz870@gmail.com                             |\n");
    printf("|            Redes sociais: @matheus_dnz                                  |\n");
    printf("|            Git: Matheusdnf                                              |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 


void menu_aluno(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            = = = = = = = = =  Menu Aluno = = = = = = = = =              |\n");
    printf("|                                                                         |\n");
    printf("|            1 - Cadastrar aluno                                          |\n");
    printf("|            2 - Pesquisar aluno                                          |\n");
    printf("|            3 - Atualizar informações do aluno                           |\n");
    printf("|            4 - Excluir aluno                                            |\n");
    printf("|            0 - Voltar                                                   |\n");
    printf("|                                                                         |\n");
    printf("|            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void cadastrar_aluno(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Cadastrar Aluno ***************              |\n");
    printf("|                                                                         |\n");
    printf("|            CPF (apenas números):                                        |\n");
    printf("|            Nome completo:                                               |\n");
    printf("|            E-mail:                                                      |\n");
    printf("|            Celular (apenas números):                                    |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void buscar_aluno(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Pesquisar Aluno ***************              |\n");
    printf("|                                                                         |\n");
    printf("|            Informe o CPF(apenas números):                               |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void atualizar_aluno(void) {
    system("clear||cls");
    printf("\n");

    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            ************* Atualizar Aluno *****************              |\n");
    printf("|                                                                         |\n");
    printf("|            Informe o CPF(apenas números):                              |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void excluir_aluno(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Excluir Aluno *****************              |\n");
    printf("|                                                                         |\n");
    printf("|            Informe o CPF (apenas números):                              |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}