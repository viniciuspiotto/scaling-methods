# Trabalho de Métodos de Escalonamento

## Colaboradores

- [0xbhsu](https://github.com/0xbhsu)
- [viniciuspiotto](https://github.com/viniciuspiotto)
- [GrodriguesZR](https://github.com/GrodriguesZR)
- [LeonardoIX](https://github.com/LeonardoIX)

## Descrição

No início do programa, o usuário deve escolher qual método de escalonamento será utilizado (FCFS, SJF ou Round-Robin). O programa deve utilizar as estruturas de dados pilha, fila e lista (por alocação dinâmica) para armazenar os processos conforme o método de escalonamento escolhido. 

## Criação de processos

- A cada iteração do programa, há uma chance de 30% de criar um novo processo.
- O tamanho do processo gerado deve estar entre 1 e 20 (números inteiros).
- O processo deve ser armazenado na estrutura de dados correspondente ao método de escalonamento escolhido.

## Execução de processos

- Cada iteração do programa representa uma unidade de tempo do sistema.
- O tempo de execução de um processo é baseado no seu tamanho.
- Para FCFS e SJF, a execução do próximo processo só ocorre ao término do processo atual.
- Para Round-Robin, o processo é executado por um quantum de 6 unidades de tempo.
- Se um processo terminar em 6 unidades de tempo ou menos, é removido da lista. Caso contrário, volta ao final da lista, descontando o tempo processado.

## Tarefas a serem realizadas:

- [x] Definir e implementar as estruturas de dados (pilha, fila, lista) com alocação dinâmica.
- [x] Implementar a lógica para a criação de processos com tamanhos aleatórios.
- [x] Desenvolver a lógica de escalonamento para cada método (FCFS, SJF, Round-Robin).
- [x] Implementar o loop principal do programa, representando as iterações do sistema.
- [x] Testar o programa com diferentes cenários.

## Como executar

Para executar o programa, basta executar o seguinte comando:

```bash
make run
``` 

## Como compilar

Para compilar o programa, basta executar o seguinte comando:

```bash
make
```

## Como limpar

Para limpar os arquivos gerados pela compilação, basta executar o seguinte comando:

```bash
make clean
```
