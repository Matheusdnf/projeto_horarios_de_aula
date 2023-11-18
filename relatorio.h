#ifndef relatorio_h
#define relatorio_h
#include "aluno.h"
#include "horario.h"
#include "professor.h"
#include "diciplina.h"
#include "checagem.h"
void tela_relatorio(void);
void relatorio_tudo(void);
void formato_exibido_a(Aluno *std);
void relatorio_tabela_aluno(void);
void formato_exibido_p(Professor *prof);
void relatorio_tabela_professor(void);
void formato_exibido_diciplinas(Diciplina *dic);
void relatorio_tabela_diciplinas(void);
void relatorio_tabela_h(void);
void formato_exibido_h(Horario *h);
void listar_professor_por_disciplina(char *diciplina);
void algo(void);
#endif  