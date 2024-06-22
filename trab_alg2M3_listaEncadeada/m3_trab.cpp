/*Algoritmos e Programação II
  Trabalho M3:Lista Dinâmica Encadeada
  Professor:Rafael Ballottin Martins
  Alunas:Elizabete Lucindo da Silva, Fabiane Soares Santos e  Marilia Hentz.*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <fstream>
#include"lista.h"///Biblioteca de funções em geral
#include"arq.h"///Biblioteca de funções referentes ao arquivo
using namespace std;


void menu (char *opcoes){ /// Função para o menu de opções
    cout<<"1.INSERIR"<<endl;
    cout<<"2.REMOVER"<<endl;
    cout<<"3.PESQUISAR"<<endl;
    cout<<"4.ENCERRAR"<<endl;
    cin>>*opcoes;///Opção escolhida é armazenada no local apontado pelo ponteiro

}
Produto *cadastrar (){///Função para cadastrar produtos
    Produto *novo_produto;
    novo_produto = new Produto;///Aloca dinamicamente o Produto e atribui o endereço novo_produto

    cout<<"Código: ";
    cin>>novo_produto->Codigo;

    cout<<"Nome: ";
    cin>>novo_produto->Nome;

    cout<<"Preço: ";
    cin>>novo_produto->Preco;
return novo_produto;///Retorna o ponteiro para o Produto criado
}

void exibir_lista (ListaE lista){
    cout<<"Lista de Produtos"<<endl;
    cout<<"Código\tNome\tPreço"<<endl;
    Produto *nova_lista = lista.inicio; ///Aponta para o inicio da lista

    while (nova_lista != NULL){
        cout<<nova_lista->Codigo<<"\t"<<nova_lista->Nome<<"\t"<<nova_lista->Preco<<endl;
        nova_lista = nova_lista -> proximo; ///Aponta para o próximo produto
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int codigo, pos;
    float preco;

    char *opcoes = new char;/// Ponteiro para armazenar a escolha da ação na lista
    *opcoes = '0'; ///Atribuição de valor 0 ao ponteiro.

    ListaE lista;
    Produto novo_produto;

    inicializa_lista(lista);
    leitura_arq (lista);

    while(*opcoes != '4'){

        exibir_lista(lista);
        cout<<endl;
        menu (opcoes);

        switch(*opcoes){
        case '1':
            Produto *novo_prod;
            novo_prod=cadastrar();///Preenche os dados do produto
            system("cls");///Limpa a tela

            if(verifica_codigo(lista, *novo_prod)!=0){
                insere_elemento_lista(lista,novo_prod);/// Se retornar true insere na lista
            } else {
            cout<<"O código digitado já está cadastrado para outro produto"<<endl;
            }
        break;

        case '2':
            cout<<"Digite o código do produto em que deseja deletar"<<endl;
            cin>>codigo;
            pos=localizar (lista,codigo);///Localiza a posição do produto referente ao código digitado e armazena na variável pos

            remover_Produto (lista, pos);///Remove o produto da lista com base na posição que foi armazenada em pos
            system("cls");
            break;

        case '3':
            cout<<"Digite o código do produto em que deseja pesquisar o preço"<<endl;
            cin>>codigo;
            pos=localizar (lista,codigo);

            preco = pesquisa_preco (lista, pos);///Obtem o preço do produto cuja posição está aramazenada em pos
            if (preco != 0.0){///Verifica se o preço é diferente de 0
                system("cls");
                cout<<"Preço: R$ "<<preco<<endl<<endl;
            }else{
                system("cls");
                cout<<"Produto não encontrado"<<endl<<endl;
            }

            break;

        case '4':
            escrita_arq (lista);
            break;

        default:
            system("cls");
            cout<<"Opção inválida"<<endl<<endl;

        }
      }
      delete opcoes;
      return 0;
}
