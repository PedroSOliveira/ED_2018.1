
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

int cavalheiros_total, cavalheiro_inicial;
 cout << "Digite o numero de cavalheiros: "  ;
 cin >> cavalheiros_total ;

int vetor[cavalheiros_total];

for(int i = 0; i < cavalheiros_total; i++){
    vetor[i] = i + 1;
}
int j;

cout << "Cavalheiros: " << endl;
for(j = 0; j < cavalheiros_total; j++){
    printf("%d""\n", vetor[j]);

}

int cavalheiro_vencedor;
int total = cavalheiros_total;


cout << "Escolha um cavalheiro pra inicia r: ";
cin >> cavalheiro_inicial ;

    for(int a = 0; a < cavalheiros_total; a++){
            if( cavalheiro_inicial == vetor[a]){
                do{
                    vetor[(a + 1) % cavalheiros_total] = 0;
                    cavalheiro_inicial = vetor[(a+2) % cavalheiros_total ];
                    total--;
                }while(total > 1);
            }
        }


cavalheiro_vencedor = cavalheiro_inicial;
cout << "O cavalheiro que conquistou a princesa foi: ";
cout <<  cavalheiro_vencedor  << endl;

    return 0;
}
