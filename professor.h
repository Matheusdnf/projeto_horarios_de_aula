#ifndef professor_h
#define professor_h
//struct professor
typedef struct professor {
    char cpf[12];
    char nome[100];
    char telefone[15];
    char email[225];
    char status;          //A-Ativo I-Inativo
    struct professor *prox;
} Professor;
//telas módulo professores
void menu_professor(void);
//cadatrar professor
Professor* cadastrar_professor(void);
void buscar_professor(void);
void atualizar_professor(void);
void excluir_professor(void);
void relatorio_professor(void);
//gravar dados
void gravar_professor(Professor* prof);
//funções crud
void listar_todos_professor(void);
void exibicao_professor(Professor* prof);
void procura_professor(char cpf[]);
void remover_Professor(char cpf[]);
void att_professor(char cpf[]);
#endif