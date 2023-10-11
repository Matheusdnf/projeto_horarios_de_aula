//struct professor
typedef struct professor {
    char telefone[15];
    char nome[100];
    char cpf[15];
    char email[225];
} Professor;
//módulo professores
void menu_professor(void);
void cadastrar_professor(void);
void buscar_professor(void);
void atualizar_professor(void);
void excluir_professor(void);
void relatorio_professor(void);