#include "Ramal.hpp"

Ramal::Ramal(string valor) {
    if(isValido(valor)) {
        this->valor = valor;
    } else {
        throw invalid_argument("Ramal deve estar entre 00 e 50");
    }
}

bool Ramal::setValor(string valor) {
    if(isValido(valor)){
        this->valor = valor;
        return true;
    }
    return false;
}

bool Ramal::isValido(string valor) {
    // Verifica formato (deve ter exatamente 2 dígitos)
    if (!isFormatoValido(valor)) {
        throw invalid_argument("Ramal deve estar entre 00 e 50");
    }

    // Converte para inteiro para verificar o range
    int valorNumerico = converterParaInt(valor);

    // Verifica se está no range válido (00 a 50, ou seja, 0 a 50)
    if (valorNumerico < 0 || valorNumerico > 50) {
        throw invalid_argument("Ramal deve estar entre 00 e 50");
    }

    return true;
}

bool Ramal::isFormatoValido(string valor) {
    // Deve ter exatamente 2 caracteres
    if (valor.length() != 2) {
        return false;
    }

    // Todos os caracteres devem ser dígitos
    for (char c : valor) {
        if (c < '0' || c > '9') {
            return false;
        }
    }

    return true;
}

int Ramal::converterParaInt(string valor) {
    return stoi(valor);
}
