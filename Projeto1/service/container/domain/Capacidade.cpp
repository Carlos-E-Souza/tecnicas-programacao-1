#include "Capacidade.hpp"

bool Capacidade::setValor(int valor){
    if(Capacidade::isValido(valor)) {
        this->valor = valor;
        return true;
    }
    throw invalid_argument("A capacidade so vai de 1 a 4");
}

bool Capacidade::isValido(int valor){
    for(auto& num : Capacidade::CAP_ENUM) {
        if (valor == num) {
            return true;
        }
    }
    return false;
}
