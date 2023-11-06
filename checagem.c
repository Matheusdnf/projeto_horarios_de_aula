#include "aluno.h"
#include "professor.h"
#include "diciplina.h"
#include "horario.h"
#include "valida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


//exibir infomações cadastras no módulo diciplina
void exibir_diciplinas_alt(Diciplina* dic){
    char estado[16];
    if ((dic==NULL) || (dic->status=='I')){
        printf("\nEsta Diciplinas não foi cadastrada no sistema!\n");
    }else{
        printf("Informações da diciplina:");
        printf("\nCPF do Professor:%s\n",dic->cpf);
        printf("Nome da diciplina:%s\n",dic->diciplina);
        printf("\n");
        if(dic->status=='A'){
            strcpy(estado,"Diciplina Ativa");
        }else if(dic->status=='I'){
            strcpy(estado,"Fechada");
        }
    }
}

//listar todas as diciplinas
void listar_todos_diciplina_alt(void){
    FILE* fd;
    Diciplina* dic;
    dic=(Diciplina*)malloc(sizeof(Diciplina));
    fd=fopen("Diciplina.dat","rb");
    if (fd==NULL){
        printf("\nNenhuma diciplina cadastrada!\n");
    }
    while(fread(dic,sizeof(Diciplina),1,fd)){
        if (dic->status!='I'){
            exibir_diciplinas_alt(dic);
        }
    }
    fclose(fd);
    free(dic);
}

//verifica se existe algum professor cadastrado no sistema
//evitar cpf iguais no sistema
int verifica_existe_prof_d(char cpf[]){
    FILE* fp;
    Professor* prof;
    int encontrado=0;
    prof=(Professor*)malloc(sizeof(Professor));
    fp=fopen("Professor.dat","rb");
    if (fp==NULL){
        printf("Erro ao abrir o arquivo!\n");
    }
    while(!feof(fp)) {
        fread(prof, sizeof(Professor), 1, fp);
        if ((strcmp(prof->cpf, cpf) == 0) && (prof->status=='A')) {
            encontrado=1;
            return 1;
        }
    }if(!encontrado){
        return 0;
    }        
    fclose(fp);
    free(prof);
    return 0;
}

//verificar se o aluno já existe no sistema
//evitar cpf iguais
int verifica_existe_aluno(char cpf[]){
    FILE* fa;
    Aluno* std;
    std=(Aluno*)malloc(sizeof(Aluno));
    fa=fopen("Alunos.dat","rb");
    while(fread(std, sizeof(Aluno), 1, fa)) {
        if ((strcmp(std->cpf, cpf) == 0)) {
            return 0;
        }
    }        
    fclose(fa);
    free(std);
    return 1;
}

//verificar se existe alguma diciplina já cadastrada
//evitar repetição e informações não válidas
int verifica_existe_d(char diciplina[]){
    FILE* fd;
    Diciplina* dic;
    int encontrado=0;
    dic=(Diciplina*)malloc(sizeof(Diciplina));
    fd=fopen("Diciplina.dat","rb");
    if (fd==NULL){
        printf("Erro ao abrir o arquivo!\n");
    }
    while(!feof(fd)) {
        fread(dic, sizeof(Diciplina), 1, fd);
        if ((strcmp(dic->diciplina, diciplina) == 0) && (dic->status=='A')) {
            encontrado=1;
            return 1;
        }
    }if(!encontrado){
        return 0;
    }        
    fclose(fd);
    free(dic);
    return 0;
}

//verificar se o problemas já existe no sistema
int verifica_existe_prof(char cpf[]){
    FILE* fp;
    Professor* prof;
    prof=(Professor*)malloc(sizeof(Professor));
    fp=fopen("Professor.dat","rb");
    if (fp==NULL){
        printf("Nenhum professor foi cadastrado!\n");
    }
    while(fread(prof, sizeof(Professor), 1, fp)) {
        if ((strcmp(prof->cpf, cpf) == 0)) {
            return 0;
        }
    }        
    fclose(fp);
    free(prof);
    return 1;
}

//explicação ilustrativa dos horários
void explicacao(void){
    printf("\x1B[31mperiodo\x1B[0m/\x1B[31mdia da semana\x1B[0m/\x1B[31mtempo(M,T,N)\x1B[0m/\x1B[31mDisciplina\x1B[0m\n");
}

//exibição de informações específicas do professor
void exibicao_professores_alt(Professor* prof){
    char estado[16];
    if ((prof==NULL) || (prof->status=='I')){
        printf("\nEste Professor não existe no sistema!\n");
    }else{
        printf("Dados do professores cadastrados:\n");
        printf("\nNome:%s",prof->nome);
        printf("CPF:%s\n",prof->cpf);
        printf("\n");
        if(prof->status=='A'){
            strcpy(estado,"Professor Ativo");
        }else if(prof->status=='I'){
            strcpy(estado,"Não Encontrado");
        }
    }
}

//listar todos os professores cadastrados
void listar_todos_professor_alt(void){
    FILE* fp;
    Professor* prof;
    prof=(Professor*)malloc(sizeof(Professor));
    fp=fopen("Professor.dat","rb");
    if (fp==NULL){
        printf("\nNenhum professor cadastrado!\n");
    }
    while(fread(prof,sizeof(Professor),1,fp)){
        if (prof->status!='I'){
            exibicao_professores_alt(prof);
        }
    }
    fclose(fp);
    free(prof);
}
