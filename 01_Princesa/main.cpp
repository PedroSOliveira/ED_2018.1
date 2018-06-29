
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    int cavalheiros_total, cavalheiro_inicial, salto;
    cout << "Digite o numero de cavalheiros: "  ;
    cin >> cavalheiros_total ;

    int vetor[cavalheiros_total];

    cout << "Escolha um cavalheiro para começar: "  ;
    cin >> cavalheiro_inicial ;
    cout << "Escolha o número de saltos: "  ;
    cin >> salto ;

    //preenchendo todos com 1
    int i, cont = 0;
    for(i = 0; i < cavalheiros_total; i++){
           vetor[i] = 1;
    }

    while(cont < cavalheiros_total -1){
        int ant = cavalheiro_inicial%cavalheiros_total;
        i = 0;
        while(i < salto){
            if(vetor[ (cavalheiro_inicial+1)%cavalheiros_total ] != 0 && (cavalheiro_inicial+1)%cavalheiros_total != ant){
                i++;
            }
            cavalheiro_inicial++;
        }
        vetor[cavalheiro_inicial%cavalheiros_total] = 0;
        while(vetor[cavalheiro_inicial%cavalheiros_total] == 0){
            cavalheiro_inicial++;
        }
        cont++;
    }
    cout <<" O cavalheiro que conquistou a princesa foi : ";
    cout << cavalheiro_inicial%cavalheiros_total << endl;

    return 0;
}
