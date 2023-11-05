//struct professor
typedef struct professor {
    char telefone[15];
    char nome[100];
    char cpf[15];
    char email[225];
    char status;           //A-Ativo I-Inexistente
} Professor;
//módulo professores
void menu_professor(void);
Professor* cadastrar_professor(void);
void buscar_professor(void);
void atualizar_professor(void);
void excluir_professor(void);
void relatorio_professor(void);
//gravar dados
void gravarprofessor(Professor* prof);
//funções crud
void listar_todos_professor(void);
void exicao_professores(Professor* prof);
void procura_professor(char cpf[]);
void remover_Professor(char cpf[]);
void att_professor(char cpf[]);
int verifica_existe_prof(char cpf[]);