#include "valida.h"
#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void menu_disciplinas(void){
    //opc -1 para ela poder ser atualiza pelo usuário quando vai navegando
    //impede que o programa entre em alguma opção que não deveria
    int opc=-1;
    do{
        opc=-1;
        system("clear||cls");
        Disciplina *dic;
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Disciplina ******************   \n");
        printf("          1 - Cadastrar Disciplina                          \n");
        printf("          2 - Pesquisar Disciplina                          \n");
        printf("          3 - Atualizar informações da Disciplina           \n");
        printf("          4 - Excluir Disciplina                            \n");
        printf("          5 - Relatório das Disciplina                     \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\nDigite o que deseja fazer: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                dic = cadastrar_disciplinas();
                //condição realizada para quando o cadastrado do aluno não quiser ser feito
                //ou por não atender alguma opção do usuário
                if (dic == NULL){
                    break;
                }
                gravardisciplinas(dic);
                break;
            case 2:
                buscar_disciplinas();
                break;
            case 3:
                atualizar_disciplinas();
                break;
            case 4:
                excluir_disciplinas();
                break;
            case 5:
                relatorio_disciplinas();
                break;
            case 0:
                break;
            default:
                printf("\nOpção Inválida!\n");
                printf("Digite enter para continuar...");
                getchar();
                getchar();
                getchar();
                break;
        }
    } while (opc != 0);
}

