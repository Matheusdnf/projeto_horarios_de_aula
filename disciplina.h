#ifndef disciplina_h
#define disciplina_h
#include "professor.h"
//struct diciplina
typedef struct disciplina {
    char id;
    char cpf[12]; //referente ao cpf do professor
    char disciplina[4];
    char status;           //A-Ativo I-Inexistente 
    struct disciplina *prox;
} Disciplina;
//tela do módulo diciplina
void menu_disciplinas(void);
Disciplina* cadastrar_disciplinas(void);
void buscar_disciplinas(void);
void atualizar_disciplinas(void);
void excluir_disciplinas(void);
void relatorio_disciplinas(void);
//funções para validar as diciplinas
int valida_disciplinas(char *diciplina);
void ler_disciplinas(char *diciplina);
void disciplinas(void);
//função de criar id
int criar_id_d(void);
//gravação e exibição de dados
void gravardisciplinas(Disciplina* dic);
//funções do crud
void exibir_disciplinas(Disciplina* dic,Professor* prof);
void listar_todas_disciplinas(void);
void procura_disciplinas(int id);
void remover_disciplinas(int id);
void att_disciplinas(int id);
#endif