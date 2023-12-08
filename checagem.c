#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "horario.h"
#include "valida.h"
#include "turma.h"
#include "matricula.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void listar_turma_cadastradas_alt(void){
    FILE *ft;
    Turma *t;
    t = (Turma*)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "rb");
    if ((ft == NULL) || (t==NULL)){
        printf("\nNenhuma Turma cadastrada cadastrada!\n");
        return;
    }
    //listagem simples para mostrar para o usuário o nome da turma e a respectiva série dela
    printf("Informação da turma:\n");
    while (fread(t, sizeof(Turma), 1, ft)){
        if (t->status == 'A'){
            printf("Nome da turma:%s|Turma:%s\n", t->nome,t->cod);
        }
    }
    fclose(ft);
    free(t);
}

// exibição de informações específicas do professor
void exibicao_professores_alt(Professor *prof){
    char estado[16];
    if ((prof == NULL) || (prof->status == 'I')){
        printf("\nEste Professor não existe no sistema!\n");
    }
    else{
        printf("\nNome:%s", prof->nome);
        printf("\nCPF:%s\n\n", prof->cpf);
        if (prof->status == 'A'){
            strcpy(estado, "Professor Ativo");
        }
        else if (prof->status == 'I'){
            strcpy(estado, "Não Encontrado");
        }
    }
}

// listar todos os professores cadastrados
void listar_todos_professor_alt(void){
    FILE *fp;
    Professor *prof;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    if (fp == NULL){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }
    while (fread(prof, sizeof(Professor), 1, fp)){
        if (prof->status != 'I'){
            printf("Dados do professores já cadastrados:\n");
            exibicao_professores_alt(prof);
        }
    }
    fclose(fp);
    free(prof);
}

//verificar se existe i cpf do aluno repetido
int verifica_existe_aluno(char cpf[]){
    FILE *fa;
    Aluno *std;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    if (fa == NULL){
        return 1;
    }
    while (fread(std, sizeof(Aluno), 1, fa)){
        if ((std->status!='I') && (strcmp(std->cpf, cpf) == 0)){
            return 0;
        }
    }
    fclose(fa);
    free(std);
    return 1;
}

//verificar se existe professor com o cpf repetido
int verifica_existe_prof(char cpf[]){
    FILE *fp;
    Professor *prof;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    if(fp==NULL){
        return 1;
    }
    while (fread(prof, sizeof(Professor), 1, fp)){
        if ((prof->status !='I') && (strcmp(prof->cpf, cpf) == 0)){
            return 0;
        }
    }
    fclose(fp);
    free(prof);
    return 1;
}

//verificar se existe algum cpf igual já cadastrado
int verifica_aluno_matriculado(char cpf[]){
    FILE *fm;
    Matricula *matri;
    matri = (Matricula *)malloc(sizeof(Matricula));
    fm = fopen("Matricula.dat", "rb");
    if (fm == NULL){
        return 1;
    }
    while (fread(matri, sizeof(Matricula), 1, fm)){
        if ((strcmp(matri->cpf, cpf) == 0)){
            return 0;
        }
    }
    fclose(fm);
    free(matri);
    return 1;
}

//verificar se a turma existe
int verificar_turma_existente(char cod[]){
    FILE *ft;
    Turma *t; //t-turm
    t = (Turma *)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "rb");
    if(ft==NULL){
        return 1;
    }
    while (fread(t, sizeof(Turma), 1, ft)){
        if ((t->status!='I') && (strcmp(t->cod,cod)==0)){
            return 0;
        }
    }
    fclose(ft);
    free(t);
    return 1;
}

void disciplina_por_professor(char cpf[]){
    // validar se no cpf do professor tem a diciplina correspondente exibir um printf
    FILE *fd;
    Disciplina *dic;
    fd=fopen("Disciplina.dat","rb");
    dic=(Disciplina*)malloc(sizeof(Disciplina));
    if(fd==NULL){
        printf("Nenhuma diciplina foi atrelada a um professor");
        return ;
    }
    while(fread(dic,sizeof(Disciplina),1,fd)){
        if ((dic->status!='I') && (strcmp(dic->cpf,cpf)==0)){
            printf("\n\033[1;34mDisciplinas lecionada(s) por este professor:\033[0m%s\n",dic->disciplina); 
        }
    }
    fclose(fd);
    free(dic);
}

int valida_diciplina_professor(char *disciplina,char cpf[]){
    // validar se no cpf do professor tem a diciplina correspondente exibir um printf
    FILE *fd;
    Disciplina *dic;
    fd=fopen("Disciplina.dat","rb");
    dic=(Disciplina*)malloc(sizeof(Disciplina));
    if(fd==NULL){
        printf("Nenhuma diciplina foi atrelada a um professor");
        return 1;
    }
    while(fread(dic,sizeof(Disciplina),1,fd)){
        if ((dic->status!='I') && (strncmp(dic->disciplina,disciplina, strlen(disciplina)) == 0) && (strcmp(dic->cpf,cpf)==0)){
            return 0;
        }
    }
    fclose(fd);
    free(dic);
    return 1;
}
