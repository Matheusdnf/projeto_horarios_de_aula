#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "valida.h"
//futuramente fazer um que exiba tanto os dados apagados como cadastrados
//utilizar o switch case
//adicionar uma varíaveu na função que escolhe o tipo

void escolha_relatorio(void){
    int opc=-1;
    do{
        opc=-1;
        system("clear||cls");
        printf("===================================================\n");
        printf("   ************* Relatórios ***************        \n");
        printf("            1 - Relatório Tabela                     \n");
        printf("            2 - Relatório Filtro                   \n");
        printf("            3 - Relatório Ordenados                \n");
        printf("            0 - Voltar                             \n");
        printf("===================================================\n");
        printf("\nQual relatório deseja ver: ");
        scanf("%d",&opc);
        limpar_buffer();
        switch (opc){
            case 1:
                relatorio_tudo();
                break;
            case 2:
                relatorio_filtro();
                break;
            case 3:
                relatorio_filtro();
            case 0:
                break;
            default:
                printf("\nOpção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                break;
            }
    }while(opc!=0);
}

void tela_relatorio_ordenado(void){
    system("clear||cls");
    printf("========================================================\n");
    printf("    ************* Relatório Ordenado ***************  \n");
    printf(" 1 - Alunos organziados alfabeticamente        \n");
    printf(" 2 - Professores organziados alfabeticamente   \n");
    printf(" 3 - Turmas organziados alfabeticamente        \n");
    printf(" 4 - Matrículas organizadas Numericamente      \n");
    printf(" 5 - Disciplinas organizadas alfabeticamente   \n");
    printf(" 6 - Diciplina dos horário organizados alfabenticamente\n");
    printf(" 0 - Voltar                                    \n");
    printf("========================================================\n");
}

void tela_relatorio(void){
    system("clear||cls");
    printf("===================================================\n");
    printf("   ************* Relatório Tabela ***************    \n");
    printf("            1 - Relatório de alunos                   \n");
    printf("            2 - Relatório de professores              \n");
    printf("            3 - Relatório de Turmas                 \n");
    printf("            4 - Relatório de Matrículas               \n");
    printf("            5 - Relatório de Disciplinas               \n");
    printf("            6 - Relatório de Horários              \n");
    printf("            0 - Voltar                                \n");
    printf("===================================================\n");
}

void tela_filtro_relatorio(void){
    system("clear||cls");
    printf("===================================================\n");
    printf("   ************* Relatório Filtro ***************    \n");
    printf("       1 - Relatório de diciplina por professor      \n");
    printf("       2 - Relatório dos turno dos horários          \n");
    printf("       3 - Relatório dos dias da semana dos horários \n");
    printf("       4 - Relatório alunos da turma                 \n");
    printf("       5-  Horário de determinada Turma              \n");
    printf("       6-  Professores por turmas                    \n");
    printf("       7-                                            \n");
    printf("       8-                                            \n");
    printf("       9-                                            \n");
    printf("       0 - Voltar                                    \n");
    printf("===================================================\n");
    printf("\nQual relatório deseja ver: ");

}
void relatorio_filtro(void){
    int opc=-1;
    do{
        opc=-1;
        tela_filtro_relatorio();
        scanf("%d",&opc);
        limpar_buffer();
        switch (opc){
            case 1:
                filtro_disciplina_atrelada_professor();
                break;
            case 2:
                filtro_turno_horario();
                break;
            case 3:
                filtro_diasemana_horario();
                break;
            case 4:
                filtro_alunos_turma();
                break;
            case 5:
                filtro_horario_turmas();
                break;
            case 6:
                filtro_professores_turmas();
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                break;
            }
    }while(opc!=0);
}

void relatorio_ordenado(void){
    int opc=-1;
    do{
        opc=-1;
        tela_relatorio_ordenado();
        scanf("%d",&opc);
        switch (opc){
            case 1:
                printf("Em produção");
                getchar();
                getchar();
                break;
            case 2:
                printf("Em produção");
                getchar();
                getchar();
            case 3:
                printf("Em produção");
                getchar();
                getchar();
            case 4:
                printf("Em produção");
                getchar();
                getchar();
            case 0:
                break;
            default:
                printf("\nOpção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                break;
            }
    }while(opc!=0);
}
void relatorio_tudo(void){
    int opc=-1;
    do{
        char situ;
        opc=-1;
        tela_relatorio();
        printf("\nQual relatório deseja ver: ");
        scanf("%d", &opc);
        limpar_buffer();
        switch (opc){
            case 1:
                system("clear||cls");
                printf("=========================================================================================================\n");
                printf("                            *************   Alunos   ***************    \n\n");
                situ=escolher_filtro();
                relatorio_tabela_aluno(situ);
                printf("=========================================================================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                break;
            case 2:
                system("clear||cls");
                printf("===========================================================================================================\n");
                printf("                           *************   Professores   ***************    \n\n");
                situ=escolher_filtro();
                relatorio_tabela_professor(situ);
                printf("===========================================================================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                break;
            case 3:
                system("clear||cls");
                printf("==================================================\n");
                printf("     *************   Turmas   ***************    \n\n");
                situ=escolher_filtro();
                relatorio_tabela_turmas(situ);
                printf("\n==================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                break;
            case 5:
                system("clear||cls");
                printf("==================================================================\n");
                printf("              *************   Diciplina   ***************    \n\n");
                situ=escolher_filtro();
                relatorio_tabela_disciplinas(situ);
                printf("\n==================================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                break;
            case 4:
                system("clear||cls");
                printf("=============================================================\n");
                printf("        *************   Matriculas   ***************    \n\n");
                situ=escolher_filtro();
                relatorio_tabela_matricula(situ);
                printf("\n=============================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                break;
            case 6:
                system("clear||cls");
                printf("======================================================================================================\n");
                printf("                        *************   Horários   ***************    \n\n");
                situ=escolher_filtro();
                relatorio_tabela_h(situ);
                printf("=======================================================================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                break;
        }
    } while (opc != 0);
}
//relatórios/listagem personalizadas
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

void listar_alunos_cadastrados_alt(void){
    FILE *fa;
    Aluno *std;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    if ((fa == NULL) || (std==NULL)){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
    while (fread(std, sizeof(Aluno), 1, fa)){
        if (std->status != 'I' ){
            printf("Nome do aluno:%s|cpf:%s\n",std->nome,std->cpf);
        }
    }
    fclose(fa);
    free(std);
}


// listar todos os professores cadastrados
void listar_todos_professor_alt(void){
    FILE *fp;
    Professor *prof;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    if ((prof == NULL || fp == NULL)){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }
    while (fread(prof, sizeof(Professor), 1, fp)){
        if (prof->status != 'I'){
            printf("\nNome:%s|CPF:%s", prof->nome, prof->cpf);
        }
    }
    fclose(fp);
    free(prof);
}

//relatório com tabelas e adição de filtro
void relatorio_tabela_aluno(char situ){
    FILE *fa;
    Aluno *std;
    char estado[12];
    int cont=0;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    if ((fa == NULL) || (std==NULL)){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome\x1B[0m");
    printf("|%-20s", "\x1B[34mCPF\x1B[0m");
    printf("|%-45s", "\x1B[34mEmail\x1B[0m");
    printf("|%-20s", "\x1B[34mTelefone\x1B[0m");
    printf("|%-20s|", "\x1B[34msituação\x1B[0m");
    printf("\n");
    while (fread(std, sizeof(Aluno), 1, fa)){
        if (std->status == situ ){
            cont++;
            if (std->status == 'A'){
                strcpy(estado, "Matriculado");
            }
            else if (std->status == 'I'){
                strcpy(estado, "Inativo");
            }
            printf("|%-30s|%-11s|%-36s|%-11s|%-11s|\n",std->nome,std->cpf,std->email,std->telefone,estado);
        }
    }if(!cont){
        printf("Não há nenhum usuário inativo no momento!\n");
    }
    fclose(fa);
    free(std);
}


void relatorio_tabela_professor(char situ){
    FILE *fp;
    Professor *prof;
    char estado[12];
    int cont=0;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    if ((fp == NULL) || (prof==NULL)){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome\x1B[0m");
    printf("|%-20s", "\x1B[34mCPF\x1B[0m");
    printf("|%-45s", "\x1B[34mEmail\x1B[0m");
    printf("|%-20s", "\x1B[34mTelefone\x1B[0m");
    printf("|%-9s|", "\x1B[34msituação\x1B[0m");
    printf("\n");
    while (fread(prof, sizeof(Professor), 1, fp)){
        if (prof->status == situ ){
            cont++;
            if (prof->status == 'A'){
                strcpy(estado, "Ativo");
            }
            else if (prof->status == 'I'){
                strcpy(estado, "Inativo");
            }
            printf("|%-30s|%-11s|%-36s|%-11s|%-10s|\n",prof->nome,prof->cpf,prof->email,prof->telefone,estado);
        }
    } if(!cont){
        printf("\nNão há nenhum usuário inativo no momento!\n");
    }
    fclose(fp);
    free(prof);
}

void relatorio_tabela_turmas(char situ){
    FILE * ft;
    Turma *t;
    char estado[12];
    int cont=0;
    t = (Turma *)malloc(sizeof(Turma));
    ft= fopen("Turma.dat", "rb");
    if ((ft == NULL) || (t==NULL)){
        printf("\nNenhuma Turma cadastrada!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mnome\x1B[0m");
    printf("|%-10s", "\x1B[34mturma\x1B[0m");
    printf("|%-9s|", "\x1B[34msituação\x1B[0m");
    printf("\n");
    while (fread(t, sizeof(Turma), 1, ft)){
        if (t->status == situ ){
            cont++;
            if (t->status == 'A'){
                strcpy(estado, "Ativa");
            }
            else if (t->status == 'I'){
                strcpy(estado, "Inativa");
            }
            printf("|%-30s|%-5s|%-10s|",t->nome,t->cod,estado);
            printf("\n");
        }
    }if(!cont){
        printf("\nNão há nenhuma turma inativa no momento!\n");
    }
    fclose(ft);
    free(t);
}

void relatorio_tabela_disciplinas(char situ){
    FILE *fd;
    FILE *fp;
    Disciplina *dic;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    dic = (Disciplina *)malloc(sizeof(Disciplina));
    fd = fopen("Disciplina.dat", "rb");
    fp=fopen("Professor.dat","rb");
    char estado[12];
    int cont=0;
    if ((fd == NULL) || (fp==NULL)){
        printf("Nenhuma disciplina ou professor cadastrado!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome\x1B[0m");
    printf("|%-20s", "\x1B[34mCPF\x1B[0m");
    printf("|%-1s|", "\x1B[34mDisciplina\x1B[0m");
    printf("%-9s|", "\x1B[34mSituação\x1B[0m");
    printf("\n");
    while (fread(dic, sizeof(Disciplina), 1, fd)){
        if (dic->status == situ ){
            cont++;
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,dic->cpf)==0))){
                    if (dic->status == 'A'){
                        strcpy(estado, "Ativa");
                    }
                    else if (dic->status == 'I'){
                        strcpy(estado, "Inativa");
                    }
                    printf("|%-30s|%-11s|%-10s|%-10s|",prof->nome,dic->cpf,dic->disciplina,estado);
                    printf("\n");
                }
            }
        }
    }if(!cont){
        printf("\nNão há nenhuma diciplina inativa no momento!\n");
    }
    fclose(fd);
    free(dic);
    fclose(fp);
    free(prof);
}

void relatorio_tabela_h(char situ){
    FILE *fh;
    FILE *fp;
    Horario *h;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    h = (Horario *)malloc(sizeof(Horario));
    fp=fopen("Professor.dat","rb");
    fh = fopen("Horario.dat", "rb");
    char estado[12];
    int cont=0;
    if ((fh == NULL) || (fp==NULL)) {
        printf("Nenhum horário cadastrado!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome\x1B[0m");
    printf("|%-20s", "\x1B[34mCPF\x1B[0m");
    printf("|%-15s", "\x1B[34mturno\x1B[0m");
    printf("|%-15s", "\x1B[34mDisciplina\x1B[0m");
    printf("|%-15s", "\x1B[34mDia da semana\x1B[0m");
    printf("|%-1s|", "\x1B[34mTurno(M,T,D)\x1B[0m");
    printf("%-9s|", "\x1B[34mSituação\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if (h->status == situ){
            cont++;
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if ((strcmp(prof->cpf,h->cpf)==0)){
                    if (h->status == 'A'){
                        strcpy(estado, "Ativo");
                    }
                    else if (h->status == 'I'){
                        strcpy(estado, "Inativo");
                    }
                    printf("|%-30s|%-11s|%-7s|%-10s|%-13s|%-12s|%-10s|", prof->nome, prof->cpf, h->turno, h->disciplina, h->dia, h->turno, estado);
                    printf("\n");
                }
            }
        }
    }
    if(!cont){
        printf("\nNão há nenhum horário inativo no momento!\n");
    }
    fclose(fh);
    free(h);
    fclose(fp);
    free(prof);
}

void relatorio_tabela_matricula(char situ){
    char estado[12];
    FILE *fm;
    FILE *fa;
    Matricula *matri;
    Aluno *std;
    matri = (Matricula*)malloc(sizeof(Matricula));
    std=(Aluno*)malloc(sizeof(Aluno));
    fm = fopen("Matricula.dat", "rb");
    fa=fopen("Alunos.dat","rb");
    int cont=0;
    if ((fm == NULL) || (fa==NULL)){
        printf("\nNenhuma Matricula ou aluno cadastrado!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome\x1B[0m");
    printf("|%-20s", "\x1B[34mCPF\x1B[0m");
    printf("|%-10s|", "\x1B[34mTurma\x1B[0m");
    printf("%-9s|", "\x1B[34mSituação\x1B[0m");
    printf("\n");
    while (fread(matri, sizeof(Matricula), 1, fm)){
        if (matri->status == 'I'){
            cont++;
            rewind(fa);
            while(fread(std,sizeof(Aluno),1,fa)){
                if(((strcmp(matri->cpf,std->cpf)==0))){
                    if (matri->status == 'A'){
                        strcpy(estado, "Ativa");
                    }
                    else if (matri->status == 'I'){
                        strcpy(estado, "Inativa");
                    }
                    printf("|%-30s|%-11s|%-5s|%2s|\n",std->nome,matri->cpf,matri->cod,estado);
                    printf("\n");
                }    
            }
        }
    }if(!cont){
        printf("\nNão há nenhuma matrícula inativa no momento!\n");
    }
    fclose(fm);
    free(matri);
    fclose(fa);
    free(std);
}

//relatório com filtro

void filtro_disciplina_atrelada_professor(void){
    char diciplina[3];
    ler_disciplinas(diciplina);
    listar_professor_por_disciplina(diciplina);
    getchar();
}

void listar_professor_por_disciplina(char *disciplina) {
    FILE *fd;
    FILE *fp;
    Disciplina *dic;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    dic = (Disciplina *)malloc(sizeof(Disciplina));
    fd = fopen("Disciplina.dat", "rb");
    fp=fopen("Professor.dat","rb");
    int cont=0;
    if ((fd == NULL) || (fp==NULL)){
        printf("Nenhuma Disciplina ou professor cadastrado!\n");
        return;
    }
    printf("|%-39s|", "\x1B[34mNome Do Professor\x1B[0m");
    printf("\n");
    while (fread(dic, sizeof(Disciplina), 1, fd)) {
        if (((strncmp(dic->disciplina, disciplina, strlen(disciplina)) == 0) || (strcmp(dic->disciplina+1,disciplina)==0)) && (dic->status != 'I')) {
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,dic->cpf)==0))){
                    printf("|%-30s|\n", prof->nome);
                    cont++;
                }
            }
        }
    }if(!cont){
        printf("\nEssa diciplina não foi atrelada a nenhum professor!\n");
    }
    fclose(fd);
    free(dic);
    free(prof);
    fclose(fp);
}


void filtro_turno_horario(void){
    char turno[3];
    ler_turno(turno);
    listar_h_por_turno(turno);
    getchar();
    getchar();
}

void listar_h_por_turno(char *turno) {
    FILE *fh;
    FILE *fp;
    Horario *h;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    h = (Horario *)malloc(sizeof(Horario));
    fp=fopen("Professor.dat","rb");
    fh = fopen("Horario.dat", "rb");
    int cont=0;
    if ((fh == NULL) || (fp==NULL)) {
        printf("Nenhum horário cadastrado ou professor!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome Professor\x1B[0m");
    printf("|%-15s", "\x1B[34mDisciplina\x1B[0m");
    printf("|%-15s", "\x1B[34mDia da semana\x1B[0m");
    printf("|%-10s|", "\x1B[34mTurma\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if ((strcmp (h->turno,turno)==0) && (h->status != 'I')) {
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if ((prof->status!='I' && strcmp(prof->cpf,h->cpf)==0)){
                    printf("|%-30s|%-10s|%-13s|%-5s|\n", prof->nome, h->disciplina, h->dia,h->turma);//pedir ajuda
                    cont++;
                }
            }
        }
    }if(!cont){
        printf("Não existe horário nesse Turno!");
    }
    fclose(fh);
    free(h);
    fclose(fp);
    free(prof);
}

void filtro_diasemana_horario(void){
    char dia[7];
    ler_dia(dia);
    listar_h_pelo_diasemana(dia);
    getchar();
    getchar();
}

void listar_h_pelo_diasemana(char *dia){
    FILE *fh;
    Horario *h;
    int cont=0;
    h = (Horario *)malloc(sizeof(Horario));
    fh = fopen("Horario.dat", "rb");
    if (fh == NULL){
        printf("\nNenhum horario cadastrada!\n");
        return;
    }
    printf("|%-15s","\x1B[31mturno\x1B[0m");
    printf("|%-15s", "\x1B[31mDiciplina\x1B[0m");
    printf("|%-15s", "\x1B[31mPeriodo\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
         if (((strncmp(h->dia,dia, strlen(dia)) == 0) || (strcmp(h->dia+1,dia)==0)) && (h->status != 'I')){
            cont++;
            printf("|%-7s|%-9s|%-13s|\n",h->turno,h->disciplina,h->periodo);
        }
    }if (!cont){
        printf("Esse dia da semana não foi cadastrado!");
    }
    fclose(fh);
    free(h);
}

void filtro_alunos_turma(void){
    char turma[7];
    ler_turma(turma);
    relatorio_tabela_aluno_por_turma(turma);
    getchar();
    getchar();
}

void relatorio_tabela_aluno_por_turma(char *turma){
    FILE *fa;
    Aluno *std;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    FILE* fm;
    Matricula *matri;
    matri=(Matricula*)malloc(sizeof(Matricula));
    fm=fopen("Matricula.dat","rb");
    if ((fa == NULL) || (fm==NULL)){
        printf("\nNenhum aluno ou turma cadastrada!\n");
        return;
    }
        printf("|%-39s","\x1B[31mNome Do Aluno\x1B[0m");
        printf("|%-9s", "\x1B[31mTurma\x1B[0m");
        printf("\n");
    while (fread(std, sizeof(Aluno), 1, fa) && (fread(matri,sizeof(Matricula),1,fm))){
        if ( (matri->status!='I') && (strncmp(matri->cod,turma, strlen(turma)) == 0)) {
            printf("|%-30s|%-30s\n",std->nome,matri->cod);
        }
    }
    fclose(fa);
    fclose(fm);
    free(matri);
    free(std);
}

void filtro_horario_turmas(void){
    char turma[5];
    char situ='A';
    relatorio_tabela_turmas(situ);
    ler_turma(turma);
    listar_h_turma(turma);
    getchar();
    getchar();
}

void listar_h_turma(char *turma) {
    FILE *fh;
    FILE *fp;
    Horario *h;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    h = (Horario *)malloc(sizeof(Horario));
    fp=fopen("Professor.dat","rb");
    fh = fopen("Horario.dat", "rb");
    int cont=0;
    if ((fh == NULL) || (fp==NULL)) {
        printf("Nenhum horário cadastrado ou professor!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome\x1B[0m");
    printf("|%-15s", "\x1B[34mturno\x1B[0m");
    printf("|%-15s", "\x1B[34mDisciplina\x1B[0m");
    printf("|%-15s", "\x1B[34mDia da semana\x1B[0m");
    printf("|%-1s|", "\x1B[34mTurno(M,T,D)\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if ((strcmp (h->turma,turma)==0) && (h->status != 'I')) {
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if ((prof->status!='I' && strcmp(prof->cpf,h->cpf)==0)){
                    printf("|%-30s|%-10s|%-13s|%-5s|%-10s|\n", prof->nome, h->disciplina, h->dia,h->turno,h->periodo);//pedir ajuda
                    cont++;
                }
            }
        }
    }if(!cont){
        printf("Não essa turma ainda não tem um horário!");
    }
    fclose(fh);
    free(h);
    fclose(fp);
    free(prof);
}

void filtro_professores_turmas(void){
    char turma[5];
    char situ='A';
    relatorio_tabela_turmas(situ);
    ler_turma(turma);
    professores_por_turma(turma);
    getchar();
    getchar();
}

void professores_por_turma(char *turma) {
    FILE *fh;
    FILE *fp;
    Horario *h;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    h = (Horario *)malloc(sizeof(Horario));
    fp=fopen("Professor.dat","rb");
    fh = fopen("Horario.dat", "rb");
    int cont=0;
    if ((fh == NULL) || (fp==NULL)) {
        printf("Nenhum horário cadastrado ou professor!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome do(s) professores\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if ((strcmp (h->turma,turma)==0) && (h->status != 'I')) {
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if ((prof->status!='I' && strcmp(prof->cpf,h->cpf)==0)){
                    printf("|%-30s|\n",prof->nome);//pedir ajuda
                    cont++;
                }
            }
        }
    }if(!cont){
        printf("Não essa turma ainda não tem um horário!");
    }
    fclose(fh);
    free(h);
    fclose(fp);
    free(prof);
}

//relatorio relacionando diciplina e professor
//professores que dão aula em determinada turmas
//fazer filtro que mostre os horário de uma determinada turma 
//filtro que mostre as aulas do professor
