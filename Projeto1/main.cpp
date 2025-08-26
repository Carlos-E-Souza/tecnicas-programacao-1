#include <iostream>
#include <stdexcept>

#include "service/container/domain/Capacidade.hpp"
#include "service/container/domain/Cartao.hpp"
#include "service/container/domain/Codigo.hpp"

using namespace std;

int main()
{
    int num;
    string cartNum;
    cout << "Hello world!" << endl;

    Capacidade cap;
    cout << "Capacidade: ";
    cin >> num;
    cout << endl;

    Cartao cartao;
    //Valido: 1234567890123452
    cout << "Cartao: ";
    cin >> cartNum;
    cout << endl;
    try {
        cap.setValor(num);
        cout << "Capacidade valor: " << cap.getValor() << endl;

        cartao.setValor(cartNum);
        cout << "Cartao Digito: " << cartao.getValor() << endl;
    } catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << endl;
    }

    string cod;
    cout << "Codigo: ";
    cin >> cod;
    cout << endl;

    Codigo codi;

    try {
        codi.setValor(cod);
        cout << "Valor: " << codi.getValor() << endl;
    } catch(invalid_argument &exp){
        cout << "Excecao: " << exp.what() << endl;
    }

    return 0;
}
