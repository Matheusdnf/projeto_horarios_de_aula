//struct horário
typedef struct horario {
    char periodo[7];
    char dia[7];
    char tempo[3];
    char diciplina[3];
} Horario;
//módulo horário de aula
void menu_horario(void);
void cadastrar_horario(void);
void buscar_horario(void);
void atualizar_horario(void);
void excluir_horario(void);
void relatorio_horario(void);
//validação dos horários
void ler_periodo(char* periodo); 
void ler_tempo(char* tempo);
void ler_dia(char* dia);
int valida_periodo(char* periodo); 
int valida_tempo(char* tempo);
int valida_dia(char* dia);