#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "horario.h"
#include "professor.h"
#include "diciplina.h"
#include "relatorio.h"
#include "checagem.h"
//futuramente fazer um que exiba tanto os dados apagados como cadastrados
//utilizar o switch case
//adicionar uma varíaveu na função que escolhe o tipo


void tela_relatorio(void){
    system("clear||cls");
    printf("===================================================\n");
    printf("   ************* Menu Relatório ***************    \n");
    printf("            1 - Relatório de alunos                   \n");
    printf("            2 - Relatório de professores              \n");
    printf("            3 - Relatório de Horários                 \n");
    printf("            4 - Relatório de Diciplinas               \n");
    printf("            0 - Voltar                                \n");
    printf("===================================================\n");
}

void relatorio_tudo(void){
    int opc;
    do{
        tela_relatorio();
        printf("\nQual relatório deseja ver: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                system("clear||cls");
                printf("===================================================\n");
                printf("   *************   ALUNOS   ***************    \n\n");
                relatorio_tabela_aluno();
                printf("\n===================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                getchar();
                break;
            case 2:
                system("clear||cls");
                printf("===================================================\n");
                printf("   *************   Professores   ***************    \n\n");
                relatorio_tabela_professor();
                printf("\n===================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                getchar();
                break;
            case 3:
                system("clear||cls");
                printf("===================================================\n");
                printf("   *************   Horários   ***************    \n\n");
                relatorio_tabela_h();
                printf("\n===================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                getchar();
                break;
            case 4:
                system("clear||cls");
                printf("===================================================\n");
                printf("   *************   Diciplina   ***************    \n\n");
                listar_todos_professor_alt();
                relatorio_tabela_diciplinas();
                printf("\n===================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                getchar();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida!\n");
                getchar();
                printf("Digite enter para continuar...");
                getchar();
                break;
        }
    } while (opc != 0);
}

void formato_exibido_a(Aluno *std){
    char estado[17];
    if ((std == NULL) || (std->status == 'I')){
        printf("\nEste Aluno não existe no sistema!\n");
    }
    else{
        printf("|%-8s|%-11s|%-s|%-11s|\n",std->nome,std->cpf,std->email,std->telefone);
        if (std->status == 'M'){
            strcpy(estado, "Matriculado");
        }
        else if (std->status == 'I'){
            strcpy(estado, "Fechado");
        }
    }
}

void relatorio_tabela_aluno(void){
    FILE *fa;
    Aluno *std;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    if (fa == NULL){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
        printf("|%-17s","\x1B[31mNome\x1B[0m");
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-24s", "\x1B[31mEmail\x1B[0m");
        printf("|%-1s", "\x1B[31mTelefone\x1B[0m");
        printf("\n");
    while (fread(std, sizeof(Aluno), 1, fa)){
        if (std->status != 'I'){
            formato_exibido_a(std);
        }
    }
    fclose(fa);
    free(std);
}

void formato_exibido_p(Professor *prof){
    char estado[17];
    if ((prof == NULL) || (prof->status == 'I')){
        printf("\nEste Professor não existe no sistema!\n");
    }
    else{
        printf("|%-8s|%-11s|%-s|%-11s|\n",prof->nome,prof->cpf,prof->email,prof->telefone);
        if (prof->status == 'A'){
            strcpy(estado, "Ativo");
        }
        else if (prof->status == 'I'){
            strcpy(estado, "Fechado");
        }
    }
}

void relatorio_tabela_professor(void){
    FILE *fp;
    Professor *prof;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    if (fp == NULL){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }
        printf("|%-17s","\x1B[31mNome\x1B[0m");
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-24s", "\x1B[31mEmail\x1B[0m");
        printf("|%-1s", "\x1B[31mTelefone\x1B[0m");
        printf("\n");
    while (fread(prof, sizeof(Professor), 1, fp)){
        if (prof->status != 'I'){
            formato_exibido_p(prof);
        }
    }
    fclose(fp);
    free(prof);
}

void formato_exibido_diciplinas(Diciplina *dic){
    char estado[16];
    if ((dic == NULL) || (dic->status == 'I')){
        printf("\nEsta Diciplinas não foi cadastrada no sistema!\n");
    }
    else{
        printf("|%-11s|%-9s|\n",dic->cpf,dic->diciplina);
        printf("\n");
        if (dic->status == 'A'){
            strcpy(estado, "Diciplina Ativa");
        }
        else if (dic->status == 'I'){
            strcpy(estado, "Fechada");
        }
    }
}
void relatorio_tabela_diciplinas(void){
    FILE *fd;
    Diciplina *dic;
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    fd = fopen("Diciplina.dat", "rb");
    if (fd == NULL){
        printf("\nNenhuma Diciplina cadastrada!\n");
        return;
    }
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-1s|", "\x1B[31mDiciplina\x1B[0m");
        printf("\n");
    while (fread(dic, sizeof(Diciplina), 1, fd)){
        if (dic->status != 'I'){
            formato_exibido_diciplinas(dic);
        }
    }
    fclose(fd);
    free(dic);
}

void formato_exibido_h(Horario *h){
    char estado[16];
    if ((h == NULL) || (h->status == 'I')){
        printf("\nEste horário não foi cadastrada no sistema!\n");
    }
    else{
        printf("|%-8s|%-11s|%-s|%-11s|\n",h->periodo,h->diciplina,h->dia,h->tempo);
        printf("\n");
        if (h->status == 'A'){
            strcpy(estado, "Horário Ativo");
        }
        else if (h->status == 'I'){
            strcpy(estado, "Fechada");
        }
    }
}
void relatorio_tabela_h(void){
    FILE *fh;
    Horario *h;
    h = (Horario *)malloc(sizeof(Horario));
    fh = fopen("Horario.dat", "rb");
    if (fh == NULL){
        printf("\nNenhum horario cadastrada!\n");
        return;
    }
        printf("|%-17s","\x1B[31mNome\x1B[0m");
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-24s", "\x1B[31mEmail\x1B[0m");
        printf("|%-1s", "\x1B[31mTelefone\x1B[0m");
        printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if (h->status != 'I'){
            formato_exibido_h(h);
        }
    }
    fclose(fh);
    free(h);
}