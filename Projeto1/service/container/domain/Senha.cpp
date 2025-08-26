#include "Senha.hpp"

Senha::Senha(string valor) {
    if(isValido(valor)) {
        this->valor = valor;
    } else {
        throw invalid_argument("Senha deve ter 5 caracteres com regras especificas");
    }
}

bool Senha::setValor(string valor) {
    if(isValido(valor)){
        this->valor = valor;
        return true;
    }
    return false;
}

bool Senha::isValido(string valor) {
    // Verifica se tem exatamente 5 caracteres
    if (valor.length() != 5) {
        throw invalid_argument("Senha deve ter 5 caracteres com regras especificas");
    }

    // Verifica se todos os caracteres são válidos
    for (char c : valor) {
        if (!isCaracterValido(c)) {
            throw invalid_argument("Senha deve ter 5 caracteres com regras especificas");
        }
    }

    // Verifica se as sequências são válidas
    if (!isSequenciaValida(valor)) {
        throw invalid_argument("Senha deve ter 5 caracteres com regras especificas");
    }

    // Verifica se tem todos os requisitos
    if (!temTodosRequisitos(valor)) {
        throw invalid_argument("Senha deve ter 5 caracteres com regras especificas");
    }

    return true;
}

bool Senha::isCaracterValido(char c) {
    return isLetraMinuscula(c) ||
           isLetraMaiuscula(c) ||
           isDigito(c) ||
           isCaracterEspecial(c);
}

bool Senha::isLetraMinuscula(char c) {
    return c >= 'a' && c <= 'z';
}

bool Senha::isLetraMaiuscula(char c) {
    return c >= 'A' && c <= 'Z';
}

bool Senha::isDigito(char c) {
    return c >= '0' && c <= '9';
}

bool Senha::isCaracterEspecial(char c) {
    return CARACTERES_ESPECIAIS.find(c) != string::npos;
}

bool Senha::isSequenciaValida(string valor) {
    for (size_t i = 0; i < valor.length() - 1; i++) {
        char atual = valor[i];
        char proximo = valor[i + 1];

        // Letra não pode ser seguida por letra
        if ((isLetraMinuscula(atual) || isLetraMaiuscula(atual)) &&
            (isLetraMinuscula(proximo) || isLetraMaiuscula(proximo))) {
            return false;
        }

        // Dígito não pode ser seguido por dígito
        if (isDigito(atual) && isDigito(proximo)) {
            return false;
        }
    }

    return true;
}

bool Senha::temTodosRequisitos(string valor) {
    bool temMinuscula = false;
    bool temMaiuscula = false;
    bool temDigito = false;
    bool temEspecial = false;

    for (char c : valor) {
        if (isLetraMinuscula(c)) {
            temMinuscula = true;
        }
        else if (isLetraMaiuscula(c)) {
            temMaiuscula = true;
        }
        else if (isDigito(c)) {
            temDigito = true;
        }
        else if (isCaracterEspecial(c)) {
            temEspecial = true;
        }
    }

    // Deve ter pelo menos uma de cada tipo
    return temMinuscula && temMaiuscula && temDigito && temEspecial;
}
