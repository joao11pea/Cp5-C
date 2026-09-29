#include<stdio.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

//  PARTE 5



void imprimirLista(No *inicio)
{
    No *atual = inicio;
    while (atual != NULL)
    {
        printf("%d -> ", atual->valor); // Exibe o valor
        atual = atual->proximo;         // Avança para o próximo nó
    }
    printf("NULL\n");
}

/*
    RESPOSTAS:

    1. Por que não devemos alterar o ponteiro inicio durante a impressão?
        O ponteiro inicio é a única referência ao primeiro nó da lista. 
        Se ele for alterado dentro da função, a lista pode ser perdida. 
        Isso não é problema aqui, porque inicio é passado por valor (a função altera só uma cópia). 
        Mas a boa prática é usar um ponteiro auxiliar (atual) para percorrer, deixando claro que 
        a impressão é uma operação de leitura, que não modifica a estrutura. 
        Se o mesmo código fosse feito com ponteiro para ponteiro, ou operando direto na variável
         inicio da lista, perder o início causaria vazamento de memória, pois os nós ficariam inacessíveis.

    2. O que atual = atual->proximo faz?
        Ela lê o endereço guardado no campo proximo do nó atual e o atribui ao ponteiro atual. 
        Assim, atual passa a apontar para o nó seguinte. 
        Quando chega ao último nó, proximo é NULL, então atual vira NULL e o while termina.

    3. Complexidade para imprimir uma lista com n nós:
        O(n), pois cada nó é visitado exatamente uma vez, com custo constante por nó.
*/

//  PARTE 6

int buscar(No *inicio, int valor)
{
    No *atual = inicio;
    while (atual != NULL)
    {
        if (atual->valor == valor)
        { // Verifica se encontrou
            return 1;
        }
        atual = atual->proximo; // Avança para o próximo nó
    }
    return 0;
}

/*
    RESPOSTAS:

    1. Melhor caso da busca:
        O valor procurado está no primeiro nó. Basta uma comparação, então a complexidade é O(1).

    2. Pior caso da busca:
        O valor está no último nó ou não existe na lista. É preciso percorrer os n nós, então a 
        complexidade é O(n).

    3. Por que a lista não permite acesso direto como vetor[i]?
        Em um vetor, os elementos ficam em posições contíguas de memória, então o endereço do elemento i 
        é calculado diretamente (endereço base + i × tamanho do tipo), em O(1). 
        Na lista encadeada, os nós ficam espalhados na memória (alocação dinâmica), e a única ligação 
        entre eles é o ponteiro proximo. Para chegar ao i-ésimo nó é preciso partir do
        início e seguir os ponteiros um a um, o que custa O(n).

*/

//  PARTE 7

