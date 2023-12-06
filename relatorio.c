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
        printf("            1 - Relatório Tudo                     \n");
        printf("            2 - Relatório Filtro                   \n");
        printf("            3 - Relatório Ordenados                \n");
        printf("            0 - Voltar                             \n");
        printf("===================================================\n");
        printf("\nQual relatório deseja ver: ");
        fflush(stdin);
        scanf("%d",&opc);
        getchar();
        fflush(stdin);
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
    printf("===================================================\n");
    printf(" ************* Relatório Ordenado ***************  \n");
    printf("     1 - Alunos organziados alfabeticamente        \n");
    printf("     2 - Professores organziados alfabeticamente   \n");
    printf("     3 - Turmas organziados alfabeticamente        \n");
    printf("      -                                           \n");
    printf("      -                                           \n");
    printf("      -                                           \n");
    printf("      -                                           \n");
    printf("      -                                           \n");
    printf("     0 - Voltar                                    \n");
    printf("===================================================\n");
}

void tela_relatorio(void){
    system("clear||cls");
    printf("===================================================\n");
    printf("   ************* Menu Relatório ***************    \n");
    printf("            1 - Relatório de alunos                   \n");
    printf("            2 - Relatório de professores              \n");
    printf("            3 - Relatório de Horários                 \n");
    printf("            4 - Relatório de Diciplinas               \n");
    printf("            5 - Relatório de Matrículas               \n");
    printf("            6 - Relatório de Turmas               \n");
    printf("            0 - Voltar                                \n");
    printf("===================================================\n");
}

