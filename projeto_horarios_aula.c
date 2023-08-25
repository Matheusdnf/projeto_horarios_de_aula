#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//
// Assinatura das fun��es
void menu_principal(void);
void menu_sobre(void);
void menu_equipe(void);
void menu_aluno(void);
void cadastrar_aluno(void);
void buscar_aluno(void);
void atualizar_aluno(void);
void excluir_aluno(void);
void menu_horario(void);
void cadastrar_horario(void);
void buscar_horario(void);
void atualizar_horario(void);
void excluir_horario(void);
void menu_professor(void);
void cadastrar_professor(void);
void buscar_professor(void);
void atualizar_professor(void);
void excluir_professor(void);

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
    menu_horario();
    cadastrar_horario();
    buscar_horario();
    atualizar_horario();
    excluir_horario();
    menu_professor();
    cadastrar_professor();
    buscar_professor();
    atualizar_professor();
    excluir_professor();
    return 0;
}

// Fun��es
void menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===============================================================================\n");
    printf("            Universidade Federal do Rio Grande do Norte (UFRN)                 \n");
    printf("                 Centro de Ensino Superior do Serid�                           \n");
    printf("              Departamento de Computa��o e Tecnologia                          \n");
    printf("                  Disciplina DCT1106 -- Programa��o                            \n");
    printf("                  Projeto controle de hor�rios de aula                         \n");
    printf("              Desenvolvido por Matheus Diniz Fernandes                         \n");
    printf("===============================================================================\n");
    printf("                       ####     ####    ######                                 \n");
    printf("                      ##  ##   ##  ##     ##                                   \n");
    printf("                      ##       ##         ##                                   \n");
    printf("                      ##        ####      ##                                   \n");
    printf("                      ##           ##     ##                                   \n");
    printf("                      ##  ##   ##  ##     ##                                   \n");
    printf("                       ####     ####      ##                                 \n\n");
    printf("                      COL�GIO SABER � DIVERS�O                               \n\n");
    printf("              Sempre preocupado em ensinar da melhor forma poss�vel!         \n\n");
    printf("===============================================================================\n");
    printf("|                                                                             |\n");
    printf("|            ************* Menu principal ***************                     |\n");
    printf("|            1 - M�dulo alunos                                                |\n");
    printf("|            2 - M�dulo Aulas                                                 |\n");
    printf("|            3 - M�dulo professores                                            \n");
    printf("|            Escolha a op��o desejada: ");
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
    printf("|            ********* Gest�o de Hor�rio de aula *********                      |\n");
    printf("|                                                                               |\n");
    printf("|  Projeto realizado para a diciplina de programa��o a qual buscar incoporar    |\n");
    printf("|  os principais m�dulos para uma gest�o de hor�rio de aula, sendo eles alunos, |\n");
    printf("|  professores e hor�rios de aula.                                              |\n");
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
    printf("|            ********* Sistema de Gest�o Escolar **********               |\n");
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
    printf("|            3 - Atualizar informa��es do aluno                           |\n");
    printf("|            4 - Excluir aluno                                            |\n");
    printf("|            0 - Voltar                                                   |\n");
    printf("|                                                                         |\n");
    printf("|            Escolha a op��o desejada: ");
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
    printf("|            CPF (apenas n�meros):                                        |\n");
    printf("|            Nome completo:                                               |\n");
    printf("|            E-mail:                                                      |\n");
    printf("|            Celular (apenas n�meros):                                    |\n");
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
    printf("|            Informe o CPF(apenas n�meros):                               |\n");
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
    printf("|            Informe o CPF(apenas n�meros):                              |\n");
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
    printf("|            Informe o CPF (apenas n�meros):                              |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void menu_horario(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            = = = = = = = = =  Menu Hor�rios = = = = = = = = =           |\n");
    printf("|                                                                         |\n");
    printf("|            1 - Cadastrar Hor�rios                                       |\n");
    printf("|            2 - Pesquisar por Hor�rios                                   |\n");
    printf("|            3 - Atualizar Hor�rio                                        |\n");
    printf("|            4 - Excluir Hor�rio                                          |\n");
    printf("|            0 - Voltar                                                   |\n");
    printf("|                                                                         |\n");
    printf("|            Escolha a op��o desejada: ");
    scanf("%c", &op);
    getchar();
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void cadastrar_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Cadastrar Hor�rio ***************            |\n");
    printf("|                                                                         |\n");
    printf("|            Digite os dias da semana:                                    |\n");
    printf("|            Digite o Per�odo do Dia:                                     |\n");
    printf("|            Digite o hor�rio:                                            |\n");
    printf("|            Nome da diciplina:                                           |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void buscar_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Pesquisar horario ***************            |\n");
    printf("|                                                                         |\n");
    printf("|            Digite a mat�ria:                                            |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void atualizar_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            ************* Atualizar hor�rio *****************            |\n");
    printf("|                                                                         |\n");
    printf("|            Informe a mat�ria:                                         |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void excluir_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Excluir hor�rio *****************            |\n");
    printf("|                                                                         |\n");
    printf("|            Informe a mat�ria:                                           |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void menu_professor(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            = = = = = = = = =  Menu Professor(a) = = = = = = = = =       |\n");
    printf("|                                                                         |\n");
    printf("|            1 - Cadastrar Professor(a)                                   |\n");
    printf("|            2 - Pesquisar por Professor(a)                               |\n");
    printf("|            3 - Atualizar Professor(a)                                   |\n");
    printf("|            4 - Excluir Professor(a)                                     |\n");
    printf("|            0 - Voltar                                                   |\n");
    printf("|                                                                         |\n");
    printf("|            Escolha a op��o desejada: ");
    scanf("%c", &op);
    getchar();
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void cadastrar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Cadastrar Professor(a) ***************       |\n");
    printf("|                                                                         |\n");
    printf("|            CPF (apenas n�meros):                                        |\n");
    printf("|            Nome completo:                                               |\n");
    printf("|            E-mail:                                                      |\n");
    printf("|            Celular (apenas n�meros):                                    |\n");
    printf("|            Mat�ria Lecionada:                                           |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void buscar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Pesquisar Professor(a) ***************       |\n");
    printf("|                                                                         |\n");
    printf("|            Digite o CPF(apenas n�meros):                                |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void atualizar_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            ************* Atualizar Professor(a) *****************       |\n");
    printf("|                                                                         |\n");
    printf("|            Digite o CPF (apenas n�meros):                               |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void excluir_professor(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("|                                                                         |\n");
    printf("|            *************** Excluir Professor(a) *****************       |\n");
    printf("|                                                                         |\n");
    printf("|            Digite o CPF (apenas n�meros):                               |\n");
    printf("|                                                                         |\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}