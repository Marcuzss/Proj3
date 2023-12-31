#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_DESCRICAO 300
#define MAX_CATEGORIA 100
#define MAX_ESTADO 100 
#define MAX_TAREFAS 100

typedef struct {
    int prioridade;
    char descricao[MAX_DESCRICAO];
    char categoria[MAX_CATEGORIA];
    char estado[MAX_ESTADO]; 
} Tarefa;

void criarTarefa(Tarefa* tarefas, int* numTarefas);
void deletarTarefa(Tarefa* tarefas, int* numTarefas, int posicao);
void listarTarefas(const Tarefa* tarefas, int numTarefas);
void salvarTarefas(const Tarefa* tarefas, int numTarefas, const char* nomeArquivo);
void carregarTarefas(Tarefa* tarefas, int* numTarefas, const char* nomeArquivo);
void alterarTarefa(Tarefa* tarefas, int posicao);
void filtrarPrioridade(const Tarefa* tarefas, int numTarefas); 
void exportarPrioridade(const Tarefa* tarefas, int numTarefas, int prioridadeEscolhida, const char* nomeArquivo);
void filtrarEstado(const Tarefa* tarefas, int numTarefas);
void filtrarCategoria(const Tarefa* tarefas, int numTarefas);
void exportarCategoria(const Tarefa* tarefas, int numTarefas, const char* categoriaEscolhida, const char* nomeArquivo);
void filtrarPrioridadeCategoria(const Tarefa* tarefas, int numTarefas, int prioridadeEscolhida, const char* categoriaEscolhida);
void exportarPrioridadeCategoria(const Tarefa* tarefas, int numTarefas, const char* nomeArquivo, int prioridade, const char* categoria);


#endif





