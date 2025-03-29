#include "../include/warmup_solver.h"

// Definição das constantes
#define OUTPUT_DIR "output/"         
#define SOLUTION_FILE "solution.txt"


int calculaViagem(int quantidadeDeAlunos, int qtdPessoaCabine) {
    int qtdViagem = 1;

    if (quantidadeDeAlunos < 1) {
        return 0;
    }

    while (quantidadeDeAlunos >= qtdPessoaCabine) {
        quantidadeDeAlunos -= qtdPessoaCabine; 
        qtdViagem++;
    }

    return qtdViagem;
}


void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {
    FILE *fwsolptr;
    int quantidadeDeAlunos, qtdPessoaCabine, resultado;

    // Lendo os valores do arquivo de entrada
    if (fscanf(ptr_in_file, "%d %d",  &qtdPessoaCabine, &quantidadeDeAlunos) != 2) {
        printf("Erro ao ler os valores do arquivo de entrada!\n");
        exit(1);
    }

    // Calculando a quantidade de viagens
    resultado = calculaViagem(quantidadeDeAlunos, qtdPessoaCabine);

    // Criando o arquivo de solução
    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        printf("Erro ao abrir o arquivo de solução '%s'\n", SOLUTION_FILE);
        exit(1);
    }

    // Escrevendo o resultado no arquivo de solução
    fprintf(fwsolptr, "%d\n", resultado);

    fclose(fwsolptr);
}


int check_warmup_solution(const char* file_name, const char* warmup_instance) {

    FILE *fanswer, *fsolution;
    char answer_line[100], solution_line[100], answer_file[100];
    int is_correct = 1;

    answer_file[0] = '\0';
    strcat(answer_file, warmup_instance);
    strcat(answer_file, OUTPUT_DIR);
    strcat(answer_file, file_name);

    // Opening answer file
    fanswer = fopen(answer_file, "r");
    if (fanswer == NULL) {
        printf("File '%s' can't be opened\n", answer_file);
        exit(1);
    }

    // Opening solution file
    fsolution = fopen(SOLUTION_FILE, "r");
    if (fsolution == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Reading from the answer file and comparing with the solution file
    while (fgets(answer_line, 100, fanswer)) {

        fgets(solution_line, 100, fsolution);

        if (strcmp(answer_line, solution_line)) {
            is_correct = 0;
            break;
        }
    }

    fclose(fanswer);
    fclose(fsolution);

    return is_correct;
}
