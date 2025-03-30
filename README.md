# Projeto 09 – Teleférico

## Problema

A turma da faculdade vai fazer uma excursão na serra, e todos os alunos e monitores irão utilizar um teleférico para subir até o pico de uma montanha. A cabine do teleférico tem uma capacidade máxima de **C** pessoas (alunos e monitores juntos) por viagem. Por questões de segurança, deve haver pelo menos um monitor junto com os alunos em cada viagem.

**Exemplo:**  
Se a cabine comporta **C = 10** pessoas e a turma possui **A = 20** alunos, os alunos podem realizar três viagens:
- **1ª viagem:** 8 alunos + 1 monitor  
- **2ª viagem:** 6 alunos + 1 monitor  
- **3ª viagem:** 6 alunos + 1 monitor  

**Entrada:**  
- Primeira linha: inteiro **C** (capacidade da cabine, 2 ≤ C ≤ 100).  
- Segunda linha: inteiro **A** (número total de alunos, 1 ≤ A ≤ 1000).

**Saída:**  
- Um número inteiro representando o número máximo de viagens necessárias para levar todos os alunos até o pico.

---

## Modelagem do Problema

### Variáveis
- **qtdPessoaCabine:** Capacidade máxima da cabine.
- **quantidadeDeAlunos:** Número total de alunos a serem transportados.
- **qtdViagem:** Contador que armazena o número de viagens necessárias.
- **resultado:** Resultado obtido pela função `calculaViagem`.

### Funções e Procedimentos
- **`int calculaViagem(int quantidadeDeAlunos, int qtdPessoaCabine)`**  
  Calcula o número de viagens necessárias para transportar todos os alunos.  
  *Lógica:* Enquanto o número de alunos for maior ou igual à capacidade da cabine, decrementa o total de alunos e incrementa o contador de viagens.

- **`void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance)`**  
  - Lê os dados de entrada do arquivo (capacidade da cabine e número de alunos).  
  - Calcula o número de viagens necessárias chamando `calculaViagem`.  
  - Escreve o resultado calculado no arquivo `solution.txt`.

- **`int check_warmup_solution(const char* file_name, const char* warmup_instance)`**  
  - Abre o arquivo de saída esperado (localizado em `warmup_instance/OUTPUT_DIR/file_name`) e o arquivo `solution.txt` gerado.  
  - Compara as linhas dos dois arquivos para validar se o resultado calculado está correto.

### Estrutura de Pastas

As instâncias de teste estão organizadas em pastas dentro do diretório da instância (ex.: `09-teleferico/input` e `09-teleferico/output`).

---

## Solução

O algoritmo implementado na função `calculaViagem` é simples:

```c
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
```

## Descrição da Solução

### Entrada:
São lidos os valores de `qtdPessoaCabine` e `quantidadeDeAlunos` do arquivo de entrada.

### Cálculo:
A função `calculaViagem` determina quantas viagens são necessárias, subtraindo a capacidade da cabine do total de alunos enquanto houver alunos suficientes, incrementando um contador de viagens.

### Saída:
O resultado é escrito no arquivo `solution.txt`.

### Validação:
A função `check_warmup_solution` compara o conteúdo de `solution.txt` (resultado calculado) com o conteúdo do arquivo de saída esperado (armazenado em `09-teleferico/output/instance_X`).

---

## Execução

### Compilação
Para compilar o projeto, abra um terminal na pasta raiz do projeto e execute:

```bash
gcc -Wall -Wextra -pedantic -o warmup warmup.c solver/warmup_solver.c -I warmup/include 
```

### Rodar o projeto
Depois de compilar, abra um terminal na pasta raiz do projeto e execute:

```bash
./warmup
```

## Desempenho
Após a execução dos testes, os resultados obtidos foram:

- **Total Success:** 39
- **Total Failures:** 0

Isso indica que a solução implementada passou em todas as instâncias de teste.

