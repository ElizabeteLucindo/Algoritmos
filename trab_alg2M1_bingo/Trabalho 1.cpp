#include <iostream>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;

#define TAM 5
#define qtd 75

// Definições das cores
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTAQUA 11
#define LIGHTRED 12
#define LIGHTPURPLE 13
#define LIGHTYELLOW 14
#define BRIGHTWHITE 15

void menu(char &resposta) {
    // Função para as opções do menu
    cout << "\n";
    cout << "BINGO" << endl;
    cout << "\n";
    cout << "MENU" << endl;
    cout << "1. Jogar" << endl;
    cout << "2. Regras" << endl;
    cout << "3. Sobre" << endl;
    cout << "4. Fim" << endl;
    cin >> resposta;
}

void regras() {
    // Função para exibir as regras do jogo
    cout << "Regras do BINGO:" << endl;
    cout << "Cada jogador possui cartelas, sendo que cada cartela possui 5 colunas com 5 linhas, e cada linha possui 5 valores." << endl;
    cout << "Os jogadores devem ouvir os números cantados, verificar se os mesmos constam na cartela, e caso constem marcá-los na cartela." << endl;
    cout << "A primeira pessoa que completar uma cartela é a vencedora." << endl;
}

void sobre() {
    // Função para exibir informações sobre o jogo
    cout << "\nDesenvolvedoras:     Elizabete Lucindo da Silva\n";
    cout << "                     Fabiane Santos Soares\n";
    cout << "                     Marilia Hentz\n";
    cout << "                     Ryanne dos Santos \n\n";
    cout << "Professor: Rafael Ballottin Martins\n";
    cout << "Disciplina: Algoritmos e Programação II\n";
    cout << "Agosto/2023\n";
}

void delay(unsigned long t) {
    // Função para pausar a tela
    Sleep(t);
}

void textcolor(int forecolor, int backcolor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)(forecolor | backcolor << 4));
}

int sorteio_num() {
    return rand() % 75 + 1;
}

void bubblesort(int M[][TAM], int n) {
    // Função para ordenar a cartela
    int i, j, cond, temp, linha;

    for (linha = 0; linha < TAM; linha++) {
        cond = 1;
        for (i = n - 1; (i >= 1) && (cond == 1); i--) {
            cond = 0;
            for (j = 0; j < i; j++) {
                if (M[linha][j + 1] < M[linha][j]) {
                    temp = M[linha][j];
                    M[linha][j] = M[linha][j + 1];
                    M[linha][j + 1] = temp;
                    cond = 1;
                }
            }
        }
    }
}

bool verifica_bolinha(int bolinhas[qtd], int temp) {
    // Função para verificar se a bolinha já foi sorteada
    for (int i = 0; i < qtd; i++) {
        if (bolinhas[i] == temp)
            return true;
    }
    return false;
}

void exibe_bolinha(int bolinhas[], int total) {
    // Função para exibir os números sorteados

    cout << "Números sorteados: ";
    for (int i = 0; i < total; i++) {
        cout << bolinhas[i];
        if (i < total - 1) {
            cout << ", ";
        }

    }

    cout << endl;
}

void sorteio_bolinha(int bolinhas[qtd]) {
    // Função para sortear as bolinhas
    int i, temp,total;
    for (i = 0; i < qtd; i++) {
        temp = rand() % 75 + 1;
        if (!verifica_bolinha(bolinhas, temp))
            bolinhas[i] = temp;
        else
            i--;
    }

}


void nomear_cartela(string nome[], int num_cartela[]) {
    // Função para numerar as cartelas do jogo e solicitar nomes dos jogadores
    int i;
    for (i = 0; i < TAM; i++) {
        num_cartela[i] = i + 1;
        cout << "Cartela nº " << num_cartela[i] << endl;
        cout << "Digite o nome do jogador:" << endl;
        cin >> nome[i];
        cout << "\n";
        system("cls");
    }
}

bool verifica_sorteio(int cart[][TAM], int sorteio) {
    // Função para verificar se o número sorteado não é repetido
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++) {
            if (sorteio == cart[i][j])
                return false;
        }
    return true;
}

