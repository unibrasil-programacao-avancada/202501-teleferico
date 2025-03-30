#include "../include/warmup_solver.h"

// Definição das constantes
#define OUTPUT_DIR "output/"         
#define SOLUTION_FILE "solution.txt"

void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {
    int quantidadeDeAlunos, qtdPessoaCabine, resultado;

    // Lendo os valores do arquivo de entrada
    if (fscanf(ptr_in_file, "%d %d", &qtdPessoaCabine, &quantidadeDeAlunos) != 2) {
        printf("Erro ao ler os valores do arquivo de entrada!\n");
        exit(1);
    }

    // Calculando a quantidade de viagens
    resultado = calculaViagem(quantidadeDeAlunos, qtdPessoaCabine);
    printf("Resultado calculado: %d\n", resultado);

    // Criando o arquivo de solução e escrevendo o resultado calculado
    FILE *fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        printf("Erro ao abrir o arquivo de solução '%s'\n", SOLUTION_FILE);
        exit(1);
    }
    fprintf(fwsolptr, "%d\n", resultado);
    fclose(fwsolptr);
}


int calculaViagem(int quantidadeDeAlunos, int qtdPessoaCabine) {
    int qtdViagem = 1;

    if (quantidadeDeAlunos < 1) {
        return 0;
    }

    while (quantidadeDeAlunos >= qtdPessoaCabine) {
        quantidadeDeAlunos ++;
        quantidadeDeAlunos -= qtdPessoaCabine; 
        qtdViagem++;
    }

    return qtdViagem;
}

int check_warmup_solution(const char* file_name, const char* warmup_instance) {
    FILE *fanswer, *fsolution;
    char answer_line[100], solution_line[100], answer_file[100];
    int is_correct = 1;

    answer_file[0] = '\0';
    strcat(answer_file, warmup_instance);
    strcat(answer_file, OUTPUT_DIR);
    strcat(answer_file, file_name);

    // Abrindo o arquivo de resposta (valor esperado)
    fanswer = fopen(answer_file, "r");
    if (fanswer == NULL) {
        printf("Arquivo '%s' não pode ser aberto\n", answer_file);
        exit(1);
    }

    // Abrindo o arquivo de solução (resultado calculado)
    fsolution = fopen(SOLUTION_FILE, "r");
    if (fsolution == NULL) {
        printf("Arquivo '%s' não pode ser aberto\n", SOLUTION_FILE);
        exit(1);
    }

    // Lendo a primeira linha de cada arquivo
    if (fgets(answer_line, 100, fanswer) && fgets(solution_line, 100, fsolution)) {
        // Remover quebra de linha, se houver
        size_t len = strlen(answer_line);
        if (len > 0 && answer_line[len-1] == '\n') answer_line[len-1] = '\0';
        len = strlen(solution_line);
        if (len > 0 && solution_line[len-1] == '\n') solution_line[len-1] = '\0';

        if (strcmp(answer_line, solution_line) != 0) {
            is_correct = 0;
        }
    } else {
        is_correct = 0;
    }

    fclose(fanswer);
    fclose(fsolution);

    return is_correct;
}
