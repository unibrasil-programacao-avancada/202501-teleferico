#ifndef WARMUP_SOLVER_H
#define WARMUP_SOLVER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Função que resolve o problema do warmup
void solve_warmup(FILE* ptr_in_file);

// Função para checar a solução do warmup
int check_warmup_solution(const char* file_name, const char* warmup_instance);

// Função que calcula o número de viagens
int calculaViagem(int quantidadeDeAlunos, int qtdPessoaCabine);

#endif // WARMUP_SOLVER_H
