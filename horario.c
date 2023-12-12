#include "valida.h" //arquivos com as assinaturas das validações
#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//caso não exista turma não cadastrar
void menu_horario(void){
    int opc=-1;
    do{
        opc=-1;
        system("clear||cls");
        Horario *h;
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Horários ******************   \n");
        printf("          1 - Cadastrar Horário                          \n");
        printf("          2 - Pesquisar Horário                          \n");
        printf("          3 - Atualizar Horário                          \n");
        printf("          4 - Excluir Horário                            \n");
        printf("          5 - Relatório dos Horários                     \n");
        printf("          0 - Voltar                                     \n");
        printf("===========================================================\n");
        printf("\nDigite o que deseja fazer: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                h = cadastrar_horario();
                if (h == NULL){
                    break;
                }
                gravar_h(h);
                break;
            case 2:
                buscar_horario();
                break;
            case 3:
                atualizar_horario();
                break;
            case 4:
                excluir_horario();
                break;
            case 5:
                relatorio_horario();
                break;
            case 0:
                break;
            default:
                printf("Opção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                break;
        }
    } while (opc != 0);
}

Horario *cadastrar_horario(void){
    system("clear||cls");
    char situ='A';
    Horario *h;
    FILE *fd;
    FILE *fm;
    h = (Horario *)malloc(sizeof(Horario));
    char resposta;
    fd = fopen("Disciplina.dat", "rb");
    fm=fopen("Matricula.dat","rb");
    printf("========================================================\n");
    printf(" **************** Cadastrar Horário ******************  \n\n");
    if ((fd == NULL) || (fm==NULL)){
        printf("Nenhum professor com diciplina ou aluno matriculado!\n");
        getchar();
        printf("\nDigite enter para continuar...");
        getchar();
        return NULL;
    }
    printf("Professores cadastrados\n\n");
    relatorio_tabela_disciplinas(situ);
    printf("\nDigite o cpf do professor!\n");
    do{
        //leitura do cpf
        ler_cpf(h->cpf);
        if(verifica_existe_prof(h->cpf)){
            printf("Nenhum professor foi cadastrado com esse cpf!\n");
            //caso já o usuário vai ter a chance de tentar novamente
            //tranformar em uma função
            resposta=obter_resposta();
            //Caso ele digite algo diferente de "S" no caso "N"
            //quer dizer que ele não quer mais digitar o cpf e irá retornar NULL
            if (resposta == 'N') {
                return NULL;  
            }
            //Caso o aluno com o cpf em questão não estiver cadastrado o loop se encerará
        } else {
            break;  
        }
    } while (1);
    printf("Turmas cadastradas\n");
    relatorio_tabela_turmas(situ);
    printf("\nEm qual turma esse professor irá dar aula?\n");
    do{
        ler_turma(h->turma);
        if(verificar_turma_existente(h->turma)){
            printf("Essa turma não foi cadastrada!\n");
            char resposta=obter_resposta();
            //Caso ele digite algo diferente de "S" no caso "N"
            //quer dizer que ele não quer mais digitar o cpf e irá retornar NULL
            if (resposta == 'N') {
                return NULL;  
            }
        //Caso a turma em questão não estiver cadastrado o loop se encerará
        }else{
            break;  
        }
    }while (1);
    disciplina_por_professor(h->cpf);
    disciplinas();
    do{
        ler_disciplinas(h->disciplina);
        if(valida_diciplina_professor(h->disciplina,h->cpf)){
            printf("Esse professor não leciona essa disciplina!\n");
            resposta=obter_resposta();
            if (resposta == 'N') {
                    return NULL;  
            }
            //Caso o aluno com o cpf em questão não estiver cadastrado o loop se encerará
        } else {
            break;  
        }
    }while (1);
    printf("\n");
    ler_periodo(h->periodo);
    printf("\n");
    ler_turno(h->turno);
    printf("\n");
    ler_dia(h->dia);
    printf("\n");
    h->id = criar_id_h();
    h->status = 'A';
    printf("                                                        \n");
    printf("Horário cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar(); // para aparecer o menu e ele não sair rapidamente
    return h;
    free(h);
}

void buscar_horario(void){
    system("clear||cls");
    int id = 0;
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Pesquisar Horário *************   \n\n");
    printf("                                                        \n");
    printf("Informe o id do horário:");
    scanf("%d", &id);
    printf("\n");
    procura_h(id);
    printf("                                                        \n");
    printf("========================================================\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

void atualizar_horario(void){
    system("clear||cls");
    int id = 0;
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Horário *************   \n\n");
    printf("                                                        \n");
    printf("Informe o id do horário:");
    scanf("%d", &id);
    printf("\n");
    att_h(id);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

void excluir_horario(void){
    system("clear||cls");
    int id = 0;
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Horário *************     \n\n");
    printf("                                                        \n");
    printf("Informe o id do horário:");
    scanf("%d", &id);
    limpar_buffer();
    procura_h(id);
    if(decidir_excluir()){
        remover_h(id);
    }
    else{
        return;
    }
    printf("                                                        \n");
    printf("========================================================\n");
    printf("Digite enter para continuar...");
    getchar();
}

void relatorio_horario(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf(" *************** Relatório dos Horários ************* \n\n");
    printf("                                                        \n");
    printf("\x1B[34m(informar todos os horários cadastrados)\x1B[0m\n");
    printf("                                                        \n");
    lista_todos_h();
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

// explicação ilustrativa dos horários
void explicacao(void){
    printf("\x1B[34mperiodo\x1B[0m/\x1B[34mDia da semana\x1B[0m/\x1B[34mTurno(M,T,N)\x1B[0m/\x1B[34mDisciplina\x1B[0m");
}

// funções referente a validação dos horários
void ler_periodo(char *periodo){
    int t;
    do{
        //liberar lixo de memória
        fflush(stdin);
        printf("Digite em que horários serão [1,2...6] horário\n");
        printf("Digite o turno (só números):");
        fgets(periodo,7,stdin);
        periodo[strlen(periodo)-1]=0;
        t = valida_periodo(periodo);
        if (t == 0){
            printf("Período inválido!\n");
        }
    }while(t!=1);
}

void ler_turno(char *turno){
    int t;
    do{
        fflush(stdin);
        printf("Escolha se será manhã,tarde ou noite\n");
        printf("Digite o turno (M,T,N):");
        fgets(turno,3,stdin);
        turno[strlen(turno)-1]=0;
        t = valida_turno(turno);
        if (t == 0){
            printf("turno inválido!\n");
        }
    }while(t!=1);
}

void ler_dia(char *dia){
    int t;
    do{
        fflush(stdin);
        printf("Escolha se será: \n2-Segunda \n3-Terça \nAté 6-Sexta\n");
        printf("Digite o dia:");
        fgets(dia,7,stdin);
        //remover o \n
        dia[strlen(dia)-1]=0;
        t = valida_dia(dia);
        if (t == 0){
            printf("Dia Inválido\n");
        }
    }while(t!=1);
}

int valida_periodo(char *turno){
    int tam = strlen(turno);
    int cont = 0;
    if (!(tam >= 1 && tam <= 6)){
        return 0;
    }
    // evitar que o usuário digite dias que não estejam entre 1 e 6
    for (int i = 0; i < tam; i++){
        // feito com a ajuda do gpt
        if (turno[i] < '1' || turno[i] > '6'){
            return 0;
        }
        // impedir que o usuário digite números repetidos
        for (int i = 0; i < tam; i++){
            if (turno[i] == turno[i + 1]){
                cont++;
            }
            if (cont >= 1){
                return 0;
            }
        }
    }
    return 1;
}

int valida_turno(char *turno){
    int tam = strlen(turno);
    letra_maiuscula(turno);
    char *t[] = {"M", "T", "N"};
    // impedir que o usário digite mais do que um caracter
    if (tam != 1){
        return 0;
    }
    // que o caracter digitado seja um dos presentes da lista
    for (int i = 0; i < 3; i++){
        if (strcmp(turno, t[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int valida_dia(char *dia){
    int tam = strlen(dia);
    int cont = 0;
    if (!(tam >= 1 && tam <= 5)){
        return 0;
    }
    // fazer com que o usuário só digite números entre 2 e 6
    for (int i = 0; i < tam; i++){
        // feito com a ajuda do gpt
        if (dia[i] < '2' || dia[i] > '6'){
            return 0;
        }
        // evitar que o usuário digitei dois dias repetidos
        for (int i = 0; i < tam; i++){
            if (dia[i] == dia[i + 1]){
                cont++;
            }
            if (cont >= 1){
                return 0;
            }
        }
    }
    return 1;
}
// Criar Id de forma nativa
// Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow
// Adapatado por Maria Eloisa e Matheus Diniz
int criar_id_h(void){
    // Abrir o arquivo
    FILE *arquivo = fopen("Horario.dat", "rb");
    if (arquivo == NULL){
        // caso o arquivo não exista começe com 1
        return 1;
        // Percorre o arquivo inteiro
        fseek(arquivo, 0, SEEK_END);
        // Para verificiar o tamanho do arquivo
        if ((long)ftell(arquivo) == 0){
            // caso o arquivo esteja vázio
            fclose(arquivo);
            return 1;
        }
    }
    else{
        // Posicione o ponteiro no início do último registro
        // Ver a última estrutura Adicionada

        // long adicionada para evitar problemas de conversão pelo sizeof, para um valor negativo, causando um estouro no fseek
        fseek(arquivo, -((long)sizeof(Horario)), SEEK_END);
        // Agora você pode ler o último registro usando fread

        Horario ultstruct;
        fread(&ultstruct, sizeof(Horario), 1, arquivo);

        // Obtenha o ID do último registro e incremente
        int id = ultstruct.id + 1;

        fclose(arquivo); // Feche o arquivo aqui
        return id;
    }
}

void gravar_h(Horario *h){
    FILE *fh; // File Horário
    fh = fopen("Horario.dat", "ab");
    if (fh == NULL){
        printf("Erro na recuperação dos dados do Horário!\n");
        return;
    }
    fwrite(h, sizeof(Horario), 1, fh);
    fclose(fh);
}

void exibir_h(Horario *h,Professor *prof){
    if ((h == NULL) || (h->status == 'I')){
        printf("\nEste Horário não foi cadastrado no sistema!\n");
    }
    else{
        printf("\n******** Dados do Horário ********\n");
        printf("\nNome do professor:%s\n",prof->nome);
        printf("CPF do Professor:%s\n", h->cpf);
        explicacao();
        printf("\n%s/%s/%s/%s", h->periodo, h->dia, h->turno, h->disciplina);
        printf("\nTurma:%s",h->turma);
        printf("\nid:%d\n", h->id);
        printf("\n");
    }
}

void lista_todos_h(void){
    FILE *fh;
    FILE *fp;
    Horario *h;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    h = (Horario *)malloc(sizeof(Horario));
    fp=fopen("Professor.dat","rb");
    fh = fopen("Horario.dat", "rb");
    if ((fh == NULL) || (fp==NULL)) {
        printf("Nenhum horário cadastrado ou professor!\n");
        return;
    }
    while (fread(h, sizeof(Horario), 1, fh)){
        if (h->status != 'I'){
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if ((prof->status!='I' && strcmp(prof->cpf,h->cpf)==0)){
                exibir_h(h,prof);
                }
            }
        }
    }
    fclose(fh);
    free(h);
    fclose(fp);
    free(prof);
}

// feito com a ajuda de marlison silva chat

void procura_h(int id){
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
    while (fread(h, sizeof(Horario), 1, fh)){
        if((h->status!='I') && (h->id==id)){
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,h->cpf)==0))){
                exibir_h(h,prof);
                cont++;
                }
            }
        }
    }if(!cont){
        printf("\nEssa disciplina não existe no sistema ou ainda não foi cadastrado!\n");
    }
    fclose(fh);
    free(h);
    free(prof);
    fclose(fp);
}

// feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz
void remover_h(int id){
    FILE *fh;
    Horario *h;
    h = (Horario *)malloc(sizeof(Horario));
    int cont=0;
    fh = fopen("Horario.dat", "r+b");
    if (fh == NULL){
        printf("\nNenhum horário cadastrado!\n");
        return;
    }
    while (fread(h, sizeof(Horario), 1, fh)){
        if ((h->id == id) && h->status == 'A'){
            cont++;
            h->status = 'I';
            fseek(fh, -1 * (long)sizeof(Horario), SEEK_CUR);
            fwrite(h, sizeof(Horario), 1, fh);
            printf("\nHorario excluído!\n");
            break; // Encerre o loop após a exclusão
        }
    }
    if (!cont){
        printf("\nHorario não encontrado!\n");
    }
    fclose(fh);
    free(h);
}
// fazer uma exibição de horários

void att_h(int id) {
    char situ = 'A';
    char resposta;
    FILE *fh, *fp;
    Horario *h;
    Professor *prof;
    prof = (Professor *)malloc(sizeof(Professor));
    h = (Horario *)malloc(sizeof(Horario));
    fp = fopen("Professor.dat", "rb");
    fh = fopen("Horario.dat", "r+b");
    int cont = 0;
    int esc = -1;
    if (fh == NULL || fp == NULL) {
        printf("Nenhum horário cadastrado ou professor!\n");
        return;
    }
    while (fread(h, sizeof(Horario), 1, fh)) {
        if (h->id == id && h->status == 'A') {
            while (fread(prof, sizeof(Professor), 1, fp)) {
                if (strcmp(prof->cpf, h->cpf) == 0) {
                    cont++;
                    do {
                        esc = -1;
                        system("clear||cls");
                        printf("========================================================\n");
                        printf("   *************** Atualizar Horario ***************    \n");
                        printf("                                                        \n");
                        printf("               O que deseja atualizar?                  \n");
                        printf("Turno[\033[34m1\033[0m] - Dia[\033[34m2\033[0m] - Disciplina[\033[34m3\033[0m] - Período[\033[34m4\033[0m] - Voltar[\033[34m0\033[0m]\n");
                        printf("                                                        \n");
                        printf("Dados cadastrados no sistema:\n");
                        printf("CPF do professor: %s\n", h->cpf);
                        printf("Disciplina: %s\n", h->disciplina);
                        printf("Horários: %s\n", h->periodo);
                        printf("Turno: %s\n", h->turno);
                        printf("Turma: %s\n", h->turma);
                        printf("Dia da semana: %s\n", h->dia);
                        printf("========================================================\n");
                        printf("\n");
                        printf("Qual opção deseja atualizar: ");
                        fflush(stdin);
                        scanf("%d", &esc);
                        limpar_buffer();
                        switch (esc) {
                            case 1:
                                ler_turno(h->turno);
                                printf("\nAlteração realizada!\n");
                                break;
                            case 2:
                                ler_dia(h->dia);
                                printf("\nAlteração realizada!\n");
                                break;
                            case 3:
                                printf("Professores cadastrados:\n\n");
                                relatorio_tabela_disciplinas(situ);
                                printf("\nDigite o CPF do professor:\n");
                                do {
                                    ler_cpf(h->cpf);
                                    if (verifica_existe_prof(h->cpf)) {
                                        printf("Nenhum professor foi cadastrado com esse CPF!\n");
                                        resposta = obter_resposta();
                                        if (resposta == 'N') {
                                            break;
                                        }
                                    } else {
                                        break;
                                    }
                                } while (1);
                                disciplinas();
                                do {
                                    ler_disciplinas(h->disciplina);
                                    if (valida_diciplina_professor(h->disciplina, h->cpf)) {
                                        printf("Esse professor não leciona essa disciplina!\n");
                                        resposta = obter_resposta();
                                        if (resposta == 'N') {
                                            break;
                                        }
                                    } else {
                                        break;
                                    }
                                } while (1);
                                printf("Alteração realizada!\n");
                                printf("Digite enter para continuar...");
                                getchar();
                                break;
                            case 4:
                                ler_periodo(h->periodo);
                                printf("\nAlteração realizada!\n");
                                break;
                            case 0:
                                break;
                            default:
                                printf("\nOpção Inválida!\n");
                                break;
                        }
                        fseek(fh, -1 * (long)sizeof(Horario), SEEK_CUR);
                        fwrite(h, sizeof(Horario), 1, fh);
                    } while (esc != 0);
                }
            }
        }break;
    }if (!cont) {
        printf("Horario não encontrado!\n");
    }
    fclose(fh);
    fclose(fp);
    free(h);
    free(prof);
}
