#include <iostream>

using namespace std;

int main() {
   

     // Suponha que saldo_cliente e preco_produto são do tipo unsigned int
    unsigned int saldo_cliente = 100;
    unsigned int preco_produto = 200;

    for (int i; i < 10; i++) {

        if (saldo_cliente >= preco_produto) {
            saldo_cliente = saldo_cliente - preco_produto;
            // Processa a compra
        } else {
            cout << "teste";
        }

    }

    cout << "Saldo do Cliente: " << saldo_cliente << endl;
    cout << "FIM";
   
    return 0;
}