void tela_filtro_relatorio(void){
    system("clear||cls");
    printf("===================================================\n");
    printf("   ************* Relatório Filtro ***************    \n");
    printf("       1 - Relatório de diciplina por professor      \n");
    printf("       2 - Relatório dos tempo dos horários          \n");
    printf("       3 - Relatório dos dias dos horários           \n");
    printf("       4 - Relatório professor diciplina             \n");
    printf("       5-                                            \n");
    printf("       6-                                            \n");
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
        switch (opc){
            case 1:
                filtro_diciplina();
                break;
            case 2:
                filtro_tempo_horario();
            case 3:
                filtro_diasemana_horario();
            case 4:
                filtro_periodo_horario();
            case 5:
                teste();
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
        opc=-1;
        tela_relatorio();
        printf("\nQual relatório deseja ver: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                system("clear||cls");
                printf("=============================================================================================\n");
                printf("                      *************   Alunos   ***************    \n\n");
                relatorio_tabela_aluno();
                printf("=============================================================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                getchar();
                break;
            case 2:
                system("clear||cls");
                printf("=============================================================================================\n");
                printf("                   *************   Professores   ***************    \n\n");
                relatorio_tabela_professor();
                printf("=============================================================================================\n");
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
            case 5:
                system("clear||cls");
                printf("===================================================\n");
                printf("   *************   Matriculas   ***************    \n\n");
                relatorio_tabela_matricula();
                printf("\n===================================================\n");
                printf("\nDigite enter para continuar...");
                getchar();
                getchar();
                break;
            case 6:
                system("clear||cls");
                printf("===================================================\n");
                printf("   *************   Turmas   ***************    \n\n");
                relatorio_tabela_turmas();
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
//relatório com tabelas
void relatorio_tabela_aluno(void){
    FILE *fa;
    Aluno *std;
    char estado[17];
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    if ((fa == NULL) || (std==NULL)){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
        printf("|%-39s","\x1B[31mNome\x1B[0m");
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-45s", "\x1B[31mEmail\x1B[0m");
        printf("|%-15s", "\x1B[31mTelefone\x1B[0m");
        printf("\n");
    while (fread(std, sizeof(Aluno), 1, fa)){
        if (std->status != 'I'){
            printf("|%-30s|%-11s|%-36s|%-11s|\n",std->nome,std->cpf,std->email,std->telefone);
            if (std->status == 'M'){
                strcpy(estado, "Matriculado");
            }
            else if (std->status == 'I'){
                strcpy(estado, "Fechado");
            }
        }
    }
    fclose(fa);
    free(std);
}


void relatorio_tabela_professor(void){
    FILE *fp;
    Professor *prof;
    char estado[17];
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    if ((fp == NULL) || (prof==NULL)){
        printf("\nNenhum professor cadastrado!\n");
        return;
    }
        printf("|%-39s","\x1B[31mNome\x1B[0m");
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-45s", "\x1B[31mEmail\x1B[0m");
        printf("|%-15s", "\x1B[31mTelefone\x1B[0m");
        printf("\n");
    while (fread(prof, sizeof(Professor), 1, fp)){
        if (prof->status != 'I'){
            printf("|%-30s|%-11s|%-36s|%-11s|\n",prof->nome,prof->cpf,prof->email,prof->telefone);
            if (prof->status == 'A'){
                strcpy(estado, "Ativo");
            }
            else if (prof->status == 'I'){
                strcpy(estado, "Fechado");
            }
        }
    }
    fclose(fp);
    free(prof);
}

void relatorio_tabela_turmas(void){
    FILE * ft;
    Turma *t;
    char estado[20];
    t = (Turma *)malloc(sizeof(Turma));
    ft= fopen("Turma.dat", "rb");
    if ((ft == NULL) || (t==NULL)){
        printf("\nNenhuma Turma cadastrada!\n");
        return;
    }
        printf("|%-39s", "\x1B[31mnome\x1B[0m");
        printf("|%-10s","turma");
        printf("\n");
    while (fread(t, sizeof(Turma), 1, ft)){
        if (t->status != 'I'){
            printf("|%-30s|%-8s|\n",t->nome,t->cod);
            printf("\n");
            if (t->status == 'A'){
                strcpy(estado, "Turma Ativa");
            }
            else if (t->status == 'I'){
                strcpy(estado, "Fechada");
            }
        }
    }
    fclose(ft);
    free(t);
}

void relatorio_tabela_diciplinas(void){
    FILE *fd;
    Diciplina *dic;
    char estado[16];
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    fd = fopen("Diciplina.dat", "rb");
    if ((fd == NULL) || (dic==NULL)){
        printf("\nNenhuma Diciplina cadastrada!\n");
        return;
    }
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-1s|", "\x1B[31mDiciplina\x1B[0m");
        printf("\n");
    while (fread(dic, sizeof(Diciplina), 1, fd)){
        if (dic->status != 'I'){
            printf("|%-11s|%-9s|",dic->cpf,dic->diciplina);
            printf("\n");
            if (dic->status == 'A'){
                strcpy(estado, "Diciplina Ativa");
            }
            else if (dic->status == 'I'){
                strcpy(estado, "Fechada");
            }
        }
    }
    fclose(fd);
    free(dic);
}

void relatorio_tabela_h(void){
    FILE *fh;
    Horario *h;
    char estado[16];
    h = (Horario *)malloc(sizeof(Horario));
    fh = fopen("Horario.dat", "rb");
    if ((fh == NULL) || (h==NULL)){
        printf("\nNenhum horario cadastrada!\n");
        return;
    }
        printf("|%-15s","\x1B[31mPeriodo\x1B[0m");
        printf("|%-15s", "\x1B[31mDiciplina\x1B[0m");
        printf("|%-15s", "\x1B[31mDia da semana\x1B[0m");
        printf("|%-1s|", "\x1B[31mTempo(M,T,D)\x1B[0m");
        printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if (h->status != 'I'){
            printf("|%-7s|%-9s|%-13s|%-12s|\n",h->periodo,h->diciplina,h->dia,h->tempo);
            printf("\n");
            if (h->status == 'A'){
                strcpy(estado, "Horário Ativo");
            }
            else if (h->status == 'I'){
                strcpy(estado, "Fechada");
            }
        }
    }
    fclose(fh);
    free(h);
}

void relatorio_tabela_matricula(void){
    FILE * fm;
    Matricula *matri;
    char estado[20];
    matri = (Matricula *)malloc(sizeof(Matricula));
    fm= fopen("Matricula.dat", "rb");
    if ((fm == NULL) || (matri==NULL)){
        printf("\nNenhuma Matricula cadastrada!\n");
        return;
    }
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-10s","turma");
        printf("\n");
    while (fread(matri, sizeof(Matricula), 1, fm)){
        if (matri->status != 'I'){
            printf("|%-11s|%-8s|\n",matri->cpf,matri->cod);
            printf("\n");
            if (matri->status == 'A'){
                strcpy(estado, "Matrícula Ativa");
            }
            else if (matri->status == 'I'){
                strcpy(estado, "Fechada");
            }
        }
    }
    fclose(fm);
    free(matri);
}

//filtro dos dados desativados
void alunos_desativados(void){
    FILE *fa;
    char estado[20];
    Aluno *std;
    std = (Aluno *)malloc(sizeof(Aluno));
    fa = fopen("Alunos.dat", "rb");
    //verifica se existe o arquivo alunos
    if (fa == NULL){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
        printf("|%-39s","\x1B[31mNome\x1B[0m");
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-45s", "\x1B[31mEmail\x1B[0m");
        printf("|%-15s", "\x1B[31mTelefone\x1B[0m");
        printf("\n");
    while (fread(std, sizeof(Aluno), 1, fa)){
        if (std->status == 'I'){
            printf("|%-30s|%-11s|%-36s|%-11s|\n",std->nome,std->cpf,std->email,std->telefone);
            if (std->status == 'M'){
                strcpy(estado, "Matriculado");
            }
            else if (std->status == 'I'){
                strcpy(estado, "Fechado");
            }
        }
    }
    fclose(fa);
    free(std);
}

void professores_desativados(void){
    FILE *fp;
    char estado[20];
    Professor *prof;
    prof = (Professor *)malloc(sizeof(Professor));
    fp = fopen("Professor.dat", "rb");
    //verifica se existe o arquivo alunos
    if (fp == NULL){
        printf("\nNenhum aluno cadastrado!\n");
        return;
    }
        printf("|%-39s","\x1B[31mNome\x1B[0m");
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-45s", "\x1B[31mEmail\x1B[0m");
        printf("|%-15s", "\x1B[31mTelefone\x1B[0m");
        printf("\n");
    while (fread(prof, sizeof(Professor), 1, fp)){
        if (prof->status == 'I'){
            printf("|%-30s|%-11s|%-36s|%-11s|\n",prof->nome,prof->cpf,prof->email,prof->telefone);
            if (prof->status == 'A'){
                strcpy(estado, "Professor ativo");
            }
            else if (prof->status == 'I'){
                strcpy(estado, "Fechado");
            }
        }
    }
    fclose(fp);
    free(prof);
}

void turmas_desativadas(void){
    FILE *ft;
    char estado[20];
    Turma *t;
    t = (Turma *)malloc(sizeof(Turma));
    ft = fopen("Turma.dat", "rb");
    //verifica se existe o arquivo alunos
    if (ft == NULL){
        printf("\nNenhuma turma cadastrada!\n");
        return;
    }
        printf("|%-39s", "\x1B[31mnome\x1B[0m");
        printf("|%-10s","turma");
        printf("\n");
    while (fread(t, sizeof(Turma), 1, ft)){
        if (t->status == 'I'){
            printf("|%-30s|%-8s|\n",t->nome,t->cod);
            if (t->status == 'A'){
                strcpy(estado, "Turma ativa");
            }
            else if (t->status == 'I'){
                strcpy(estado, "Fechado");
            }
        }
    }
    fclose(ft);
    free(t);
}

void diciplinas_desativadas(void){
    FILE *fd;
    char estado[20];
    Diciplina *dic;
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    fd = fopen("Diciplina.dat", "rb");
    //verifica se existe o arquivo alunos
    if (fd == NULL){
        printf("\nNenhuma Diciplina cadastrada!\n");
        return;
    }
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-1s|", "\x1B[31mDiciplina\x1B[0m");
        printf("\n");
    while (fread(dic, sizeof(Diciplina), 1, fd)){
        if (dic->status == 'I'){
            printf("|%-11s|%-9s|",dic->cpf,dic->diciplina);
            printf("\n");
            if (dic->status == 'A'){
                strcpy(estado, "Diciplina Ativa");
            }
            else if (dic->status == 'I'){
                strcpy(estado, "Fechada");
            }
        }
    }
    fclose(fd);
    free(dic);
}

void h_desativadas(void){
       FILE *fh;
    Horario *h;
    char estado[16];
    h = (Horario *)malloc(sizeof(Horario));
    fh = fopen("Horario.dat", "rb");
    if ((fh == NULL) || (h==NULL)){
        printf("\nNenhum horario cadastrada!\n");
        return;
    }
        printf("|%-15s","\x1B[31mPeriodo\x1B[0m");
        printf("|%-15s", "\x1B[31mDiciplina\x1B[0m");
        printf("|%-15s", "\x1B[31mDia da semana\x1B[0m");
        printf("|%-1s|", "\x1B[31mTempo(M,T,D)\x1B[0m");
        printf("\n");
    while (fread(h, sizeof(Horario), 1, fh)){
        if (h->status == 'I'){
            printf("|%-7s|%-9s|%-13s|%-12s|\n",h->periodo,h->diciplina,h->dia,h->tempo);
            printf("\n");
            if (h->status == 'A'){
                strcpy(estado, "Horário Ativo");
            }
            else if (h->status == 'I'){
                strcpy(estado, "Fechada");
            }
        }
    }
    fclose(fh);
    free(h);
}

void matriculas_desativadas(void){
    FILE * fm;
    Matricula *matri;
    char estado[20];
    matri = (Matricula *)malloc(sizeof(Matricula));
    fm= fopen("Matricula.dat", "rb");
    if ((fm == NULL) || (matri==NULL)){
        printf("\nNenhuma Matricula cadastrada!\n");
        return;
    }
        printf("|%-20s", "\x1B[31mCPF\x1B[0m");
        printf("|%-10s","turma");
        printf("\n");
    while (fread(matri, sizeof(Matricula), 1, fm)){
        if (matri->status == 'I'){
            printf("|%-11s|%-8s|\n",matri->cpf,matri->cod);
            printf("\n");
            if (matri->status == 'A'){
                strcpy(estado, "Matrícula Ativa");
            }
            else if (matri->status == 'I'){
                strcpy(estado, "Fechada");
            }
        }
    }
    fclose(fm);
    free(matri);
}

//relatório com filtro
void listar_professor_por_disciplina(char *diciplina) {
    FILE* fd;
    Diciplina *dic;
    dic = (Diciplina *)malloc(sizeof(Diciplina));
    fd = fopen("Diciplina.dat", "rb");
    if (fd==NULL){
        printf("Nenhuma diciplina cadastrada");
        return;
    }
    while (fread(dic, sizeof(Diciplina), 1, fd)) {
        if (((strncmp(dic->diciplina, diciplina, strlen(diciplina)) == 0) || (strcmp(dic->diciplina+1,diciplina)==0)) && (dic->status != 'I')) {
            printf("|%-20s", dic->cpf);
        }
    }
    fclose(fd);
    free(dic);
}

void filtro_diciplina(void){
    char diciplina[3];
    ler_diciplinas(diciplina);
    listar_professor_por_disciplina(diciplina);
    getchar();
    getchar();
}

void filtro_tempo_horario(void){
    char tempo[3];
    ler_tempo(tempo);
    listar_h_por_periodo(tempo);
    getchar();
    getchar();
}

void listar_h_por_periodo(char *tempo) {
    FILE *fh;
    Horario *h;
    int cont=0;
    h = (Horario *)malloc(sizeof(Horario));
    fh = fopen("Horario.dat", "rb");
    if (fh == NULL){
        printf("\nNenhum horario cadastrada!\n");
        return;
    }
    while (fread(h, sizeof(Horario), 1, fh)){
        if ((strcmp (h->tempo,tempo)==0) && (h->status != 'I')) {
            cont++;
            printf("|%-15s","\x1B[31mPeriodo\x1B[0m");
            printf("|%-15s", "\x1B[31mDiciplina\x1B[0m");
            printf("|%-15s", "\x1B[31mDia da semana\x1B[0m");
            printf("\n");
            printf("|%-7s|%-9s|%-13s|\n",h->periodo,h->diciplina,h->dia);
        }
    }if(!cont){
        printf("Não existe horário nesse periodo!");
    }
    fclose(fh);
    free(h);
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
    while (fread(h, sizeof(Horario), 1, fh)){
         if (((strncmp(h->dia,dia, strlen(dia)) == 0) || (strcmp(h->dia+1,dia)==0)) && (h->status != 'I')){
            cont++;
            printf("|%-15s","\x1B[31mPeriodo\x1B[0m");
            printf("|%-15s", "\x1B[31mDiciplina\x1B[0m");
            printf("|%-15s", "\x1B[31mTempo\x1B[0m");
            printf("\n");
            printf("|%-7s|%-9s|%-13s|\n",h->periodo,h->diciplina,h->tempo);
        }
    }if (!cont){
        printf("Esse dia da semana não foi cadastrado!");
    }
    fclose(fh);
    free(h);
}

void filtro_diasemana_horario(void){
    char dia[7];
    ler_dia(dia);
    listar_h_pelo_diasemana(dia);
    getchar();
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
    while (fread(h, sizeof(Horario), 1, fh)){
         if (((strncmp(h->periodo,periodo, strlen(periodo)) == 0) || (strcmp(h->periodo+1,periodo)==0)) && (h->status != 'I')){
            cont++;
            printf("|%-15s","\x1B[31mDia\x1B[0m");
            printf("|%-15s", "\x1B[31mDiciplina\x1B[0m");
            printf("|%-15s", "\x1B[31mTempo\x1B[0m");
            printf("\n");
            printf("|%-7s|%-9s|%-13s|\n",h->dia,h->diciplina,h->tempo);
        }
    }if (!cont){
        printf("Esse horário não foi cadastrado!");
    }
    fclose(fh);
    free(h);
}

void filtro_periodo_horario(void){
    char periodo[7];
    ler_periodo(periodo);
    listar_h_pelo_periodo(periodo);
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
        if ((std->status != 'I') && (matri->status!='I') && (strncmp(matri->cod,turma, strlen(turma)) == 0)) {
            printf("|%-30s|%-30s\n",std->nome,matri->cod);
        }
    }
    fclose(fa);
    fclose(fm);
    free(matri);
    free(std);
}

void teste(void){
    char turma[7];
    ler_turma(turma);
    relatorio_tabela_aluno_por_turma(turma);
    getchar();
    getchar();
}

//relatorio relacionando diciplina e professor

//fazer filtro que mostre os horário de uma determinada turma 
//filtro que mostre as aulas do professor
