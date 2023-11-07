#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

void criarTarefa(Tarefa* tarefas, int* numTarefas) {
    if (*numTarefas >= MAX_TAREFAS) {
        printf("Número máximo de tarefas alcançado.\n");
        return;
    }

    Tarefa novaTarefa;

    printf("Digite a prioridade da tarefa (0-10): ");
    scanf("%d", &(novaTarefa.prioridade));

    printf("Digite a descrição da tarefa (até %d letras): ", MAX_DESCRICAO);
    scanf(" %[^\n]", novaTarefa.descricao);

    printf("Digite a categoria da tarefa (até %d letras): ", MAX_CATEGORIA);
    scanf(" %[^\n]", novaTarefa.categoria);

    tarefas[*numTarefas] = novaTarefa;
    (*numTarefas)++;
}

void deletarTarefa(Tarefa* tarefas, int* numTarefas, int posicao) {
    if (posicao < 0 || posicao >= *numTarefas) {
        printf("Posição inválida.\n");
        return;
    }

    for (int i = posicao; i < *numTarefas - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*numTarefas)--;
}

void listarTarefas(const Tarefa* tarefas, int numTarefas) {
    if (numTarefas == 0) {
        printf("Não existem tarefas cadastradas.\n");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Descrição: %s\n", tarefas[i].descricao);
        printf("Categoria: %s\n", tarefas[i].categoria);
        printf("------------------------------\n");
    }
}

void salvarTarefas(const Tarefa* tarefas, int numTarefas, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(tarefas, sizeof(Tarefa), numTarefas, arquivo);
    fclose(arquivo);

    printf("Tarefas salvas com sucesso no arquivo %s.\n", nomeArquivo);
}

void carregarTarefas(Tarefa* tarefas, int* numTarefas, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo para leitura.\n");
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long fileSize = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    int numTarefasArquivo = fileSize / sizeof(Tarefa);
    *numTarefas = numTarefasArquivo;

    fread(tarefas, sizeof(Tarefa), numTarefasArquivo, arquivo);
    fclose(arquivo);

    printf("Tarefas carregadas com sucesso do arquivo %s.\n", nomeArquivo);
}

void filtrarPrioridade(const Tarefa* tarefas, int numTarefas) {
    int valorPrioridade;
    printf("Digite a prioridade que deseja filtrar (0-10): ");
    scanf("%d", &valorPrioridade);

    printf("Tarefas com prioridade %d:\n", valorPrioridade);
    printf("------------------------------\n");

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == valorPrioridade) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("------------------------------\n");
        }
    }

void alterarTarefa(Tarefa* tarefas, int posicao) {
    if (posicao < 0 || posicao >= MAX_TAREFAS) {
        printf("Posição inválida.\n");
        return;
    }

    printf("Digite a prioridade da tarefa (0-10): ");
    scanf("%d", &(tarefas[posicao].prioridade));

    printf("Digite a descrição da tarefa (até %d letras): ", MAX_DESCRICAO);
    scanf(" %[^\n]", tarefas[posicao].descricao);

    printf("Digite a categoria da tarefa (até %d letras): ", MAX_CATEGORIA);
    scanf(" %[^\n]", tarefas[posicao].categoria);
}

void filtrarPrioridade(const Tarefa* tarefas, int numTarefas) {
    int prioridadeEscolhida;
    printf("Digite a prioridade que deseja filtrar (0-10): ");
    scanf("%d", &prioridadeEscolhida);

    printf("Tarefas com prioridade %d:\n", prioridadeEscolhida);
    printf("------------------------------\n");

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeEscolhida) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("------------------------------\n");
        }
    }
}

void filtrarEstado(const Tarefa* tarefas, int numTarefas) {
    char estadoEscolhido[MAX_ESTADO];
    printf("Qual o estado da tarefa que deseja filtrar: ");
    scanf(" %[^\n]", estadoEscolhido);

    printf("Tarefas no estado %s:\n", estadoEscolhido);
    printf("------------------------------\n");

    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].estado, estadoEscolhido) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Estado: %s\n", tarefas[i].estado);
            printf("------------------------------\n");
        }
    }
}

