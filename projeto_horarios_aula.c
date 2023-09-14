#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "horario.h"
#include "professor.h"
#include "global.h"  //incluede para deixar opc global 

// Assinatura das fun��es
void menu_principal(void);
void menu_sobre(void);
void menu_equipe(void);
//vari�vel global
char opc;
// Programa principal
int main(void) {
    do{
        menu_principal();
        printf("\nDigite o que deseja fazer: "); scanf("%1s", &opc); getchar();
        switch (opc) { 
            case '1':
                menu_aluno();
                break;
            case '2':
                menu_horario();
                break;
            case '3':
                menu_professor();
                break;
            case '4':
                menu_equipe();
                break;
            case '5':
                menu_sobre();
                break;
            case '0':
                printf("\nPrograma Finalizado");
                opc='0';
                break;
            default:
                printf("\nOp��o Inv�lida!");
                printf("Digite enter para continuar...");getchar(); 
                break;
        }
    }while (opc!='0');
    return 0;
}

// Fun��es


void menu_principal() {
    system("clear||cls");
    printf("\n");
    printf("===================================================\n");
    printf("             ####     ####    ######               \n");
    printf("            ##  ##   ##  ##     ##                 \n");
    printf("            ##       ##         ##                 \n");
    printf("            ##        ####      ##                 \n");
    printf("            ##           ##     ##                 \n");
    printf("            ##  ##   ##  ##     ##                 \n");
    printf("             ####     ####      ##                 \n\n");
    printf("           COL�GIO SABER � DIVERS�O               \n\n");
    printf(" Preocupados em ensinar da melhor forma poss�vel! \n\n");
    printf("===================================================\n");
    printf("   ************* Menu principal ***************    \n");
    printf("            1 - Gest�o de alunos                   \n");
    printf("            2 - Gest�o de Hor�rios                 \n");
    printf("            3 - Gest�o de professores              \n");
    printf("            4 - Sobre a Equipe                      \n");
    printf("            5 - Sobre o Projeto                    \n");
    printf("            0 - Finalizar programa                 \n");
    printf("                                                   \n");
}


void menu_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("              Universidade Federal do Rio Grande do Norte (UFRN)                 \n");
    printf("                   Centro de Ensino Superior do Serid�                           \n");
    printf("                Departamento de Computa��o e Tecnologia                          \n");
    printf("                    Disciplina DCT1106 -- Programa��o                            \n");
    printf("                    Projeto controle de hor�rios de aula                         \n");
    printf("                Desenvolvido por Matheus Diniz Fernandes                         \n");
    printf("=================================================================================\n");
    printf("                                                                                 \n");
    printf("            ********* Gest�o de Hor�rio de aula *********                        \n");
    printf("                                                                                 \n");
    printf("  Projeto realizado para a diciplina de programa��o a qual buscar incoporar      \n");
    printf("  os principais m�dulos para uma gest�o de hor�rio de aula, sendo eles alunos,   \n");
    printf("  professores e hor�rios de aula.                                                \n");
    printf("=================================================================================\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void menu_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("                                                                         \n");
    printf("            ********* Sistema de Gest�o Escolar **********               \n");
    printf("                                                                         \n");
    printf("            Este projeto foi desenvolvido por;                           \n");
    printf("                                                                         \n");
    printf("            Aluno:Matheus Diniz Fernandes                                \n");
    printf("            E-mail:matheusdiniz870@gmail.com                             \n");
    printf("            Redes sociais: @matheus_dnz                                  \n");
    printf("            Git: Matheusdnf                                              \n");
    printf("                                                                         \n");
    printf("===========================================================================\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
} 

