

//PARTE 1 - Recursividade: somatório//

// codigo para calcular o somatório de 1 até n usando recursão//

#include <stdio.h>
#include <stdlib.h>
int somatorio(int n) {
    if (n == 1) {                
        return 1;
    }
    return n + somatorio(n - 1);  
}

int main1(void) {
    int n;
    printf("Digite n: ");
    scanf("%d", &n);
    printf("Somatorio = %d\n", somatorio(n));
    return 0;
}
/* Repostas:

1.Indique o caso base da função.

R:S(1) = 1 é o menor valor da soma e pode ser respondido sem nova chamada. Sem o caso base, a função chamaria a si mesma indefinidamente e estouraria a pilha (stack overflow).

2. Indique a chamada recursiva e explique como o problema diminui.

R:S(n) = n + S(n-1). Cada chamada resolve um problema menor, já que o argumento cai de n para n-1. Com isso, a sequência converge para o caso base (n = 1) depois de n-1 chamadas.

3. Desenhe a sequência de chamadas para somatorio(5).

R: Ida (empilhando):

somatorio(5) = 5 + somatorio(4)
  somatorio(4) = 4 + somatorio(3)
    somatorio(3) = 3 + somatorio(2)
      somatorio(2) = 2 + somatorio(1)
        somatorio(1) = 1        ← caso base

Volta (desempilhando):

somatorio(1) retorna 1
somatorio(2) retorna 2 + 1  = 3
somatorio(3) retorna 3 + 3  = 6
somatorio(4) retorna 4 + 6  = 10
somatorio(5) retorna 5 + 10 = 15
Resultado final: 15

4. Determine a complexidade temporal e a complexidade de memória da recursão.

R: A complexidade temporal da função somatorio é O(n), pois a função faz n chamadas recursivas até atingir o caso base. A complexidade de memória também é O(n), pois cada chamada recursiva adiciona um novo quadro à pilha de chamadas, resultando em n quadros no total antes de começar a retornar.
*/

// Parte 2  Recursividade aplicada a vetor//

int somaVetor(int vetor[], int n) {
    if (n == 0) {                                   
        return 0;
    }
    return vetor[n - 1] + somaVetor(vetor, n - 1);  
}

int maiorVetor(int vetor[], int n) {
    if (n == 1) {                                   
        return vetor[0];
    }
    int maiorResto = maiorVetor(vetor, n - 1);     
    if (vetor[n - 1] > maiorResto) {
        return vetor[n - 1];
    }
    return maiorResto;
}

int main2(void) {
    int vetor[] = {10, 20, 30, 40, 50};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Soma = %d\n", somaVetor(vetor, n));     
    printf("Maior = %d\n", maiorVetor(vetor, n));   
    return 0;
}

/*
1. Qual deve ser o caso base de somaVetor?

R: O caso base de somaVetor é quando n é igual a 0. Nesse caso, a função retorna 0, pois não há elementos para somar.

2.Como o parâmetro n pode representar o tamanho do problema restante?

R:parâmetro n indica quantos elementos do vetor ainda precisam ser processados, ou seja, considera-se apenas os índices de 0 até n-1. A cada chamada, o último elemento (vetor[n-1]) é tratado e o restante é delegado a somaVetor(vetor, n - 1), que olha para um vetor com um elemento a menos. Assim o problema diminui de 1 em 1 até chegar a n = 0, o caso base.

3.Explique por que somaVetor e maiorVetor possuem complexidade O(n).

R:Cada função faz uma única chamada recursiva por nível e reduz n em 1, então são n chamadas até o caso base, cada uma com trabalho constante (uma soma ou uma comparação). Logo, o tempo é n × O(1) = O(n), tanto no melhor quanto no pior caso, pois todos os elementos são sempre visitados.
Na memória também é O(n), porque as n chamadas ficam empilhadas ao mesmo tempo até o caso base retornar.

*/
//PARTE 3 - Do ponteiro ao nó da lista//
typedef struct No No;
 
struct No {
    int valor;
    No *proximo;
};
/*
1. É um ponteiro para o outro nó da lista, armazenando o endereço de memória do próximo nó.
Quando for o último Nó da lista, o ponteiro vai apontar para "NULL", indicando que não há mais elementos na lista.
 
2. "No" representa o tipo da estrutura que define um nó da lista.
"No *" representa um ponteiro para um nó, ou seja, uma variável capaz de armazenar o endereço de memória de um No.
"No *proximo" declara uma variável chamada proximo, que é um ponteiro para outro nó do tipo No.
E no código, "valor" guarda o dado do No, enquanto "proximo" aponta para o próximo nó na lista encadeada.
 
3.
Usa-se -> para acessar os campos de uma struct por meio de um ponteiro.
Por exemplo, se novo é um No *:
 
novo->valor = 10;
novo->proximo = NULL;
 
O operador -> acessa diretamente os campos do nó apontado por novo. Que é igual a:
 
(*novo).valor = 10;
(*novo).proximo = NULL;
 
Portanto, -> é a forma mais simples de acessar os membros de uma estrutura com ponteiro.
 
*/
//PARTE 4 -Criando uma lista e inserindo no início//
typedef struct No No;
 
struct No {
    int valor;
    No *proximo;
};
 
No *inserirInicio(No *inicio, int valor) {
    // 1. Alocar um novo no
    No *novo = malloc(sizeof(No));
 
    // 2. Verificar se malloc retornou NULL
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return inicio;
    }
 
    // 3. Guardar o valor
    novo->valor = valor;
 
    // 4. Fazer novo->proximo apontar para o inicio atual
    novo->proximo = inicio;
 
    // 5. Retornar o novo inicio
    return novo;
}
 
int main3(void) {
    // Criacao da lista vazia
    No *inicio = NULL;
 
    // Insercoes
    inicio = inserirInicio(inicio, 30);
    inicio = inserirInicio(inicio, 20);
    inicio = inserirInicio(inicio, 10);
 
    return 0;
}
 
 
/*
1.
Inicialmente, o ponteiro inicio aponta para NULL,
representando uma lista vazia.
 
Ao inserir 30, um novo no é criado. O campo proximo
desse no aponta para NULL, que era o inicio anterior.
Depois, inicio passa a apontar para o no que contem 30.
 
Ao inserir 20, um novo no e criado e seu campo proximo
aponta para o no que contem 30. Depois, inicio passa a
apontar para o no que contem 20.
 
Ao inserir 10, um novo no e criado e seu campo proximo
aponta para o no que contem 20. Depois, inicio passa a
apontar para o no que contem 10.
 
 
2.
inicio
 
[10 | *] -> [20 | *] -> [30 | NULL]
 
 
3.
A insercao no inicio possui complexidade O(1) porque
nao e necessario percorrer a lista.
 
Independentemente da quantidade de nos existentes,
a operacao realiza uma quantidade constante de passos:
aloca o novo no, guarda o valor, faz o novo no apontar
para o inicio atual e atualiza o inicio da lista.
 
Por isso, o tempo da operacao nao aumenta conforme
a quantidade de elementos da lista.
*/

int main(){
    printf("Parte 1 - Somatório:\n");
    main1();
    printf("Parte 2 - Vetor:\n");
    main2();
    printf("Parte 3 - Lista Encadeada:\n");
    main3(); 
    return 0;
}