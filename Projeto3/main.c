//Marcus Vinicius Zelenato RA: 22.223.084-9

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main() {
    Tarefa tarefas[MAX_TAREFAS];
    int numTarefas = 0;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Criar tarefa\n");
        printf("2. Deletar tarefa\n");
        printf("3. Listar tarefas\n");
        printf("4. Salvar tarefas em arquivo\n");
        printf("5. Carregar tarefas do arquivo\n");
        printf("6. Alterar tarefa\n");
        printf("7. Filtrar tarefas por prioridade\n");
        printf("8. Filtrar tarefas por estado\n"); 
        printf("9. Filtrar tarefas por categoria\n"); 
        printf("10. Filtrar tarefas por prioridade e categoria\n");
        printf("11. Exportar tarefas por prioridade\n");
        printf("12. Exportar tarefas por categoria\n");
        printf("13. Exportar tarefas por prioridade e categoria\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        int opcao;
        scanf("%d", &opcao);

        if (opcao == 1) {
            criarTarefa(tarefas, &numTarefas);
        } else if (opcao == 2) {
            int posicao;
            printf("Digite a posição da tarefa a ser deletada: ");
            scanf("%d", &posicao);
            deletarTarefa(tarefas, &numTarefas, posicao - 1);
        } else if (opcao == 3) {
            listarTarefas(tarefas, numTarefas);
        } else if (opcao == 4) {
            char nomeArquivo[MAX_CATEGORIA];
            printf("Digite o nome do arquivo para salvar as tarefas: ");
            scanf("%s", nomeArquivo);
            salvarTarefas(tarefas, numTarefas, nomeArquivo);
        } else if (opcao == 5) {
            char nomeArquivo[MAX_CATEGORIA];
            printf("Digite o nome do arquivo para carregar as tarefas: ");
            scanf("%s", nomeArquivo);
            carregarTarefas(tarefas, &numTarefas, nomeArquivo);
        } else if (opcao == 6) {
            int posicao;
            printf("Digite a posição da tarefa a ser alterada: ");
            scanf("%d", &posicao);
            alterarTarefa(tarefas, posicao - 1);
        } else if (opcao == 7) {
            filtrarTarefasPorPrioridade(tarefas, numTarefas);
        } else if (opcao == 8) {
            filtrarTarefasPorEstado(tarefas, numTarefas);
        } else if (opcao == 9) {
            filtrarTarefasPorCategoria(tarefas, numTarefas);
        } else if (opcao == 10) {
            int prioridadeEscolhida;
            char categoriaEscolhida[MAX_CATEGORIA];
            printf("Digite a prioridade que deseja filtrar (0-10): ");
            scanf("%d", &prioridadeEscolhida);
            printf("Digite a categoria que deseja filtrar: ");
            scanf("%s", categoriaEscolhida);
            filtrarPrioridadeCategoria(const Tarefa* tarefas, int numTarefas, int prioridadeEscolhida, const char* categoriaEscolhida);
        } else if (opcao == 11) {
            // Add code to export tasks by priority
        } else if (opcao == 12) {
            // Add code to export tasks by category
        } else if (opcao == 13) {
            // Add code to export tasks by priority and category
        } else if (opcao == 0) {
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
         
    }
}


