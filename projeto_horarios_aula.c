#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "horario.h"
#include "professor.h"
#include "global.h"  //incluede para deixar opc global 

// Assinatura das funções
void menu_principal(void);
void menu_sobre(void);
void menu_equipe(void);
//variável global
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
                printf("\nOpção Inválida!");
                printf("Digite enter para continuar...");getchar(); 
                break;
        }
    }while (opc!='0');
    return 0;
}

// Funções


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
    printf("           COLÉGIO SABER É DIVERSÃO               \n\n");
    printf(" Preocupados em ensinar da melhor forma possível! \n\n");
    printf("===================================================\n");
    printf("   ************* Menu principal ***************    \n");
    printf("            1 - Gestão de alunos                   \n");
    printf("            2 - Gestão de Horários                 \n");
    printf("            3 - Gestão de professores              \n");
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
    printf("                   Centro de Ensino Superior do Seridó                           \n");
    printf("                Departamento de Computação e Tecnologia                          \n");
    printf("                    Disciplina DCT1106 -- Programação                            \n");
    printf("                    Projeto controle de horários de aula                         \n");
    printf("                Desenvolvido por Matheus Diniz Fernandes                         \n");
    printf("=================================================================================\n");
    printf("                                                                                 \n");
    printf("            ********* Gestão de Horário de aula *********                        \n");
    printf("                                                                                 \n");
    printf("  Projeto realizado para a diciplina de programação a qual buscar incoporar      \n");
    printf("  os principais módulos para uma gestão de horário de aula, sendo eles alunos,   \n");
    printf("  professores e horários de aula.                                                \n");
    printf("=================================================================================\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void menu_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("===========================================================================\n");
    printf("                                                                         \n");
    printf("            ********* Sistema de Gestão Escolar **********               \n");
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

