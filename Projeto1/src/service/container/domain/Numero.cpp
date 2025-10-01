#include "Numero.hpp"

Numero::Numero(string valor) {
    isValido(valor);
    this->valor = valor;
}

void Numero::isValido(string valor) {
    // Verifica formato (deve ter exatamente 3 dígitos)
    if (!isFormatoValido(valor)) {
        throw invalid_argument("Numero deve estar entre 001 e 999");
    }

    // Converte para inteiro para verificar o range
    int valorNumerico = converterParaInt(valor);

    // Verifica se está no range válido (001 a 999, ou seja, 1 a 999)
    if (valorNumerico < 1 || valorNumerico > 999) {
        throw invalid_argument("Numero deve estar entre 001 e 999");
    }

    return;
}

bool Numero::isFormatoValido(string valor) {
    // Deve ter exatamente 3 caracteres
    if (valor.length() != 3) {
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

int Numero::converterParaInt(string valor) {
    return stoi(valor);
}
