#include "global.h"    //incluede para deixar opc global 
#include "horario.h"
#include "valida.h"    //arquivos com as assinaturas das validações
#include "diciplina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menu_horario(void) {
    while (opc!=0){
        system("clear||cls");   
        Horario* h;
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
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                h=cadastrar_horario();
                gravar_h(h);
                break;
            case '2':
                buscar_horario();
                break;
            case '3':
                atualizar_horario();
                break;
            case '4':
                excluir_horario();
                break;
            case '5':
                relatorio_horario();
                break;
            case '0':
                opc=0;
                break;
            default:
                printf("Opção Inválida!\n");
                getchar(); printf("Digite enter para continuar...");getchar(); 
                break;
        }
    }
}

Horario* cadastrar_horario(void) {
    system("clear||cls");
    Horario* h;
    h=(Horario*)malloc(sizeof(Horario));
    printf("========================================================\n");
    printf(" **************** Cadastrar Horário ******************  \n\n");
    printf("                                                        \n");
    ler_periodo(h->periodo); 
    ler_tempo(h->tempo);
    ler_dia(h->dia);
    diciplinas();
    ler_diciplina(h->diciplina);
    h->id=criar_id_h();
    h->status='A';
    printf("                                                        \n");
    printf("Dados cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
    return h;
}

void buscar_horario(void) {
    system("clear||cls");
    int id=0;
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Pesquisar Horário *************   \n\n");
    printf("                                                        \n");
    printf("Informe o id do horário:");
    scanf("%d",&id);
    printf("\n");
    procura_horario(id);
    printf("                                                        \n");
    printf("========================================================\n");
    getchar();printf("Digite enter para continuar...");getchar();
}


void atualizar_horario(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Horário *************   \n\n");
    printf("                                                        \n");
    printf("Informe o id do horário:\n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void excluir_horario(void) {
    system("clear||cls");
    int id=0;
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Excluir Horário *************     \n\n");
    printf("                                                        \n");
    printf("Informe o id do horário:");
    scanf("%d",&id);
    getchar();
    remover_horario(id);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("Digite enter para continuar...");getchar(); 
}

void relatorio_horario(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf(" *************** Relatório dos Horários ************* \n\n");
    printf("                                                        \n");
    printf("(informar todos os horários cadastrado)\n");
    printf("                                                        \n");
    lista_todos_h();
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


//funções referente a validação dos horários
void ler_periodo(char* periodo){ 
    int n; 
    bool v=true,f=false;
    while (v){ 
        printf("Digite em que horários serão [1,2...6] horário\n");
        printf("Digite o periodo (só números):"); 
        scanf("%s",periodo);
        limpar_buffer();
        n=valida_periodo(periodo);
        if (n==1){ 
            printf("válido\n"); 
            v=f;
        }else if (n==0){ 
            printf("inválido\n"); 
        } 
    } 
}
void ler_tempo(char* tempo){ 
    int t; 
    bool v=true,f=false;
    while (v){ 
        printf("Escolha se será manhã,tarde ou noite\n");
        printf("Digite o tempo (M,T,N):"); 
        scanf("%s",tempo);
        limpar_buffer();
        t=valida_tempo(tempo);
        if (t==1){ 
            printf("válido\n");
            v=f; 
        }else if (t==0){ 
            printf("inválido\n"); 
            
        } 
    } 
}    
 

void ler_dia(char* dia){ 
    int d; 
    bool v=true,f=false;
    while (v){ 
        printf("Escolha se será: \n2-Segunda \n3-Terça \nAté 6-Sexta\n");
        printf("Digite o dia:"); 
        scanf("%s",dia);
        limpar_buffer();
        d=valida_dia(dia);
        if (d==1){ 
            printf("válido\n");
            v=f; 
        }else if (d==0){ 
            printf("inválido\n"); 
            
        } 
    } 
}    
 

int valida_periodo(char* periodo) {
    int tam = strlen(periodo);
    int cont=0;
    if (!(tam >= 1 && tam <= 6)) {
        return 0;
    }
    //evitar que o usuário digite dias que não estejam entre 1 e 6
    for (int i = 0; i < tam; i++) {
        //feito com a ajuda do gpt
        if (periodo[i] < '1' || periodo[i] > '6') {
            return 0;
        }
    //impedir que o usuário digite números repetidos
    for (int i=0 ; i<tam;i++){
        if(periodo[i]==periodo[i+1]){
            cont++;
        }
        if (cont>=1){
            return 0;
        }
    }
    }
    return 1;
}

int valida_tempo(char* tempo) {
    int tam = strlen(tempo);
    char *t[]={"M","T","N"};
    //impedir que o usário digite mais do que um caracter
    if (tam!=1){
        return 0;
    }
    // que o caracter digitado seja um dos presentes da lista
    for (int i=0 ; i<3;i++){
        if (strcmp(tempo, t[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int valida_dia(char* dia) {
    int tam = strlen(dia);
    int cont=0;
    if (!(tam >= 1 && tam <= 5)) {
        return 0;
    }
    //fazer com que o usuário só digite números entre 2 e 6
    for (int i = 0; i < tam; i++) {
        //feito com a ajuda do gpt
        if (dia[i] < '2' || dia[i] > '6') {
            return 0;
        }
    //evitar que o usuário digitei dois dias repetidos
    for (int i=0 ; i<tam;i++){
        if(dia[i]==dia[i+1]){
            cont++;
        }
        if (cont>=1){
            return 0;
        }
    }
    }
    return 1;
}
//Criar Id de forma nativa 
//Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow 
//Adapatado por Maria Eloisa e Matheus Diniz 
int criar_id_h(void) { 
  //Abrir o arquivo 
  FILE *arquivo = fopen("Horario.dat", "rb"); 
  if (arquivo == NULL){
    //caso o arquivo não exista começe com 1
    return 1;
  // Percorre o arquivo inteiro  
  fseek(arquivo, 0, SEEK_END);  
  //Para verificiar o tamanho do arquivo 
  if ((long)ftell(arquivo)==0){
    //caso o arquivo esteja vázio
    fclose(arquivo);
    return 1;
  }
  } else { 
    // Posicione o ponteiro no início do último registro 
    //Ver a última estrutura Adicionada 

    //long adicionada para evitar problemas de conversão pelo sizeof, para um valor negativo, causando um estouro no fseek
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
 

void gravar_h(Horario* h){
    FILE* fh;  //File Horário
    fh=fopen("Horario.dat","ab");
    if (fh==NULL){
        printf("Erro na recuperação dos dados do Horário!\n");
        exit(1);
    }
    fwrite(h,sizeof(Horario),1,fh);
    fclose(fh);
}

void exibir_h(Horario* h){
    char estado[16];
    if ((h==NULL) || (h->status=='I')){
        printf("\nEste Horário não foi cadastrado no sistema!\n");
    }else{
        printf("********Dados do Horário ********");
        printf("\nPeriodo:%s\n",h->periodo);
        printf("Dia:%s\n",h->dia);
        printf("Tempo:%s\n",h->tempo);
        printf("Diciplina:%s\n",h->diciplina);
        printf("id:%d\n",h->id);
        printf("\n");
        if(h->status=='A'){
            strcpy(estado,"Horário Ativo");
        }else if(h->status=='N'){
            strcpy(estado,"Não Encontrado");
        }else{
            strcpy(estado,"Fechado");
        }
    }
}

void lista_todos_h(void){
    FILE* fh;
    Horario* h;
    h=(Horario*)malloc(sizeof(Horario));
    fh=fopen("Horario.dat","rb");
    if (fh==NULL){
        printf("Nenhum horário cadastrado!\n");
    }
    while(fread(h,sizeof(Horario),1,fh)){
        if (h->status!='I'){
            exibir_h(h);
        }
    }
    fclose(fh);
    free(h);
}

//feito com a ajuda de marlison silva chat 

void procura_horario(int id) {
    FILE* fh;
    Horario* h;
    h=(Horario*)malloc(sizeof(Horario));
    fh=fopen("Horario.dat","rb");
    if (fh == NULL)  {
    printf("Horário não encontrado!\n");
        return;
    }
    while(fread(h, sizeof(Horario), 1, fh)) {
        if ((h->id == id) && (h->status)) {
            exibir_h(h);
        }
    }
    fclose(fh);
    free(h);
}

//feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz
void remover_horario(int id) {
    FILE* fh;
    Horario *h;
    h=(Horario*)malloc(sizeof(Horario));
    int encontra = 0;
    fh = fopen("Horario.dat", "r+b");
    if (fh == NULL) {
        printf("\nNenhum horário cadastrado!\n");
        return;
    }
    while (fread(h, sizeof(Horario), 1, fh)) {
        if ((h->id == id) && h->status == 'A') {
            encontra = 1;
            h->status = 'I';
            fseek(fh, -1 * (long)sizeof(Horario), SEEK_CUR);
            fwrite(h, sizeof(Horario), 1, fh);
            printf("\nHorario excluído!\n");
            break; // Encerre o loop após a exclusão
        }
    }
    if (!encontra) {
        printf("\nHorario não encontrado!\n");
    }
    fclose(fh);
}
//fazer uma exibição de horários 

void att_h(int id){
    FILE* fh;
    Horario *h;
    int encontra=0;
    int esc;
    h=(Horario*)malloc(sizeof(Horario));
    fh=fopen("Horario.dat","r+b");
    if (fh == NULL) {
    printf("\tNenhum horário foi cadastrado!\n");
        return;
    }
    while (fread(h, sizeof(Horario), 1, fh)) {
        if ((h->id == id) && h->status == 'A') {
        encontra=1;  
            while (esc!=0){
            system("clear||cls");
            printf("========================================================\n");
            printf("   *************** Atualizar Horario ***************    \n");
            printf("                                                        \n");
            printf("               o que deseja atualizar?                  \n");
            printf("          Tempo[\033[31m1\033[0m] - Dia[\033[31m2\033[0m] - Disciplina[\033[31m3\033[0m] - Período[\033[31m4\033[0m] - Voltar[\033[31m0\033[0m]\n");
            printf("                                                        \n");
            printf("Dados cadastrados no sistema:\n");
            printf("\nNome do Horario:%s",h->diciplina);
            printf("CPF Do Horario:%s\n",h->dia);
            printf("Email:%s\n",h->tempo);
            printf("Telefone:%s\n",h->periodo);
            printf("========================================================\n");
            printf("\n");
            printf("Qual opção deseja atualizar:");
            scanf("%d",&esc);
            fflush(stdin);
            switch (esc) { 
                case 1:
                    ler_diciplina(h->diciplina);
                    printf("\nAlteração realizada!\n");
                    printf("\nDigite enter para continuar...");getchar();
                    break;
                case 2:
                    ler_tempo(h->tempo);
                    printf("\nAlteração realizada!\n");
                    printf("\nDigite enter para continuar...");getchar();
                    break;
                case 3:
                    ler_dia(h->dia);
                    printf("\nAlteração realizada!\n");
                    printf("\nDigite enter para continuar...");getchar();
                    break;
                case 4:
                    ler_periodo(h->periodo);
                    printf("\nAlteração realizada!\n");
                    printf("\nDigite enter para continuar...");getchar();
                    break;
                case 0:
                    esc=0;
                    break;
                default:
                    printf("\nOpção Inválida!\n");
                    printf("Digite enter para continuar...");getchar(); 
                    break;
            }
                fseek(fh, -1 * (long)sizeof(Horario), SEEK_CUR);
                fwrite(h, sizeof(Horario), 1, fh);       
            }break;
        }
        }
        if (!encontra) {
            printf("Horario não encontrado!\n");
    } 
    fclose(fh);
    free(h);
}