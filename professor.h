//struct professor
typedef struct professor {
    char telefone[15];
    char nome[100];
    char cpf[15];
    char email[225];
    char status;           //A-Ativo I-Inexistente N-Não encontrado
} Professor;
//módulo professores
void menu_professor(void);
Professor* cadastrar_professor(void);
void buscar_professor(void);
void atualizar_professor(void);
void excluir_professor(void);
void relatorio_professor(void);
void gravarprofessor(Professor* prof);
void exibir_professores(Professor* prof);