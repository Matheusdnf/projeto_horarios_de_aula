#include "global.h" //incluede para deixar opc global 
#include "diciplina.h"
#include "valida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void menu_diciplina(void) {
    while (opc!=0){
        system("clear||cls");   
        Diciplina* dic;
        printf("\n");
        printf("===========================================================\n");
        printf("     ****************  Menu Diciplina ******************       \n");
        printf("          1 - Cadastrar Diciplina                          \n");
        printf("          2 - Pesquisar Diciplina                          \n");
        printf("          3 - Atualizar informações da Diciplina           \n");
        printf("          4 - Excluir Diciplina                            \n");
        printf("          5 - Relatório das Diciplinas                     \n");
        printf("          0 - Voltar                                       \n");
        printf("===========================================================\n");
        printf("\n");
        printf("Escolha uma das opções:");
        scanf("%s",&opc);
        switch (opc){
            case '1':
                dic=cadastrar_diciplina();
                gravardiciplina(dic);
                break;
            case '2':
                buscar_diciplina();
                break;
            case '3':
                atualizar_diciplina();
                break;
            case '4':
                excluir_diciplina();
                break;
            case '5':
                relatorio_diciplina();
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


Diciplina* cadastrar_diciplina(void) {
    system("clear||cls");   
    Diciplina* dic;
    dic=(Diciplina*)malloc(sizeof(Diciplina));
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Cadastrar Diciplina *************   \n\n");
    printf("                                                        \n");
    printf("Pode ser 1 ou 2 diciplinas\n"); 
    diciplinas();
    ler_diciplina(dic->diciplina);
    printf("Digite o nome do professor\n");
    ler_nome(dic->nome);
    dic->id=criar_id_d();
    dic->status='A';
    printf("                                                        \n");
    printf("Dados cadastrados!\n");
    printf("========================================================\n");
    printf("\n");
    printf("Digite enter para continuar...");getchar(); //para aparecer o menu e ele não sair rapidamente
    return dic;
}

void buscar_diciplina(void) {
    system("clear||cls");
    int id=0;
    printf("\n");  
    printf("========================================================\n");
    printf("    *************** Pesquisar Diciplina *************     \n\n");
    printf("                                                        \n");
    printf("Informe o id da diciplina:");
    scanf("%d",&id);
    procura_diciplina(id);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 

}

void atualizar_diciplina(void) {
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf("    *************** Atualizar Diciplina *************   \n\n");
    printf("                                                        \n");
    printf("            Informe a diciplina:                        \n");
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}

void excluir_diciplina(void) {
    system("clear||cls");
    printf("\n");
    int id=0;
    printf("========================================================\n");
    printf("    *************** Excluir Diciplina *************     \n\n");
    printf("                                                        \n");
    printf("Informe o id da diciplina:");
    scanf("%d",&id);
    remover_diciplina(id);
    printf("                                                        \n");
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void relatorio_diciplina(void){
    system("clear||cls");
    printf("\n");
    printf("========================================================\n");
    printf(" *************** Relatório Das Diciplinas ************* \n\n");
    printf("                                                        \n");
    printf("(informar todas as diciplinas cadastrado)               \n");
    printf("                                                        \n");
    listar_todas_diciplina();
    printf("========================================================\n");
    printf("\n");
    getchar(); printf("Digite enter para continuar...");getchar(); 
}


void diciplinas(void) {
    printf("\n");
    printf("P-Português\n");
    printf("I-Inglês\n");
    printf("E-Espanhol\n");
    printf("A-Artes\n");
    printf("H-História\n");
    printf("G-Geografia\n");
    printf("L-Literatura\n");
    printf("L-Filosofia\n");
    printf("S-Sociologia\n");
    printf("M-Matemática\n");
    printf("B-Biologia\n");
    printf("Q-Química\n");
    printf("F-Física\n\n");
}

//funções para a validação da diciplina
void ler_diciplina(char *diciplina) {
    int t;
    bool v=true,f=false;
    while (v) {
        fflush(stdin);
        printf("Digite a disciplina (somente maiúsculas):");
        fgets(diciplina, 3 , stdin);
        fflush(stdin);
        t = valida_diciplina(diciplina);
        if (t == 1) {
            printf("válido\n");
            v = f; // Saia do loop quando a disciplina for válida
        } else if (t == 0) {
            printf("inválido\n");
        }
    }
}

int valida_diciplina(char *diciplina) {
    int tam = strlen(diciplina);
    //Só é permitidos 1 ou 2 matérias por vez
    //string que contem todas as iniciais referentes as diciplinas
    if (tam != 2){
        return 0;
    }
    char *materia[]={
    "P","I","E","A","H",
    "G","L","O","S",
    "M","B","Q","F",};
    for (int i=0 ; i<13;i++){
        //compara se ambos os caracteres digitados estão presente no que foi digitado
        if (strncmp(diciplina, materia[i], 2) == 0 || strncmp(diciplina, materia[i], 1) == 0) {  
            return 1;
        }
    }
    //verificar a questão dos espaços e a ocorrência de números
    for (int i = 0; i < tam; i++) {
        if (!isalpha(diciplina[i]) && !isspace(diciplina[i])) {
            return 0;
        }
    }
    return 1;
}

//Criar Id de forma nativa 
//Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow 
//Adapatado por Maria Eloisa e Matheus Diniz 
int criar_id_d(void) { 
  //Abrir o arquivo 
  FILE *arquivo = fopen("Diciplina.dat", "rb"); 
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
    fseek(arquivo, -((long)sizeof(Diciplina)), SEEK_END); 
    // Agora você pode ler o último registro usando fread 
     
    Diciplina ultstruct; 
    fread(&ultstruct, sizeof(Diciplina), 1, arquivo); 
   
    // Obtenha o ID do último registro e incremente 
    int id = ultstruct.id + 1; 
 
    fclose(arquivo); // Feche o arquivo aqui 
    return id; 
  } 
} 

void gravardiciplina(Diciplina* dic){
    FILE* fd;  //File Diciplina
    fd=fopen("Diciplina.dat","ab");
    if (fd==NULL){
        printf("Erro na recuperação dos dados da Diciplinas!\n");
    }
    fwrite(dic,sizeof(Diciplina),1,fd);
    fclose(fd);
}

void exibir_diciplinas(Diciplina* dic){
    char estado[16];
    if ((dic==NULL) || (dic->status=='I')){
        printf("\nEsta Diciplinas não foi cadastrada no sistema!\n");
    }else{
        printf("\n");
        printf(" ********Informações da diciplina********");
        printf("\nNome do Professor:%s",dic->nome);
        printf("Nome da diciplina:%s\n",dic->diciplina);
        printf("Id da diciplina:%d\n",dic->id);
        printf("\n");
        if(dic->status=='A'){
            strcpy(estado,"Diciplina Ativa");
        }else if(dic->status=='I'){
            strcpy(estado,"Fechada");
        }
    }
}

void listar_todas_diciplina(void){
    FILE* fd;
    Diciplina* dic;
    dic=(Diciplina*)malloc(sizeof(Diciplina));
    fd=fopen("Diciplina.dat","rb");
    if (fd==NULL){
        printf("Nenhuma diciplina cadastrada!\n");
    }
    while(fread(dic,sizeof(Diciplina),1,fd)){
        if (dic->status!='I'){
            exibir_diciplinas(dic);
        }
    }
    fclose(fd);
    free(dic);
}

//feito com a ajuda de marlison silva chat 

void procura_diciplina(int id) {
    FILE* fd;
    Diciplina* dic;
    dic=(Diciplina*)malloc(sizeof(Diciplina));
    fd=fopen("Diciplina.dat","rb");
    if (dic == NULL) {
    printf("\t Diciplina não encontrada!\n");
        return;
    }
    while(fread(dic, sizeof(Diciplina), 1, fd)) {
        if ((dic->id == id) && (dic->status)) {
            exibir_diciplinas(dic);
        }
    }
    fclose(fd);
    free(dic);
}

//feito com a ajuda de marlison silva chat gpt e adapatada por matheus diniz
void remover_diciplina(int id) {
    FILE* fd;
    Diciplina dic;
    int encontra = 0;
    fd = fopen("Diciplina.dat", "r+b");
    if (fd == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return;
    }
    while (fread(&dic, sizeof(Diciplina), 1, fd)) {
        if ((dic.id == id) && dic.status == 'A') {
            encontra = 1;
            dic.status = 'I';
            fseek(fd, -1 * (long)sizeof(Diciplina), SEEK_CUR);
            fwrite(&dic, sizeof(Diciplina), 1, fd);
            printf("\nDiciplina excluída!\n");
            break; // Encerre o loop após a exclusão
        }
    }
    if (!encontra) {
        printf("\nDiciplina não encontrada!\n");
    }
    fclose(fd);
}