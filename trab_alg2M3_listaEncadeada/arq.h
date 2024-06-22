/*Algoritmos e Programação II
  Trabalho M3:Lista Dinâmica Encadeada
  Professor:Rafael Ballottin Martins
  Alunas:Elizabete Lucindo da Silva, Fabiane Soares Santos e  Marilia Hentz.*/
#ifndef ARQ_H
#define ARQ_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

///Biblioteca

void escrita_arq (ListaE lista){
    ofstream PROD;
    PROD.open ("list.txt");///Abre/cria o arquivo
    PROD <<"Lista de Produtos"<<endl;
    PROD <<"Código\tNome\tPreço"<<endl;
    Produto *nova_lista = lista.inicio; ///Aponta para o início da lista

    while (nova_lista != NULL){///Percorre a lista até chegar no final
        PROD<<nova_lista->Codigo<<"\t"<<nova_lista->Nome<<"\t"<<nova_lista->Preco<<endl;
        nova_lista = nova_lista -> proximo; ///Aponta para o próximo produto
    }

    PROD.close();///Fecha o arquivo
}

void leitura_arq (ListaE &lista){
    ifstream PRODUCT; ///Para leitura do arquivo quando abrir
    PRODUCT.open ("list.txt");///Abre o arquivo
    Produto produto_auxiliar; ///Cria novo produto

    if (!PRODUCT.is_open()) {
    cout << "Não foi possível abrir o arquivo para leitura." << endl;

    }else{/// Se o arquivo  estiver aberto, então entrará o código,nome,preço
    string line;
     getline(PRODUCT, line); // Ignora a primeira linha (comentário)
     getline(PRODUCT, line); // Ignora a segunda linha (comentário)

        while(PRODUCT >> produto_auxiliar.Codigo ){
            PRODUCT.ignore(); // Ignora o caractere de tabulação
            getline(PRODUCT, produto_auxiliar.Nome, '\t');
            PRODUCT >> produto_auxiliar.Preco;

            Produto *novo_p = cadastro_produto_a(produto_auxiliar);
            insere_elemento_lista(lista, novo_p);

        }PRODUCT.close();///Fecha o arquivo
    }
}
#endif