void sorteio_cartela(int cart[][TAM]) {
    // Função para preencher os valores da cartela
    int sorteio, i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            sorteio = rand() % 15 + 1 + (15 * i);
            if (verifica_sorteio(cart, sorteio)) {
                cart[i][j] = sorteio;
            } else {
                j--;
            }
        }
    }
    bubblesort(cart,TAM);
}


void exibir (int cart[][TAM],  string nome[TAM],int num_cartela[TAM],int n,int bolinhas[], int total){
    int i,j,x;

        cout<<"Cartela nº "<<num_cartela[n]<<" - "<<nome[n]<<endl;
        for(i=0;i<TAM;i++){
            for(j=0;j<TAM;j++){
                    for (x=0; x<total; x++){
                         if (cart[i][j] == bolinhas[x])
                         textcolor(3, 0);

                    }cout<<cart[i][j] << "\t";
                         textcolor(7, 0);
            }
            cout<<endl;
        }cout<<"\n\n";

}

bool verifica_ganhador(int cart[][TAM], int numeros_sorteados[], int numero_sorteado) {
    int numero_sorteado_encontrado = 0;
    // Verificar se o jogador preencheu toda a sua cartela
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int numero_cartela = cart[i][j];

            // Verifique se o número na cartela já foi sorteado

            for (int k = 0; k < numero_sorteado; k++) {
                if (numeros_sorteados[k] == numero_cartela) {
                    numero_sorteado_encontrado += 1;

                }
            }


            }
        }// Se chegou aqui, o jogador venceu
     if (numero_sorteado_encontrado == 25) {
                return true;
    }else
        return false;
}




void imprimir_vencedor(int C1[][TAM],int C2[][TAM],int C3[][TAM],int C4[][TAM],int C5[][TAM], string nome[TAM], int num_cartela[TAM], int numeros_sorteados[], int numero_sorteado, int total) {
    int bolinhas;
    system("cls");

        if (verifica_ganhador(C1, numeros_sorteados, total)) {
            cout << "Jogador vencedor: " << nome[0] << " (Cartela nº " << num_cartela[0] << ")" << endl;
            cout << "Cartela vencedora:" << endl;
            for (int i=0;i<TAM;i++){
                for (int j=0;j<TAM;j++){
                    cout<<C1[i][j]<<"\t";
                }cout<<endl;
            }
            }
        else if (verifica_ganhador(C2, numeros_sorteados, total)) {
            cout << "Jogador vencedor: " << nome[1] << " (Cartela nº " << num_cartela[1] << ")" << endl;
            cout << "Cartela vencedora:" << endl;
            for (int i=0;i<TAM;i++){
                for (int j=0;j<TAM;j++){
                    cout<<C2[i][j]<<"\t";
                }cout<<endl;
            }
            }
        else if (verifica_ganhador(C3, numeros_sorteados, total)) {
            cout << "Jogador vencedor: " << nome[2] << " (Cartela nº " << num_cartela[2] << ")" << endl;
            cout << "Cartela vencedora:" << endl;
            for (int i=0;i<TAM;i++){
                for (int j=0;j<TAM;j++){
                    cout<<C3[i][j]<<"\t";
                }cout<<endl;
            }
            }
        else if (verifica_ganhador(C4, numeros_sorteados, total)) {
            cout << "Jogador vencedor: " << nome[3] << " (Cartela nº " << num_cartela[3] << ")" << endl;
            cout << "Cartela vencedora:" << endl;
            for (int i=0;i<TAM;i++){
                for (int j=0;j<TAM;j++){
                    cout<<C4[i][j]<<"\t";
                }cout<<endl;
            }
            }
        else if (verifica_ganhador(C5, numeros_sorteados, total)) {
            cout << "Jogador vencedor: " << nome[4] << " (Cartela nº " << num_cartela[4] << ")" << endl;
            cout << "Cartela vencedora:" << endl;
            for (int i=0;i<TAM;i++){
                for (int j=0;j<TAM;j++){
                    cout<<C5[i][j]<<"\t";
                }cout<<endl;
            }
            }
            delay(500);


            //break; // Encerra após encontrar o jogador vencedor
        }


