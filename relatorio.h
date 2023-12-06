#ifndef relatorio_h
#define relatorio_h
#include "aluno.h"
#include "horario.h"
#include "professor.h"
#include "diciplina.h"
#include "checagem.h"
#include "matricula.h"
#include "turma.h"
//telas do relatório
void tela_relatorio(void);
void relatorio_tudo(void);
void relatorio_filtro(void);
void tela_filtro_relatorio(void);
void escolha_relatorio(void);
void tela_relatorio_ordenado(void);
void relatorio_ordenado(void);
void teste(void);
void relatorio_tabela_aluno_por_turma(char *turma);
//relatório tabela
void relatorio_tabela_aluno(void);
void relatorio_tabela_professor(void);
void relatorio_tabela_diciplinas(void);
void relatorio_tabela_h(void);
void relatorio_tabela_matricula(void);
void relatorio_tabela_turmas(void);
//relatório com filtro 
void filtro_diciplina(void);
void filtro_diciplina(void);
void listar_professor_por_disciplina(char *diciplina);
void filtro_tempo_horario(void);
void listar_h_por_periodo(char *tempo);
void filtro_diasemana_horario(void);
void listar_h_pelo_diasemana(char *dia);
void listar_h_pelo_periodo(char *periodo);
void filtro_periodo_horario(void);
#endif  