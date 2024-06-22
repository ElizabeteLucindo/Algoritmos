/*Algoritmos e Programa��o II
  Trabalho M2:Agenda Eletr�nica Gen�rica
  Professor:Rafael Ballottin Martins
  Alunas:Elizabete Lucindo da Silva, Fabiane Soares Santos e  Marilia Hentz.*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
///Biblioteca
template<typename TIPO, int MAX>
struct Agenda {
    TIPO itens[MAX]; /// Um vetor que armazena os elementos da agenda.
    int quantidade;  /// Quantidade atual de elementos na agenda.
};


template<typename TIPO, int MAX>
bool inicializa_agenda(Agenda<TIPO, MAX>& ag) {
    ag.quantidade = 0; /// Define a quantidade de elementos como zero.
    return true; /// Retorna true para indicar que a agenda foi inicializada.
}


template <typename TIPO, int MAX>
bool inserir (Agenda <TIPO, MAX> &ag, TIPO & dado) {/// Fun��o para inserir um dado na agenda, desde que haja espa�o dispon�vel.
    if (ag.quantidade < MAX) {
        ag.itens[ag.quantidade] = dado; /// Insere o dado na pr�xima posi��o dispon�vel.
        ag.quantidade ++; /// Aumenta a quantidade de elementos na agenda.
        return true; /// Retorna true para indicar que o dado foi inserido com sucesso.
    }
    return false;
}

template <typename TIPO, int MAX>
bool remover (Agenda <TIPO,MAX> &ag, int pos){ /// Remove segundo a posi��o
    if (pos < 0 || pos >= ag.quantidade){ /// Verifica se a posi��o � v�lida.
        return false; /// Retorna false se a posi��o for inv�lida.
    }

    for(int i=pos; i<ag.quantidade-1;i++){
        ag.itens[i] = ag.itens[i+1]; /// Desloca os elementos para preencher o espa�o vazio.

    }ag.quantidade--; /// Reduz a quantidade de elementos na agenda.
        return true; /// Retorna true para indicar que o dado foi removido
    }



template <typename TIPO, int MAX>
bool verifica (TIPO n, Agenda<TIPO, MAX> ag){ /// Verifica se um elemento "n" j� existe na agenda.
    for (int i=0; i < MAX; i++) {
        if (n == ag.itens_agd[i]) {
            cout<<"\nA��o inv�lida, item j� existente" << endl;

        }
    }
}

