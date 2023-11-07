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

    printf("Digite o estado da tarefa (até %d letras): ", MAX_ESTADO);
    scanf(" %[^\n]", novaTarefa.estado);

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
        printf("Estado: %s\n", tarefas[i].estado);
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

void exportarPrioridade(const Tarefa* tarefas, int numTarefas, int prioridadeEscolhida, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeEscolhida) {
            fprintf(arquivo, "%d, %s, %s, %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].estado, tarefas[i].descricao);
        }
    }

    fclose(arquivo);

    printf("Tarefas de prioridade %d exportadas com sucesso para o arquivo %s.\n", prioridadeEscolhida, nomeArquivo);
}

void filtrarCategoria(const Tarefa* tarefas, int numTarefas) {
    char categoriaEscolhida[MAX_CATEGORIA];
    printf("Digite a categoria que deseja filtrar: ");
    scanf(" %[^\n]", categoriaEscolhida);

    printf("Tarefas da categoria %s:\n", categoriaEscolhida);
    printf("------------------------------\n");

    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoriaEscolhida) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Estado: %s\n", tarefas[i].estado);
            printf("------------------------------\n");
        }
    }
}

void exportarCategoria(const Tarefa* tarefas, int numTarefas, const char* categoriaEscolhida, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoriaEscolhida) == 0) {
            fprintf(arquivo, "%d, %s, %s, %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].estado, tarefas[i].descricao);
        }
    }

    fclose(arquivo);

    printf("Tarefas da categoria %s exportadas com sucesso para o arquivo %s.\n", categoriaEscolhida, nomeArquivo);
}

void filtrarPrioridadeCategoria(const Tarefa* tarefas, int numTarefas, int prioridadeEscolhida, const char* categoriaEscolhida) {
    printf("Tarefas com prioridade %d e categoria %s:\n", prioridadeEscolhida, categoriaEscolhida);
    printf("------------------------------\n");

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeEscolhida && strcmp(tarefas[i].categoria, categoriaEscolhida) == 0) {
            printf("Tarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Descrição: %s\n", tarefas[i].descricao);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Estado: %s\n", tarefas[i].estado);
            printf("------------------------------\n");
        }
    }
}
