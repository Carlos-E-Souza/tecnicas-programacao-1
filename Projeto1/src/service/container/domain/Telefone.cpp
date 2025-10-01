#include "Telefone.hpp"

Telefone::Telefone(string valor) {
    isValido(valor);
    this->valor = valor;
}

void Telefone::isValido(string valor) {
    // Verifica formato
    if (!isFormatoValido(valor)) {
        throw invalid_argument("Telefone deve ter formato +DDDDDDDDDDDDDD");
    }

    return;
}

bool Telefone::isFormatoValido(string valor) {
    // Deve ter exatamente 15 caracteres (+ seguido de 14 dígitos)
    if (valor.length() != 15) {
        return false;
    }

    // Primeiro caractere deve ser +
    if (valor[0] != '+') {
        return false;
    }

    // Os próximos 14 caracteres devem ser dígitos
    for (size_t i = 1; i < valor.length(); i++) {
        char c = valor[i];
        if (c < '0' || c > '9') {
            return false;
        }
    }

    return true;
}
