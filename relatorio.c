#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "valida.h"

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
                relatorio_ordenado();
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
    printf(" 4 - Matrículas organizadas pelas turmas       \n");
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
    printf("       1 - Filtro de diciplina por professor      \n");
    printf("       2 - Filtro dos turno dos horários          \n");
    printf("       3 - Filtro dos dias da semana dos horários \n");
    printf("       4 - Filtro alunos da turma                 \n");
    printf("       5-  Horário de determinada Turma              \n");
    printf("       6-  Professores por turmas                    \n");
    printf("       7-  Filtro horário pelo periódo               \n");
    printf("       8-  Filtro horário de um professor            \n");
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
                filtro_periodo_horario();
                break;
            case 8:
                filtro_aulas_professor();
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
        printf("\nQual relatório deseja ver: ");
        scanf("%d",&opc);
        limpar_buffer();
        switch (opc){
            case 1:
                list_alf_aluno();
                break;
            case 2:
                list_alf_professor();
                break;
            case 3:
                list_alf_turma();
                break;
            case 4:
                list_alf_matricula();
                break;
            case 5:
                list_alf_disciplina();
                break;
            case 6:
                list_alf_h();
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
            printf("\n");
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
            printf("|%-30s|%-11s|%-36s|%-11s|%-8s|\n",std->nome,std->cpf,std->email,std->telefone,estado);
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
            printf("|%-30s|%-11s|%-36s|%-11s|%-8s|\n",prof->nome,prof->cpf,prof->email,prof->telefone,estado);
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
            printf("|%-30s|%-5s|%-8s|",t->nome,t->cod,estado);
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
                    printf("|%-30s|%-11s|%-10s|%-8s|",prof->nome,dic->cpf,dic->disciplina,estado);
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
                    printf("|%-30s|%-11s|%-6s|%-10s|%-13s|%-12s|%-8s|", prof->nome, prof->cpf, h->periodo, h->disciplina, h->dia, h->turno, estado);
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
        if (matri->status == situ ){
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
                    printf("|%-30s|%-11s|%-5s|%-8s|\n",std->nome,matri->cpf,matri->cod,estado);
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
    while (fread(dic, sizeof(Disciplina), 1, fd) && (fread(prof, sizeof(Professor), 1, fp) )) {
        int Encontrado=0;
        //esse for irá começar do zero, irá ler a quantidade de caracter representados por 
        //matri->cod que são por padrão 4 e irá i++
        for (int i = 0; i < strlen(dic->disciplina); i++) {
            //irá usar a função strstr que irá procurar uma sequencia de caracteres
            //como parametro irá ser passado matri->cod + i que irá passar por cada caracter
            // e irá procurar pelo carater que eu quero que seria o de turma
            //caso seja ambos iguais ele ira ter encontraado oq eu desejo 
            if (strstr(dic->disciplina + i, disciplina) == dic->disciplina + i) {
                Encontrado = 1;
                break;
            }
        }
        if ((Encontrado && (dic->status != 'I') && (prof->status!='I'))) {
            cont++;
            printf("|%-30s|\n",prof->nome);
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
    printf("Digite enter para continuar...");
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
    printf("Digite enter para continuar...");
    getchar();
}

void listar_h_pelo_diasemana(char *dia){
    FILE *fh;
    Horario *h;
    int cont=0;
    h = (Horario *)malloc(sizeof(Horario));
    fh = fopen("Horario.dat", "rb");
    int diaEncontrado = 0;
    if (fh == NULL){
        printf("\nNenhum horario cadastrada!\n");
        return;
    }
    printf("|%-14s", "\x1B[34mTurno\x1B[0m");
    printf("|%-15s", "\x1B[34mDiciplina\x1B[0m");
    printf("|%-5s|", "\x1B[34mPeriodo\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        for (int i = 0; i < strlen(h->dia); i++) {
            if (strstr(h->dia + i, dia) == h->dia + i) {
                diaEncontrado = 1;
                break;
            }
        }
        if (diaEncontrado && (h->status != 'I')) {
            cont++;
            printf("|%-5s|%-9s|%-7s|\n", h->turno, h->disciplina, h->periodo);
        }
    }if (!cont){
        printf("Esse dia da semana não foi cadastrado!");
    }
    fclose(fh);
    free(h);
}

void filtro_alunos_turma(void){
    char turma[7];
    printf("teste:");
    scanf("%s",turma);
    limpar_buffer();
    relatorio_tabela_aluno_por_turma(turma);
    printf("Digite enter para continuar...");
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
    int cont=0;
    if ((fa == NULL) || (fm==NULL)){
        printf("\nNenhum aluno ou turma cadastrada!\n");
        return;
    }
    printf("|%-39s", "\x1B[34mNome Do Aluno\x1B[0m");
    printf("|%-9s", "\x1B[34mTurma\x1B[0m");
    printf("\n");
    //feito com a ajuda do chat gpt
    //realizará a leitura dos dois arquivos
    while (fread(std, sizeof(Aluno), 1, fa) && (fread(matri,sizeof(Matricula),1,fm))){
        //definição de variável ela começa como 0 pois n foi nada encontrado
        int Encontrado=0;
        //esse for irá começar do zero, irá ler a quantidade de caracter representados por 
        //matri->cod que são por padrão 4 e irá i++
        for (int i = 0; i < strlen(matri->cod); i++) {
            //irá usar a função strstr que irá procurar uma sequencia de caracteres
            //como parametro irá ser passado matri->cod + i que irá passar por cada caracter
            // e irá procurar pelo carater que eu quero que seria o de turma
            //caso seja ambos iguais ele ira ter encontraado oq eu desejo 
            if (strstr(matri->cod + i, turma) == matri->cod + i) {
                Encontrado = 1;
                break;
            }
        }
        if ((Encontrado && (matri->status != 'I') && (std->status!='I'))) {
            cont++;
            printf("|%-30s|%-30s\n",std->nome,matri->cod);
        }
    }if(!cont){
        printf("Essa turma não foi cadastrada no sistema");
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
    printf("Digite enter para continuar...");
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
    printf("|%-12s", "\x1B[34mTurno\x1B[0m");
    printf("|%-15s", "\x1B[34mDisciplina\x1B[0m");
    printf("|%-15s", "\x1B[34mDia da semana\x1B[0m");
    printf("|%-1s|", "\x1B[34mTurno(M,T,D)\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if ((strcmp (h->turma,turma)==0) && (h->status != 'I')) {
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if ((prof->status!='I' && strcmp(prof->cpf,h->cpf)==0)){
                    printf("|%-30s|%-10s|%-13s|%-5s|%-10s|\n", prof->nome, h->disciplina, h->dia,h->turno,h->periodo);
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
    printf("Digite enter para continuar...");
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
    printf("|%-10s|", "\x1B[34mDisciplina\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if ((strcmp (h->turma,turma)==0) && (h->status != 'I')) {
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if ((prof->status!='I' && strcmp(prof->cpf,h->cpf)==0)){
                    printf("|%-30s|%-10s|\n",prof->nome,h->disciplina);//pedir ajuda
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

void filtro_periodo_horario(void){
    char periodo[7];
    ler_periodo(periodo);
    listar_h_pelo_diasemana(periodo);
    printf("Digite enter para continuar...");
    getchar();
}

void listar_h_pelo_periodo(char *periodo){
    FILE *fh;
    Horario *h;
    int cont=0;
    h = (Horario *)malloc(sizeof(Horario));
    fh = fopen("Horario.dat", "rb");
    if (fh == NULL){
        printf("\nNenhum horario cadastrada!\n");
        return;
    }
    printf("|%-14s", "\x1B[34mTurno\x1B[0m");
    printf("|%-15s", "\x1B[34mDiciplina\x1B[0m");
    printf("|%-5s|", "\x1B[34mPeriodo\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        int diaEncontrado = 0;
        //feito com a ajuda do chat gpt
        for (int i = 0; i < strlen(h->dia); i++) {
            if (strstr(h->periodo + i, periodo) == h->periodo + i) {
                diaEncontrado = 1;
                break;
            }
        }
        if (diaEncontrado && (h->status != 'I')) {
            cont++;
            printf("|%-5s|%-9s|%-7s|\n", h->turno, h->disciplina, h->dia);
        }
    }if (!cont){
        printf("Esse dia da semana não foi cadastrado!");
    }
    fclose(fh);
    free(h);
}


void filtro_aulas_professor(void){
    char cpf[15];
    listar_todos_professor_alt();
    ler_cpf(cpf);
    listar_h_professor(cpf);
    printf("Digite enter para continuar...");
    getchar();
}

void listar_h_professor(char cpf[]){
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
    printf("|%-15s", "\x1B[34mturno\x1B[0m");
    printf("|%-15s", "\x1B[34mDisciplina\x1B[0m");
    printf("|%-15s", "\x1B[34mDia da semana\x1B[0m");
    printf("|%-1s|", "\x1B[34mTurno(M,T,D)\x1B[0m");
    printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if ((strcmp (h->cpf,cpf)==0) && (h->status != 'I')) {
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if ((prof->status!='I' && strcmp(prof->cpf,h->cpf)==0)){
                    printf("|%-10s|%-13s|%-5s|%-10s|\n", h->disciplina, h->dia,h->turno,h->periodo);//pedir ajuda
                    cont++;
                }
            }
        }
    }if(!cont){
        printf("Esse professor não foi cadastrado no sistema ou não tem nenhum aula!");
    }
    fclose(fh);
    free(h);
    fclose(fp);
    free(prof);
}


void list_alf_aluno(void){
    Aluno *list;
    list = NULL;
    gerar_lista_aluno(&list);
    exibir_lista_aluno(list);
    apagar_lista_aluno(&list);
}
void list_alf_professor(void){
    Professor *list;
    list = NULL;
    gerar_lista_professor(&list);
    exibir_lista_professor(list);
    apagar_lista_professor(&list);
}
void list_alf_turma(void){
    Turma *list;
    list = NULL;
    gerar_lista_turma(&list);
    exibir_lista_turma(list);
    apagar_lista_turma(&list);
}
void list_alf_disciplina(void){
    Disciplina *list;
    list = NULL;
    gerar_lista_disciplina(&list);
    exibir_lista_disciplina(list);
    apagar_lista_disciplina(&list);
}
void list_alf_matricula(void){
    Matricula *list;
    list = NULL;
    gerar_lista_matricula(&list);
    exibir_lista_matricula(list);
    apagar_lista_matricula(&list);
}
void list_alf_h(void){
    Horario *list;
    list = NULL;
    gerar_lista_h(&list);
    exibir_lista_h(list);
    apagar_lista_h(&list);
}
void gerar_lista_aluno(Aluno **list){
    FILE *fa;
    Aluno *std;
    apagar_lista_aluno(&(*list));
    *list = NULL;
    fa = fopen("Alunos.dat","rb");
    if (fa == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        std = (Aluno *) malloc(sizeof(Aluno));
        while (fread(std, sizeof(Aluno), 1, fa)) {
            if ((*list == NULL) || (strcmp(std->nome, (*list)->nome) < 0)) {
                std->prox = *list;
                *list = std;
            } else {
                Aluno* ant = *list;
                Aluno* at = (*list)->prox;
                while ((at != NULL) && (strcmp(at->nome, std->nome) < 0)) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = std;
                std->prox = at;
            }
            std = (Aluno*) malloc(sizeof(Aluno));
        }
        free(std);
        fclose(fa);
    } 
}

void gerar_lista_professor(Professor **list){
    FILE *fp;
    Professor *prof;
    apagar_lista_professor(&(*list));
    *list = NULL;
    fp = fopen("Professor.dat","rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        prof = (Professor *) malloc(sizeof(Professor));
        while (fread(prof, sizeof(Professor), 1, fp)) {
            if ((*list == NULL) || (strcmp(prof->nome, (*list)->nome) < 0)) {
                prof->prox = *list;
                *list = prof;
            } else {
                Professor* ant = *list;
                Professor* at = (*list)->prox;
                while ((at != NULL) && (strcmp(at->nome, prof->nome) < 0)) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = prof;
                prof->prox = at;
            }
            prof = (Professor*) malloc(sizeof(Professor));
        }
        free(prof);
        fclose(fp);
    } 
}

void gerar_lista_turma(Turma **list){
    FILE *ft;
    Turma *t;
    apagar_lista_turma(&(*list));
    *list = NULL;
    ft = fopen("Turma.dat","rb");
    if (ft == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        t = (Turma *) malloc(sizeof(Turma));
        while (fread(t, sizeof(Turma), 1, ft)) {
            if ((*list == NULL) || (strcmp(t->nome, (*list)->nome) < 0)) {
                t->prox = *list;
                *list = t;
            } else {
                Turma* ant = *list;
                Turma* at = (*list)->prox;
                while ((at != NULL) && (strcmp(at->nome, t->nome) < 0)) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = t;
                t->prox = at;
            }
            t = (Turma*) malloc(sizeof(Turma));
        }
        free(t);
        fclose(ft);
    } 
}
void gerar_lista_disciplina(Disciplina **list){
    FILE *fd;
    Disciplina *dic;
    apagar_lista_disciplina(&(*list));
    *list = NULL;
    fd = fopen("Disciplina.dat","rb");
    if (fd == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        dic = (Disciplina *) malloc(sizeof(Disciplina));
        while (fread(dic, sizeof(Disciplina), 1, fd)) {
            if ((*list == NULL) || (strcmp(dic->disciplina, (*list)->disciplina) < 0)) {
                dic->prox = *list;
                *list = dic;
            } else {
                Disciplina* ant = *list;
                Disciplina* at = (*list)->prox;
                while ((at != NULL) && (strcmp(at->disciplina, dic->disciplina) < 0)) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = dic;
                dic->prox = at;
            }
            dic = (Disciplina*) malloc(sizeof(Disciplina));
        }
        free(dic);
        fclose(fd);
    } 
}
void gerar_lista_matricula(Matricula **list){
    FILE *fa;
    Matricula *matri;
    apagar_lista_matricula(&(*list));
    *list = NULL;
    fa = fopen("Matricula.dat","rb");
    if (fa == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        matri = (Matricula *) malloc(sizeof(Matricula));
        while (fread(matri, sizeof(Matricula), 1, fa)) {
            if ((*list == NULL) || (strcmp(matri->cod, (*list)->cod) < 0)) {
                matri->prox = *list;
                *list = matri;
            } else {
                Matricula* ant = *list;
                Matricula* at = (*list)->prox;
                while ((at != NULL) && (strcmp(at->cod, matri->cod) < 0)) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = matri;
                matri->prox = at;
            }
            matri = (Matricula*) malloc(sizeof(Matricula));
        }
        free(matri);
        fclose(fa);
    } 
}
void gerar_lista_h(Horario **list){
    FILE *fh;
    Horario *h;
    apagar_lista_h(&(*list));
    *list = NULL;
    fh = fopen("Horario.dat","rb");
    if (fh == NULL) {
        printf("Erro na abertura do arquivo... \n");
        return;
    } else {
        h = (Horario *) malloc(sizeof(Horario));
        while (fread(h, sizeof(Horario), 1, fh)) {
            if ((*list == NULL) || (strcmp(h->disciplina, (*list)->disciplina) < 0)) {
                h->prox = *list;
                *list = h;
            } else {
                Horario* ant = *list;
                Horario* at = (*list)->prox;
                while ((at != NULL) && (strcmp(at->disciplina, h->disciplina) < 0)) {
                    ant = at;
                    at = at->prox;
                }
                ant->prox = h;
                h->prox = at;
            }
            h = (Horario*) malloc(sizeof(Horario));
        }
        free(h);
        fclose(fh);
    } 
}
void apagar_lista_aluno(Aluno **list) {
  Aluno *al;
  while (*list != NULL) {
    al = *list;
    *list = (*list)->prox;
    free(al);
  }  
}
void apagar_lista_professor(Professor **list) {
  Professor *al;
  while (*list != NULL) {
    al = *list;
    *list = (*list)->prox;
    free(al);
  }  
}
void apagar_lista_turma(Turma **list) {
  Turma *al;
  while (*list != NULL) {
    al = *list;
    *list = (*list)->prox;
    free(al);
  }  
}
void apagar_lista_h(Horario **list) {
  Horario *al;
  while (*list != NULL) {
    al = *list;
    *list = (*list)->prox;
    free(al);
  }  
}
void apagar_lista_disciplina(Disciplina **list) {
  Disciplina *al;
  while (*list != NULL) {
    al = *list;
    *list = (*list)->prox;
    free(al);
  }  
}

void apagar_lista_matricula(Matricula **list) {
  Matricula *al;
  while (*list != NULL) {
    al = *list;
    *list = (*list)->prox;
    free(al);
  }  
}
void exibir_lista_aluno(Aluno *aux) {
    while (aux != NULL) {
        printf("| %-39s - %-36s        -%-11s      |   \n", aux->nome, aux->email ,aux->telefone);
        aux =aux->prox;
	}
    getchar();
}

void exibir_lista_professor(Professor *aux) {
    while (aux != NULL) {
        printf("| %-39s - %-36s        -%-11s      |   \n", aux->nome, aux->email ,aux->telefone);
        aux =aux->prox;
	}
    getchar();
}

void exibir_lista_turma(Turma *aux) {
    while (aux != NULL) {
        printf("| %-39s - %-10s  |   \n", aux->nome, aux->cod);
        aux =aux->prox;
	}
    getchar();
}
//feito com a ajuda do chat gpt
void exibir_lista_disciplina(Disciplina *aux) {
    FILE *fd;
    FILE *fp;
    Disciplina *dic;
    Professor *prof;
    dic = (Disciplina *)malloc(sizeof(Disciplina));
    prof = (Professor *)malloc(sizeof(Professor));
    if (dic == NULL || prof == NULL) {
        printf("\nErro na alocação de memória!\n");
        return;
    }
    fd = fopen("Disciplina.dat", "rb");
    fp = fopen("Professor.dat", "rb");
    if (fd == NULL || fp == NULL) {
        printf("\nNenhuma Disciplina ou matriculada cadastrada!\n");
        return;
    }
    while (aux != NULL) {
        Disciplina *tempAux = aux;  // Ponteiro temporário para percorrer a lista sem modificar 'aux'
        fseek(fd, 0, SEEK_SET);
        while (fread(dic, sizeof(Disciplina), 1, fd) == 1) {
            if (dic != NULL && tempAux != NULL && strcmp(dic->cpf, tempAux->cpf) == 0 && dic->status != 'I') {
                fseek(fp, 0, SEEK_SET);
                while (fread(prof, sizeof(Professor), 1, fp) == 1) {
                    if (prof != NULL && strcmp(dic->cpf, prof->cpf) == 0) {
                        printf("| %-5s - %-39s   |", tempAux->disciplina, prof->nome);
                        printf("\n");
                        break;
                    }
                }
                break;
            }
        }
        aux = aux->prox;
    }
    fclose(fd);
    fclose(fp);
    free(dic);
    free(prof);
    getchar();
}



//feito com a ajuda do chat gpt
void exibir_lista_matricula(Matricula *aux) {
    FILE *fm;
    FILE *fa;
    Matricula *matri;
    Aluno *std;
    matri = (Matricula *)malloc(sizeof(Matricula));
    std = (Aluno *)malloc(sizeof(Aluno));
    if (matri == NULL || std == NULL) {
        printf("\nErro na alocação de memória!\n");
        return;
    }
    fm = fopen("Matricula.dat", "rb");
    fa = fopen("Alunos.dat", "rb");
    if (fm == NULL || fa == NULL) {
        printf("\nNenhuma Matricula ou aluno cadastrado!\n");
        return;
    }
    while (aux != NULL) {
        fseek(fm, 0, SEEK_SET); // Reiniciar o arquivo de matrículas para o início
        while (fread(matri, sizeof(Matricula), 1, fm) == 1) {
            if (matri != NULL && aux != NULL && strcmp(matri->cpf, aux->cpf) == 0 && matri->status != 'I') {
                fseek(fa, 0, SEEK_SET); // Reiniciar o arquivo de alunos para o início
                while (fread(std, sizeof(Aluno), 1, fa) == 1) {
                    if (std != NULL && strcmp(matri->cpf, std->cpf) == 0) {
                        printf("| %-5s - %-39s   |  ", aux->cod, std->nome);
                        printf("\n");
                        break; // Encerra o loop de alunos, pois já encontrou a correspondência
                    }
                }
                break; // Encerra o loop de matrículas, pois já encontrou a correspondência
            }
        }
        aux = aux->prox; // Mover para o próximo nó na lista
    }
    fclose(fm);
    fclose(fa);
    free(matri);
    free(std);
    getchar();
}

void exibir_lista_h(Horario *aux) {
    FILE *fh;
    FILE *fp;
    Horario *h;
    Professor *prof;
    h = (Horario *)malloc(sizeof(Horario));
    prof = (Professor *)malloc(sizeof(Professor));
    fh = fopen("Horario.dat", "rb");
    fp = fopen("Professor.dat", "rb");
    if (prof == NULL || h == NULL) {
        printf("\nErro na alocação de memória!\n");
        return;
    }
    if (fh == NULL || fp == NULL) {
        printf("\nNenhuma Horario ou professor cadastrado!\n");
        free(h);
        free(prof);
        return;
    }
    while (aux != NULL) {
        fseek(fp, 0, SEEK_SET);
        while (fread(prof, sizeof(Professor), 1, fp) == 1) {
            if (prof != NULL && aux != NULL && strcmp(prof->cpf, aux->cpf) == 0 && prof->status != 'I') {
                fseek(fh, 0, SEEK_SET);
                while (fread(h, sizeof(Horario), 1, fh) == 1) {
                    if (h != NULL && strcmp(prof->cpf, h->cpf) == 0) {
                        printf("| %-5s - %-39s - %-6s - %-13s - %-12s |  ", aux->disciplina, prof->nome, aux->turno, aux->periodo, aux->turma);
                        printf("\n");
                        break; // Encerra o loop de horários, pois já encontrou a correspondência
                    }
                }
                break; // Encerra o loop de professores, pois já encontrou a correspondência
            }
        }
        aux = aux->prox; // Mover para o próximo nó na lista
    }
    fclose(fh);
    free(h);
    fclose(fp);
    free(prof);
    getchar();
}
