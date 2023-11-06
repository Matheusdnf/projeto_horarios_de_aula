//struct de aluno
typedef struct aluno {
    char cpf[15];
    char nome[100];
    char telefone[15];
    char email[225];
    char status;    // M-Matriculado  I-inexistente
} Aluno;
//telas do módulo aluno
void menu_aluno(void);
Aluno* cadastrar_aluno(void);
void buscar_aluno(void);
void atualizar_aluno(void);
void excluir_aluno(void); 
void relatorio_aluno(void);
//gravação em arquivo
void gravar_aluno(Aluno* std);    
//funções do crud
void procura_aluno(char cpf[]);
void listar_todos_aluno(void);
void exibicao_alunos(Aluno* std);
void remover_aluno(char cpf[]);
void att_aluno(char cpf[]);