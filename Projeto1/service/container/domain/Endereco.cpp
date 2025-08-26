#include "Endereco.hpp"

Endereco::Endereco(string valor) {
    if(isValido(valor)) {
        this->valor = valor;
    } else {
        throw invalid_argument("Endereco deve ter 5 a 30 caracteres com regras especificas");
    }
}

bool Endereco::setValor(string valor) {
    if(isValido(valor)){
        this->valor = valor;
        return true;
    }
    return false;
}

bool Endereco::isValido(string valor) {
    // Verifica comprimento (5 a 30 caracteres)
    if (valor.length() < 5 || valor.length() > 30) {
        throw invalid_argument("Endereco deve ter 5 a 30 caracteres com regras especificas");
    }

    // Verifica se todos os caracteres são válidos
    for (char c : valor) {
        if (!isCaracterValido(c)) {
            throw invalid_argument("Endereco deve ter 5 a 30 caracteres com regras especificas");
        }
    }

    // Verifica primeiro e último caractere
    if (!isPrimeiroUltimoCaracterValido(valor)) {
        throw invalid_argument("Endereco deve ter 5 a 30 caracteres com regras especificas");
    }

    // Verifica sequências de caracteres especiais
    if (!isSequenciaValida(valor)) {
        throw invalid_argument("Endereco deve ter 5 a 30 caracteres com regras especificas");
    }

    return true;
}

bool Endereco::isCaracterValido(char c) {
    // Letra (a-z ou A-Z), dígito (0-9), vírgula, ponto ou espaço em branco
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9') ||
           c == ',' ||
           c == '.' ||
           c == ' ';
}

bool Endereco::isPrimeiroUltimoCaracterValido(string valor) {
    char primeiro = valor.front();
    char ultimo = valor.back();

    // Primeiro e último caractere não podem ser vírgula, ponto ou espaço
    if (primeiro == ',' || primeiro == '.' || primeiro == ' ') {
        return false;
    }

    if (ultimo == ',' || ultimo == '.' || ultimo == ' ') {
        return false;
    }

    return true;
}

bool Endereco::isSequenciaValida(string valor) {
    for (size_t i = 0; i < valor.length() - 1; i++) {
        char atual = valor[i];
        char proximo = valor[i + 1];

        // Vírgula não pode ser seguida por vírgula ou ponto
        if (atual == ',') {
            if (proximo == ',' || proximo == '.') {
                return false;
            }
        }

        // Ponto não pode ser seguido por vírgula ou ponto
        if (atual == '.') {
            if (proximo == ',' || proximo == '.') {
                return false;
            }
        }

        // Espaço em branco deve ser seguido por letra ou dígito
        if (atual == ' ') {
            if (!((proximo >= 'a' && proximo <= 'z') ||
                  (proximo >= 'A' && proximo <= 'Z') ||
                  (proximo >= '0' && proximo <= '9'))) {
                return false;
            }
        }
    }

    return true;
}
