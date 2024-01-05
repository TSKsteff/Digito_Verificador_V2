#include <iostream>
#define tam 13

using namespace std;

void imprimiVetor(int vtr[]) {
	for (int i = 0; i < tam; i++){cout << vtr[i] << " - ";}
}

int somatorio(int vtr[], int &sum) {
	for (int i = 0; i < 12; i++) { sum += vtr[i];}
	return sum;
}

int main() {

	//Declarações de variaveis

	long long code, valor_inicial = 1000000000000;
    int vtr[13],valor = 10, sum =0, multiplica =0, codigoVerificador =0 ;

	cout << "Digite seu codigo de barras de 13 digitos" << endl;
	cin >> code;

	if (code > 1000000000000 && code < 9999999999999) {

		for (int i = 0; i < tam; i++) {
			vtr[i] = (i % 2) != 0 && i < 12 ? (code / valor_inicial % valor) *3: code / valor_inicial % valor;
			valor_inicial /= 10;
		}
	}

	sum = somatorio(vtr,sum);

	multiplica = ((sum / 10) + 1) *10;

    codigoVerificador = multiplica - sum;
	if(codigoVerificador != vtr[12]){
        codigoVerificador %10==0 ? codigoVerificador =0: codigoVerificador;
        cout << "Codigo verificador "<<vtr[12]<<" resulta inconsistente\n\t substitua por: "<<codigoVerificador;
	}else{
        cout << "Codigo verificador consistente";
	}
	return 0;
}