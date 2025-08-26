#include "Codigo.hpp"

Codigo::Codigo(string valor) {
    if(isValido(valor)) {
        this->valor = valor;
    } else {
        throw invalid_argument("O codigo deve ter 10 digitos composto por letras e numeros");
    }
}

bool Codigo::setValor(string valor) {
    if(isValido(valor)){
        this->valor = valor;
        return true;
    }
    return false;
}

bool Codigo::isValido(string valor) {
    regex pattern("^[a-z1-9]{10}$");
    bool result = regex_match(valor, pattern);
    if(!result) {
        throw invalid_argument("O codigo deve ter 10 digitos composto por letras e numeros");
    }
    return true;
}
