//struct de aluno
typedef struct aluno {
    char cpf[15];
    char nome[100];
    char telefone[15];
    char email[225];
    char status;    // M-Matriculado N-Não encontrado I-inexistente
} Aluno;
//funções do módulo aluno
void menu_aluno(void);
Aluno* cadastrar_aluno(void);
void buscar_aluno(void);
void atualizar_aluno(void);
void excluir_aluno(void);
void relatorio_aluno(void);