Disciplina *cadastrar_disciplinas(void){
    system("clear||cls");
    Disciplina *dic;
    dic = (Disciplina *)malloc(sizeof(Disciplina));
    // verificar se algum professor já foi cadastrado no sistema
    printf("========================================================\n");
    printf("    *************** Cadastrar Disciplina *************   \n\n");
    printf("                                                        \n");
    FILE *fp;
    fp = fopen("Professor.dat", "rb");
    if (fp == NULL){
        printf("Nenhum professor foi cadastrado!\n");
        printf("Digite enter para continuar...");
        getchar();
        getchar();
        return NULL;
    }
    //fazer validação que verifica se já existe cpf no de disciplina
    printf("Dados do professores já cadastrados:\n");
    listar_todos_professor_alt();
    printf("\n\n");
     do{
        //leitura do cpf
        ler_cpf(dic->cpf);
        if((verifica_existe_prof(dic->cpf)) || (verifica_professor_com_disciplina(dic->cpf))){
            printf("Esse professor não foi cadastrado no sistema ou já tem alguma disciplina atrelada!\n");
            //caso já o usuário vai ter a chance de tentar novamente
            char resposta=obter_resposta();
            //Caso ele digite algo diferente de "S" no caso "N"
            //quer dizer que ele não quer mais digitar o cpf e irá retornar NULL
            if (resposta == 'N') {
                fclose(fp);
                free(dic);
                return NULL;  
            }
            //Caso o aluno com o cpf em questão não estiver cadastrado o loop se encerará
        } else {
            break;  
        }
    } while (1);
    printf("Pode ser 1 ou 2 disciplinas\n");
    disciplinas();
    ler_disciplinas(dic->disciplina);
    dic->status = 'A';
    dic->id = criar_id_d();
    printf("                                                        \n");
    printf("Disciplina cadastrada!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar(); // para aparecer o menu e ele não sair rapidamente
    return dic;
    free(dic);
    fclose(fp);
}

void buscar_disciplinas(void){
    system("clear||cls");
    int id = 0;
    printf("========================================================\n");
    printf("    *************** Pesquisar Disciplina *************     \n\n");
    printf("                                                        \n");
    printf("Informe o id da Disciplina:");
    scanf("%d", &id);
    limpar_buffer();
    procura_disciplinas(id);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void atualizar_disciplinas(void){
    system("clear||cls");
    int id = 0;
    printf("========================================================\n");
    printf("    *************** Atualizar Disciplina *************   \n\n");
    printf("                                                        \n");
    printf("Informe o id da Disciplina:");
    scanf("%d", &id);
    limpar_buffer();
    att_disciplinas(id);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void excluir_disciplinas(void){
    system("clear||cls");
    int id = 0;
    char cpf[12];
    int esc=2;
    printf("========================================================\n");
    printf("    *************** Excluir Disciplina *************     \n\n");
    printf("                                                        \n");
    printf("Informe o id da Disciplina:");
    scanf("%d", &id);
    limpar_buffer();
    procura_disciplinas(id);
    if (decidir_excluir()){
        //função modificada para funcionar tanto em disciplinas quanto em professores
        remover_disciplinas(id,cpf,esc);
    }
    else{
        return;
    }
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");
    getchar();
}

void relatorio_disciplinas(void){
    system("clear||cls");
    printf("========================================================\n");
    printf(" *************** Relatório Das Disciplinas ************* \n\n");
    printf("                                                        \n");
    printf("\x1B[34m(informar todos as disciplinas cadastradas)\x1B[0m \n");
    printf("                                                        \n");
    listar_todas_disciplinas();
    printf("========================================================\n");
    printf("\n");
    getchar();
    printf("Digite enter para continuar...");
    getchar();
}

void disciplinas(void){
    printf("\n");
    printf("P-Português\n");
    printf("I-Inglês\n");
    printf("E-Espanhol\n");
    printf("A-Artes\n");
    printf("H-História\n");
    printf("G-Geografia\n");
    printf("L-Literatura\n");
    printf("O-Filosofia\n");
    printf("S-Sociologia\n");
    printf("M-Matemática\n");
    printf("B-Biologia\n");
    printf("Q-Química\n");
    printf("F-Física\n\n");
}

// funções para a validação da disciplina
void ler_disciplinas(char *disciplina){
    int t;
    do{
        fflush(stdin);
        printf("Digite a matéria ou sua sigla caso seja mais que uma:");
        fgets(disciplina, 4, stdin);
        //remover o //n, função pega de @Lleusxam
        disciplina[strlen(disciplina)-1]=0;
        t = valida_disciplinas(disciplina);
        if (t == 0) {
            printf("Disciplina Invalida!\n");
        }
  } while (t != 1);
}

int valida_disciplinas(char *disciplina){
    // feito com ajuda de maria eloisa
    int tam = strlen(disciplina);
    // Só é permitidos 1 ou 2 matérias por vez
    // string que contem todas as iniciais referentes as disciplinas
    if ((tam != 3) && (tam != 1)){
        return 0;
    }
    // não permitir que o usuário digite duas letras iguais
    else if (tam == 2 && disciplina[0] == disciplina[1]){
        return 0;
    }
    letra_maiuscula(disciplina);
    int cont = 0;
    // permitir que o usuário digite a letra da maneira que preferir
    // apos isso chamara essa função que tratara os dados
    
    // um array com as iniciais das letras das matérias
    char materia[] = "PIEAHGLOSMBQF";
    // caso o usuário digitar só uma letra cairá nesse if
    if (tam == 1){
        // rodará 13 vezes que é referente a quantidade de disciplinas
        for (int i = 0; i < 13; i++){
            // disciplina [0] referindo ao primeiro índice
            if (disciplina[0] == materia[i]){
                return 1;
            }
        }
    }
    // caso o usuário digitar duas matérias
    else if (tam == 2){
        // esse for vai rodar 2 vezes para pegar ambas as posições
        for (int i = 0; i < 2; i++){
            // rodará 13 vezes que é referente a quantidade de disciplinas
            for (int j = 0; j < 13; j++){
                if (disciplina[i] == materia[j]){
                    cont++;
                }
            }
        }
        // para poder rodar duas vezes e conferir ambos os caracter
        if (cont != 2){
            return 0;
        }
        else{
            return 1;
        }
    }
    // verificar a questão dos espaços e a ocorrência de números
    for (int i = 0; i < tam; i++){
        if (!isalpha(disciplina[i]) && !isspace(disciplina[i])){
            return 0;
        }
    }
    return 0;
}

// Criar Id de forma nativa
// Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow
// Adapatado por Maria Eloisa e Matheus Diniz
int criar_id_d(void){
    // Abrir o arquivo
    FILE *arquivo = fopen("Disciplina.dat", "rb");
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
        fseek(arquivo, -((long)sizeof(Disciplina)), SEEK_END);
        // Agora você pode ler o último registro usando fread

        Disciplina ultstruct;
        fread(&ultstruct, sizeof(Disciplina), 1, arquivo);

        // Obtenha o ID do último registro e incremente
        int id = ultstruct.id + 1;

        fclose(arquivo); // Feche o arquivo aqui
        return id;
    }
}

void gravardisciplinas(Disciplina *dic){
    FILE *fd; // File Disciplina
    fd = fopen("Disciplina.dat", "ab");
    if (fd == NULL){
        printf("Erro na recuperação dos dados da Disciplinas!\n");
        return;
    }
    fwrite(dic, sizeof(Disciplina), 1, fd);
    fclose(fd);
}

void exibir_disciplinas(Disciplina *dic,Professor* prof){
    if ((dic == NULL) || (dic->status == 'I')){
        printf("\nEsta Disciplinas não foi cadastrada no sistema!\n");
    }
    else{
        printf("\n ********Informações da Disciplina********");
        printf("\nNome do professor:%s\n",prof->nome);
        printf("CPF do Professor:%s\n", dic->cpf);
        printf("Nome da Disciplina:%s\n", dic->disciplina);
        printf("Id da Disciplina:%d\n", dic->id);
        printf("\n");
    }
}

void listar_todas_disciplinas(void){
    FILE *fd;
    FILE *fp;
    Disciplina *dic;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    dic = (Disciplina *)malloc(sizeof(Disciplina));
    fd = fopen("Disciplina.dat", "rb");
    fp=fopen("Professor.dat","rb");
    if ((fd == NULL) || (fp==NULL)){
        printf("Nenhuma Disciplina ou professor cadastrado!\n");
        return;
    }
    while (fread(dic, sizeof(Disciplina), 1, fd)){
        if ((dic->status != 'I')){
            rewind(fp);
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,dic->cpf)==0))){
                    exibir_disciplinas(dic,prof);
                }
            }
        }
    }
    fclose(fd);
    free(dic);
    fclose(fp);
    free(prof);
}

