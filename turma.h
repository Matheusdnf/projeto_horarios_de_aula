//definição estrutura dos alunos
typedef struct turma{
    char cod [6];
    char nome[50];
    char status;
}Turma;
void menu_turma(void);
//telas crud
Turma *cadastrar_turma(void);
void buscar_turma(void);
void atualizar_turma(void);
void excluir_turma();
void relatorio_turma(void);
//funções de ação dos crud
void gravar_turma(Turma *t);
void exibicao_turma(Turma *t);
void listar_todas_turma(void);
void procura_turma(char *cod);
void remover_turma(char *cod);
void att_turma(char *cod);







