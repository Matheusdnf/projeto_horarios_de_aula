#ifndef horario_h
#define horario_h
//struct horário
typedef struct horario {
    char id;
    char periodo[7];
    char dia[7];
    char tempo[3];
    char diciplina[3];
    char status;           //A-Ativo I-Inexistente N-Não encontrado
} Horario;
//telas horário de aula
void menu_horario(void);
Horario* cadastrar_horario(void);
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
//criação de id
int criar_id_h(void);
//gravar em arquivo
void gravar_h(Horario* h);
//função crud
void exibir_h(Horario* h);
void lista_todos_h(void);
void procura_h(int id);
void remover_h(int id);
void att_h(int id);
#endif