/*Algoritmos e Programa��o II
  Trabalho M3:Lista Din�mica Encadeada
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
    lista.inicio = NULL;///Indica que a lista ir� iniciar vazia
}


bool insere_elemento_lista(ListaE &lista, Produto *prod){///Inserir um produto na lista
    prod->proximo=lista.inicio;/// O novo produto est� sendo inserido no in�cio da lista
    lista.inicio = prod;///O ponteiro � atualizado, apontando para o primeiro item da lista

}

int localizar_recursivo(Produto *nav, int codigo, int posicao) {
    if (nav == NULL) {
        return -1; /// C�digo n�o encontrado
    }

    if (nav->Codigo == codigo) {
        return posicao; /// C�digo encontrado, retorna a posi��o
    }


    return localizar_recursivo(nav->proximo, codigo, posicao + 1); /// Chama recursivamente para o pr�ximo da lista
}

int localizar(ListaE lista, int codigo) {

    return localizar_recursivo(lista.inicio, codigo, 1);/// Inicia a chamada recursiva a partir do in�cio da lista e posi��o 1
}

int remover_Produto (ListaE &lista, int pos){
    /// Inicializa��o de ponteiros e vari�veis auxiliares
    Produto *nav = lista.inicio; /// Ponteiro para o in�cio da lista
    Produto *prox = lista.inicio->proximo; /// Ponteiro para o pr�ximo elemento ap�s o in�cio
    int aux=0; /// Vari�vel auxiliar para rastrear a posi��o na lista

    if(pos == 1){
        if(nav->proximo == NULL){   /// Se a lista cont�m apenas um elemento
            lista.inicio = NULL; /// Define o in�cio da lista como NULL
            delete nav;


        }else {
            lista.inicio = nav->proximo; /// Define o pr�ximo elemento como in�cio
            delete nav;
        }

    }else if (pos>1){
        while(aux < pos-2){ /// Move os ponteiros nav e prox para a posi��o desejada
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

        while (contador < pos) { /// Percorre at� a posi��o encontrada
            nav = nav->proximo;
            contador++;
        }
        return nav->Preco; /// Retorna o pre�o do produto na posi��o encontrada

    }else {/// Se o produto n�o foi encontrado na lista, retorne um valor de pre�o inv�lido (pode ser tratado no c�digo que chamar essa fun��o)
        return 0.0f; /// Valor de pre�o inv�lido
    }

}

int verifica_codigo (ListaE lista, Produto novo_prod){
    Produto *nav = lista.inicio;
    while (nav!= NULL){ ///se for diferente de vazia entra
        if (nav->Codigo == novo_prod.Codigo){
            return 0;///Retorna 0 quando o c�digo j� existir
        }else {
            nav = nav->proximo;///Aponta para o pr�ximo produto
        }
    }
    return 1;
}

Produto *cadastro_produto_a(Produto produto_auxiliar) {///Cria um produto
  Produto *novo_produto = new Produto;
  novo_produto->Codigo = produto_auxiliar.Codigo;/// Atribui um c�digo ao novo produto
  novo_produto->Nome = produto_auxiliar.Nome;/// Atribui um nome ao novo produto
  novo_produto->Preco = produto_auxiliar.Preco;/// Atribui um pre�o ao novo produto
  return novo_produto;

}
#endif