int main() {
    setlocale(LC_ALL, "Portuguese");

    int C1[TAM][TAM], C2[TAM][TAM], C3[TAM][TAM], C4[TAM][TAM], C5[TAM][TAM], num_cartela[TAM];
    int bolinhas[qtd],cart[TAM][TAM];
    int total;
    int numeros_sorteados[qtd], numero_sorteado;
    char resposta;
    bool alguem_ganhou = false; // Variável para verificar se alguém ganhou

    string nome[TAM];

    srand(time(NULL));

    do {
        menu(resposta);
        system("cls");
        switch (resposta) {
            case '1':
                nomear_cartela(nome, num_cartela);
                sorteio_cartela(C1);


                sorteio_cartela(C2);

                for (int i = 0; i < 1; i++) {
                    while (C2[TAM - 1][TAM - 1] == C1[TAM - 1][TAM - 1]) {
                        sorteio_cartela(C2);
                    }
                }

                sorteio_cartela(C3);

                for (int i = 0; i < 1; i++) {
                    while (C3[TAM - 1][TAM - 1] == C2[TAM - 1][TAM - 1] || C3[TAM - 1][TAM - 1] == C1[TAM - 1][TAM - 1]) {
                        sorteio_cartela(C3);
                    }
                }

                sorteio_cartela(C4);

                for (int i = 0; i < 1; i++) {
                    while (C4[TAM - 1][TAM - 1] == C3[TAM - 1][TAM - 1] || C4[TAM - 1][TAM - 1] == C2[TAM - 1][TAM - 1] || C4[TAM - 1][TAM - 1] == C1[TAM - 1][TAM - 1]) {
                        sorteio_cartela(C4);
                    }
                }

                sorteio_cartela(C5);

                for (int i = 0; i < 1; i++) {
                    while (C5[TAM - 1][TAM - 1] == C4[TAM - 1][TAM - 1] || C5[TAM - 1][TAM - 1] == C3[TAM - 1][TAM - 1] || C5[TAM - 1][TAM - 1] == C2[TAM - 1][TAM - 1] || C5[TAM - 1][TAM - 1] == C1[TAM - 1][TAM - 1]) {
                        sorteio_cartela(C5);
                    }
                }


                total = 0;
                sorteio_bolinha(bolinhas);

                do {
                    for (total = 0; total < qtd; total++) {

                        exibe_bolinha(bolinhas,total);
                        exibir(C1, nome, num_cartela, 0,bolinhas,total);
                        delay(500);
                        numero_sorteado = bolinhas[total];
                        numeros_sorteados[total] = numero_sorteado;
                        exibir(C2, nome, num_cartela, 1,bolinhas,total);
                       delay(500);
                        numero_sorteado = bolinhas[total];
                        numeros_sorteados[total] = numero_sorteado;
                        exibir(C3, nome, num_cartela, 2,bolinhas,total);
                        delay(500);
                        numero_sorteado = bolinhas[total];
                        numeros_sorteados[total] = numero_sorteado;
                        exibir(C4, nome, num_cartela, 3,bolinhas,total);
                        delay(500);
                        numero_sorteado = bolinhas[total];
                        numeros_sorteados[total] = numero_sorteado;
                        exibir(C5, nome, num_cartela, 4,bolinhas,total);
                        delay(500);
                        numero_sorteado = bolinhas[total];
                        numeros_sorteados[total] = numero_sorteado;

                        system("cls");
                        // Verifique se alguém ganhou
                        if (verifica_ganhador(C1, numeros_sorteados, total) || verifica_ganhador(C2, numeros_sorteados, total) ||
                            verifica_ganhador(C3, numeros_sorteados, total) || verifica_ganhador(C4, numeros_sorteados, total) ||
                            verifica_ganhador(C5, numeros_sorteados, total)) {
                            alguem_ganhou = true;
                            resposta == '4';
                            break;
                        }
                    }
                } while (alguem_ganhou==false);

        imprimir_vencedor(C1,C2,C3,C4,C5,nome,num_cartela,numeros_sorteados,numero_sorteado,total);
                break;


            case '2':
                regras();
                break;

            case '3':
            sobre();
            break;

            case '4':
                cout<<"FIM";
                break;

            default:
                cout<<"Opção Inválida"<<endl;
        }
    } while (resposta != '4'); // Condição de saída quando o usuário escolhe '4'

    cout << "FIM" << endl;

    return 0;
}
