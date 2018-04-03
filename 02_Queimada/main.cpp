#include <iostream>
#include <vector>

using namespace std;

const int linha = 20;
const int coluna = 60;

struct Par{
    int l;
    int c;

    Par(int l,int c){
        this->l = l;
        this->c = c;
    }
};

vector<Par> vizinhos(Par par){

    vector<Par> vizinhos;

    vizinhos.push_back(Par(par.l,par.c + 1));
    vizinhos.push_back(Par(par.l,par.c - 1));
    vizinhos.push_back(Par(par.l + 1,par.c));
    vizinhos.push_back(Par(par.l - 1,par.c));

    return vizinhos;
}

void esperar(){
    char c;
    cin >> noskipws >> c;//capta o 'enter'
}
void mostrar(char mat[linha][coluna]){
    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            cout << mat[l][c];
        }
        cout << "\n";
    }
}

void limparTela(){
    for(int i = 0; i < 2; i++){
        cout << endl;
    }
}

vector<Par> colocar_aleatorio(vector<Par> vetor){
    for(int i = 0; i < (int)vetor.size(); i++){
            int aleatorio = rand() % vetor.size();
            swap(vetor[i],vetor[aleatorio]);
    }

    return vetor;
}


int queimar(int l,int c, char mat[linha][coluna],int nivel){

    int cont = 0;

    if(l < 0 or l >= linha)
        return 0;
    if(c < 0 or c >= coluna)
        return 0;
    if(mat[l][c] == '#'){
        int cont = 1;
        mat[l][c] = '0' + nivel;
        limparTela();
        mostrar(mat);
        esperar();

        int nivel_maximo = nivel + 1;

        for(Par par : colocar_aleatorio(vizinhos(Par(l,c)))){
            cont += queimar(par.l,par.c,mat,nivel_maximo);
            if(nivel_maximo > 9){
                nivel_maximo = 0;
            }
            mat[l][c] = '.';
        }
    }
    return cont;
}
int main(){

    char mat[linha][coluna];


    for(int l = 0; l < linha; l++){
        for(int c = 0; c < coluna; c++){
            mat[l][c] = ' ';
        }
    }

    int qtd = linha * coluna * 1.5;

    for(int i = 0; i < qtd; i++){
        mat[rand() % linha][rand() % coluna] = '#';
    }

    limparTela();
    mostrar(mat);

    int nivel = 0;

    int cont = queimar(0, 0, mat, nivel);
    cout << "Quantidade de arvores queimadas: " << cont << endl;

    return 0;
}


