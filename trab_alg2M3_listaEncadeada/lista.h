/*Algoritmos e Programação II
  Trabalho M3:Lista Dinâmica Encadeada
  Professor:Rafael Ballottin Martins
  Alunas:Elizabete Lucindo da Silva, Fabiane Soares Santos e  Marilia Hentz.*/

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

///Biblioteca

struct Produto{///Estrutura do produto
int Codigo;
string Nome;
float Preco;
Produto *proximo;///Permite que os produtos sejam encadeados em uma lista
};

struct ListaE{///Estrutura da lista
    Produto * inicio;///Aponta para o primeiro item da lista
};

bool inicializa_lista(ListaE &lista){///Inicializa a lista
    lista.inicio = NULL;///Indica que a lista irá iniciar vazia
}


bool insere_elemento_lista(ListaE &lista, Produto *prod){///Inserir um produto na lista
    prod->proximo=lista.inicio;/// O novo produto está sendo inserido no início da lista
    lista.inicio = prod;///O ponteiro é atualizado, apontando para o primeiro item da lista

}

int localizar_recursivo(Produto *nav, int codigo, int posicao) {
    if (nav == NULL) {
        return -1; /// Código não encontrado
    }

    if (nav->Codigo == codigo) {
        return posicao; /// Código encontrado, retorna a posição
    }


    return localizar_recursivo(nav->proximo, codigo, posicao + 1); /// Chama recursivamente para o próximo da lista
}

int localizar(ListaE lista, int codigo) {

    return localizar_recursivo(lista.inicio, codigo, 1);/// Inicia a chamada recursiva a partir do início da lista e posição 1
}

int remover_Produto (ListaE &lista, int pos){
    /// Inicialização de ponteiros e variáveis auxiliares
    Produto *nav = lista.inicio; /// Ponteiro para o início da lista
    Produto *prox = lista.inicio->proximo; /// Ponteiro para o próximo elemento após o início
    int aux=0; /// Variável auxiliar para rastrear a posição na lista

    if(pos == 1){
        if(nav->proximo == NULL){   /// Se a lista contém apenas um elemento
            lista.inicio = NULL; /// Define o início da lista como NULL
            delete nav;


        }else {
            lista.inicio = nav->proximo; /// Define o próximo elemento como início
            delete nav;
        }

    }else if (pos>1){
        while(aux < pos-2){ /// Move os ponteiros nav e prox para a posição desejada
            nav = nav->proximo;
            prox = prox->proximo;
            aux++;
        }
        nav -> proximo = prox->proximo;
        delete prox;

    }else if (pos == NULL){
        return 0;
    }
}
float pesquisa_preco (ListaE lista, int pos){

    if (pos != -1) { /// Se o produto foi encontrado na lista
        Produto *nav = lista.inicio;
        int contador = 1;

        while (contador < pos) { /// Percorre até a posição encontrada
            nav = nav->proximo;
            contador++;
        }
        return nav->Preco; /// Retorna o preço do produto na posição encontrada

    }else {/// Se o produto não foi encontrado na lista, retorne um valor de preço inválido (pode ser tratado no código que chamar essa função)
        return 0.0f; /// Valor de preço inválido
    }

}

int verifica_codigo (ListaE lista, Produto novo_prod){
    Produto *nav = lista.inicio;
    while (nav!= NULL){ ///se for diferente de vazia entra
        if (nav->Codigo == novo_prod.Codigo){
            return 0;///Retorna 0 quando o código já existir
        }else {
            nav = nav->proximo;///Aponta para o próximo produto
        }
    }
    return 1;
}

Produto *cadastro_produto_a(Produto produto_auxiliar) {///Cria um produto
  Produto *novo_produto = new Produto;
  novo_produto->Codigo = produto_auxiliar.Codigo;/// Atribui um código ao novo produto
  novo_produto->Nome = produto_auxiliar.Nome;/// Atribui um nome ao novo produto
  novo_produto->Preco = produto_auxiliar.Preco;/// Atribui um preço ao novo produto
  return novo_produto;

}
#endif
