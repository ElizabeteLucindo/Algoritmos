/*Algoritmos e Programação II
  Trabalho M2:Agenda Eletrônica Genérica
  Professor:Rafael Ballottin Martins
  Alunas:Elizabete Lucindo da Silva, Fabiane Soares Santos e  Marilia Hentz.*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "bib.h" ///inclui a biblioteca genérica para agenda criada.
#include <locale.h>
using namespace std;

struct Pessoal { ///Tipo de variavel struct para agenda pessoal
    string id;
    long long  int cpf;
    string nome;
    long long int celular;
};

struct Comercial { ///Tipo de variavel struct para agenda comercial
    string id;
    long long int cnpj;
    string nome_empresa;
    long long int tel_comercial;
};

void menu_tipo (int *escolha){ /// Função para o menu de escolha entre agenda pessoal e comercial
    do{
    cout<<"\n1. AGENDA PESSOAL"<<endl;
    cout<<"2. AGENDA COMERCIAL"<<endl;
    cin>>*escolha;
    } while (*escolha!=1 && *escolha !=2);
}

void menu (char *opcoes){ /// Função para o menu de opções
    cout<<"1.INSERIR"<<endl;
    cout<<"2.REMOVER"<<endl;
    cout<<"3.PESQUISAR"<<endl;
    cout<<"4.ORDENAR"<<endl;
    cout<<"5.EXIBIR"<<endl;
    cout<<"6.ENCERRAR"<<endl;
    cin>>*opcoes;
}


void leitura_p (Pessoal   &AP){ /// Função de preencher (leitura) os dados

    cout << "AGENDA" << endl;
    cout << "Digite o ID:" << endl;
    cin >> AP.id;
    cout << "Digite o CPF:" << endl;
    cin >> AP.cpf;
    cout << "Digite o nome:" << endl;
    cin >> AP.nome;
    cout << "Digite o celular:" << endl;
    cin >> AP.celular;

}

void leitura_c (Comercial & AC){ /// Função de preencher (leitura) os dados
    cout << "AGENDA" << endl;
    cout << "ID: " << endl;
    cin >> AC.id;
    cout << "CNPJ: " << endl;
    cin >> AC.cnpj;
    cout <<"Nome da empresa: " << endl;
    cin >> AC.nome_empresa;
    cout << "Telefone comercial: " << endl;
    cin >> AC.tel_comercial;
}


int localizar (Agenda<Pessoal,10> ag, string dado){
    int i;
    for(i=0; i<ag.quantidade;i++){
        if (ag.itens[i].nome == dado || ag.itens[i].id == dado) /// verifica se o id ou nome digitado (dado, ou seja, a variavel escolha_id_nome) já existe na agenda pessoal
            return i; ///retorna a posição do vetor em que ele se localiza
    }return -1; /// se não encontrar retorna -1
}

int localizar (Agenda<Comercial,10> ag, string dado){
    int i;
    for(i=0; i<ag.quantidade;i++){
        if (ag.itens[i].nome_empresa == dado || ag.itens[i].id == dado)
            return i;
    }return -1;
}

void pesquisar (int i, Agenda<Pessoal,10> ag){ /// Função para pesquisar e exibir um contato pessoal
    cout<<"id\tCPF\tNOME\tCELULAR"<<endl;
    cout<<ag.itens[i].id<<"\t"<<ag.itens[i].cpf<<"\t"<<ag.itens[i].nome<<"\t"<<ag.itens[i].celular;
}

void pesquisar (int i, Agenda<Comercial,10> ag){ /// Função para pesquisar e exibir um contato comercial
    cout<<"id\tCNPJ\tEMPRESA\tTELEFONE"<<endl;
    cout<<ag.itens[i].id<<"\t"<<ag.itens[i].cnpj<<"\t"<<ag.itens[i].nome_empresa<<"\t"<<ag.itens[i].tel_comercial;
}


void exibir (Agenda<Pessoal,10> ag, Pessoal agendaPessoal){ ///Função para exibir a agenda
    cout<<"id\tCPF\tNOME\tCELULAR"<<endl;
    for (int i=0; i<ag.quantidade;i++){
        cout<<ag.itens[i].id<<"\t"<<ag.itens[i].cpf<<"\t"<<ag.itens[i].nome<<"\t"<<ag.itens[i].celular<<"\n";
    }
}


void exibir (Agenda<Comercial,10> ag, Comercial agendaComercial){
    cout<<"id\tCNPJ\tEMPRESA\tTELEFONE"<<endl;
    for (int i=0; i<ag.quantidade;i++){
        cout<<ag.itens[i].id<<"\t"<<ag.itens[i].cnpj<<"\t"<<ag.itens[i].nome_empresa<<"\t"<<ag.itens[i].tel_comercial<<"\n";
    }
}

template <typename TIPO, int MAX>
void bubblesort (Agenda <TIPO,MAX> &ag){ ///Função de ordenação genérico por nome
    int i, j, cond;
    TIPO temp; /// variável temporária para efetuar as trocas entre os elementos.
    cond =1; /// A variável 'cond' inicia o loop ao se atribuir 1.
    for (i=ag.quantidade-1; (i>=1) && (cond==1); i--){ /// O loop externo percorre a agenda, indo da última posição até a primeira.
        cond = 0; /// Reinicia-se o valor de 'cond' para 0.
        for (j=0;j<i;j++){
            if ((ag.itens[j+1] < ag.itens[j]) == true){/// Compara elementos sequentes na agenda usando a sobrecarga de operador
                temp = ag.itens[j];
                ag.itens[j] =ag.itens[j+1]; /// Substitui o elemento atual pelo elemento subsequente.
                ag.itens[j+1] = temp; /// Troca o próximo elemento pelo anterior.
                cond=1; /// Define 'cond' como 1 para sinalizar que ocorreu uma troca
            }
        }
    }
}

bool operator< (Pessoal agendaPessoal, Pessoal agendaPessoal2){ /// Sobrecarga do operador < para contatos pessoais

    if (agendaPessoal.nome < agendaPessoal2.nome){
        return true; /// Retorna true para indicar que o primeiro contato deve ser classificado antes do segundo.
    }return false; /// Retorna false para o primeiro contato não deve ser classificado antes do segundo.
}

bool operator< (Comercial agendaComercial, Comercial agendaComercial2){ /// Sobrecarga do operador < para contatos comerciais
    if (agendaComercial.nome_empresa < agendaComercial2.nome_empresa){ /// Verifica se o nome da empresa do primeiro contato comercial é estritamente menor (em ordem alfabética) do que o nome da empresa do segundo contato comercial.
        return true;
    }return false;
}

int main()
{
    setlocale (LC_ALL,"Portuguese");
    Pessoal agendaPessoal, agendaPessoal2; /// Duas variáveis para armazenar informações de contatos pessoais
    Comercial agendaComercial, agendaComercial2; /// Duas variáveis para armazenar informações de contatos comerciais
    Agenda<Pessoal,10> AP;
    Agenda<Comercial,10> AC;
    int *escolha = new int; /// Ponteiro para armazenar a escolha do tipo de agenda
    char *opcoes = new char; /// Ponteiro para armazenar a escolha da ação na agenda
    *opcoes = '0'; ///Atribuição de valor 0 ao ponteiro.
    string escolha_id_nome; /// Variável para armazenar o ID ou nome fornecido pelo usuário

    inicializa_agenda(AP); /// funções para atribuir 0 na quantidade (Agenda Pessoal - AP)
    inicializa_agenda(AC); /// funções para atribuir 0 na quantidade (Agenda Comercial - AC)

    while (*opcoes != '6'){

        menu_tipo (escolha);
        menu (opcoes);
        system("cls");
        switch(*escolha){


        case 1: ///escolha de agenda pessoal
            if(*opcoes =='1'){ ///Inserir
                leitura_p(agendaPessoal); ///preenche os dados da agenda pessoal
                if (!inserir(AP, agendaPessoal))/// Se retornar true insere os dados na agenda pessoal
                    cout<<"Agenda sem espaço"<<endl;

            }else if(*opcoes == '2'){ ///remover
                cout<<"Escreva o ID ou nome"<<endl;
                cin>>escolha_id_nome;
                int pos = localizar(AP,escolha_id_nome); /// iguala uma variável a posição do vetor localizado para o id/nome pesquisado
                remover(AP,pos); /// remove os dados da posicao localizada na agenda pessoal

            }else if (*opcoes == '3'){ ///pesquisar um item na agenda (por ID ou nome)
                int localizador;

                cout<<"Escreva o ID ou nome"<<endl;
                cin>>escolha_id_nome;
                localizador = localizar(AP,escolha_id_nome); /// chama a função localizar passando a struct agenda e o nome/id digitado
                if (localizador != -1)
                    pesquisar (localizador, AP); /// se foi localizado na agenda é feito a pesquisa e exibição
                else
                     cout<<"Não encontrado"<<endl;


            }else if (*opcoes == '4'){///4. ordenar a agenda por nome

                bubblesort (AP);

            }else if (*opcoes == '5'){/// mostrar todos os itens da agenda

                exibir (AP, agendaPessoal);

            }else if (*opcoes == '6'){ /// encerrar programa

                return 0;

            }else {
                cout<<"Opção inválida "<<endl;
            }
            break;

        case 2: ///escolha de agente comercial
            if(*opcoes =='1'){

              leitura_c(agendaComercial);
              if (!inserir(AC, agendaComercial))
                cout<<"Agenda sem espaço"<<endl;


            }else if(*opcoes == '2'){ ///remover

                cout<<"Escreva o ID ou nome"<<endl;
                cin>>escolha_id_nome;
                int pos = localizar(AC,escolha_id_nome);
                remover(AC,pos);

            }else if (*opcoes == '3'){///pesquisar
                int localizador;
                cout<<"Escreva o ID ou nome"<<endl;
                cin>>escolha_id_nome;
                localizador = localizar(AC,escolha_id_nome);
                if (localizador != -1)
                    pesquisar (localizador, AC);
                else
                    cout<<"Não encontrado"<<endl;

            }else if (*opcoes == '4'){/// ordenar a agenda por nome

                 bubblesort (AC);

            }else if (*opcoes == '5'){///5. mostrar todos

                exibir (AC, agendaComercial);

            }else if (*opcoes == '6'){

                return 0;

            }else {

                cout<<"Opção inválida "<<endl;
            }
            break;
        }

    }
    delete escolha;
    delete opcoes;

}
