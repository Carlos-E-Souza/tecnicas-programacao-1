#include "Codigo.hpp"

Codigo::Codigo(string valor) {
    isValido(valor);
    this->valor = valor;
}

void Codigo::isValido(string valor) {
    regex pattern("^[a-z1-9]{10}$");
    bool result = regex_match(valor, pattern);
    if(!result) {
        throw invalid_argument("O codigo deve ter 10 digitos composto por letras e numeros");
    }
    return;
}