//feito com a ajuda de marlison silva chat

void procura_disciplinas(int id){
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
        printf("\nNenhuma Disciplina cadastrada ou nenhum professor no sistema!\n");
        return;
    }
    //irá realizar a leitura de ambos os arquivos
    while (fread(dic, sizeof(Disciplina), 1, fd)){
        if ((dic->status != 'I') && (dic->id==id)){
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,dic->cpf)==0))){
                    exibir_disciplinas(dic,prof);
                    cont++;
                }
            }
        }
    }if(!cont){
        printf("\nEssa disciplina não existe no sistema ou ainda não foi cadastrada!\n");
    }
    fclose(fd);
    free(dic);
    free(prof);
    fclose(fp);
}

//função modificada para funcionar no módulo de professores e disciplinas
void remover_disciplinas(int id, char cpf[], char esc) {
    FILE *fd;
    Disciplina *dic;
    dic = (Disciplina *)malloc(sizeof(Disciplina));
    fd = fopen("Disciplina.dat", "r+b");
    int cont = 0;
    if (fd == NULL) {
        printf("\nNenhuma Disciplina cadastrada!\n");
        return;
    }
    //nessa situação é para quando excluir um professor excluir a disciplina
    if (esc == 1) {
        while (fread(dic, sizeof(Disciplina), 1, fd)) {
            if (strcmp(dic->cpf, cpf) == 0 && dic->status == 'A') {
                cont++;
                dic->status = 'I';
                fseek(fd, -1 * (long)sizeof(Disciplina), SEEK_CUR);
                fwrite(dic, sizeof(Disciplina), 1, fd);
                printf("\nDisciplina excluída!\n");
                break;
            }
        }
    //excluir apenas a disciplina não excluindo o cadastro do professor
    } else if (esc == 2) {
        while (fread(dic, sizeof(Disciplina), 1, fd)) {
            if (dic->id == id && dic->status == 'A') {
                cont++;
                dic->status = 'I';
                fseek(fd, -1 * (long)sizeof(Disciplina), SEEK_CUR);
                fwrite(dic, sizeof(Disciplina), 1, fd);
                printf("\nDisciplina excluída!\n");
                break;
            }
        }
    }
    if (!cont) {
        printf("\nDisciplina não encontrada!\n");
    }
    fclose(fd);
    free(dic);
}

void att_disciplinas(int id){
    FILE *fd;
    FILE *fp;
    Disciplina *dic;
    Professor *prof;
    prof=(Professor*)malloc(sizeof(Professor));
    dic = (Disciplina *)malloc(sizeof(Disciplina));
    fd = fopen("Disciplina.dat", "r+b");
    fp=fopen("Professor.dat","rb");
    int esc=-1;
    int cont=0;
    if ((fd == NULL) || (fp==NULL)){
        printf("\nNenhuma Disciplina cadastrada ou nenhum professor cadastrado no sistema!\n");
        return;
    }
    while (fread(dic, sizeof(Disciplina), 1, fd)){
        if ((dic->id == id) && dic->status == 'A'){
            while(fread(prof, sizeof(Professor), 1, fp)){
                if (((strcmp(prof->cpf,dic->cpf)==0))){
                    cont++;
                    do{
                        esc=-1;
                        system("clear||cls");
                        printf("========================================================\n");
                        printf("   *************** Atualizar Disciplina ***************      \n");
                        printf("                                                        \n");
                        printf("               o que deseja atualizar?                  \n");
                        printf("              Disciplina[\033[34m1\033[0m] - Voltar[\033[34m0\033[0m]\n");
                        printf("                                                        \n");
                        printf("Dados cadastrados no sistema:\n");
                        printf("Nome do professor:%s",prof->nome);
                        printf("\nCPF do professor:%s", dic->cpf);
                        printf("\nNome da(s) Disciplina(s):%s\n", dic->disciplina);
                        printf("========================================================\n");
                        printf("\n");
                        printf("Qual opção deseja atualizar:");
                        fflush(stdin);
                        scanf("%d", &esc);
                        limpar_buffer();
                        switch (esc){
                            case 1:
                                disciplinas();
                                ler_disciplinas(dic->disciplina);
                                printf("Alteração realizada!\n");
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
                        fseek(fd, -1 * (long)sizeof(Disciplina), SEEK_CUR);
                        fwrite(dic, sizeof(Disciplina), 1, fd);
                    } while (esc != 0);
                }
            }break;
        }
    }if (!cont){
        printf("\nEssa disciplina não existe no sistema ou ainda não foi cadastrado!\n"); 
    }
    fclose(fd);
    free(dic);
    fclose(fp);
    free(prof);
}
