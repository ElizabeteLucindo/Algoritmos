/*Algoritmos e Programa��o II
  Trabalho M3:Lista Din�mica Encadeada
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
    PROD <<"C�digo\tNome\tPre�o"<<endl;
    Produto *nova_lista = lista.inicio; ///Aponta para o in�cio da lista

    while (nova_lista != NULL){///Percorre a lista at� chegar no final
        PROD<<nova_lista->Codigo<<"\t"<<nova_lista->Nome<<"\t"<<nova_lista->Preco<<endl;
        nova_lista = nova_lista -> proximo; ///Aponta para o pr�ximo produto
    }

    PROD.close();///Fecha o arquivo
}

void leitura_arq (ListaE &lista){
    ifstream PRODUCT; ///Para leitura do arquivo quando abrir
    PRODUCT.open ("list.txt");///Abre o arquivo
    Produto produto_auxiliar; ///Cria novo produto

    if (!PRODUCT.is_open()) {
    cout << "N�o foi poss�vel abrir o arquivo para leitura." << endl;

    }else{/// Se o arquivo  estiver aberto, ent�o entrar� o c�digo,nome,pre�o
    string line;
     getline(PRODUCT, line); // Ignora a primeira linha (coment�rio)
     getline(PRODUCT, line); // Ignora a segunda linha (coment�rio)

        while(PRODUCT >> produto_auxiliar.Codigo ){
            PRODUCT.ignore(); // Ignora o caractere de tabula��o
            getline(PRODUCT, produto_auxiliar.Nome, '\t');
            PRODUCT >> produto_auxiliar.Preco;

            Produto *novo_p = cadastro_produto_a(produto_auxiliar);
            insere_elemento_lista(lista, novo_p);

        }PRODUCT.close();///Fecha o arquivo
    }
}
#endif
