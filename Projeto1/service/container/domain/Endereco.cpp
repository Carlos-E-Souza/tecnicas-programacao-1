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

    // Verifica se todos os caracteres s�o v�lidos
    for (char c : valor) {
        if (!isCaracterValido(c)) {
            throw invalid_argument("Endereco deve ter 5 a 30 caracteres com regras especificas");
        }
    }

    // Verifica primeiro e �ltimo caractere
    if (!isPrimeiroUltimoCaracterValido(valor)) {
        throw invalid_argument("Endereco deve ter 5 a 30 caracteres com regras especificas");
    }

    // Verifica sequ�ncias de caracteres especiais
    if (!isSequenciaValida(valor)) {
        throw invalid_argument("Endereco deve ter 5 a 30 caracteres com regras especificas");
    }

    return true;
}

bool Endereco::isCaracterValido(char c) {
    // Letra (a-z ou A-Z), d�gito (0-9), v�rgula, ponto ou espa�o em branco
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

    // Primeiro e �ltimo caractere n�o podem ser v�rgula, ponto ou espa�o
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

        // V�rgula n�o pode ser seguida por v�rgula ou ponto
        if (atual == ',') {
            if (proximo == ',' || proximo == '.') {
                return false;
            }
        }

        // Ponto n�o pode ser seguido por v�rgula ou ponto
        if (atual == '.') {
            if (proximo == ',' || proximo == '.') {
                return false;
            }
        }

        // Espa�o em branco deve ser seguido por letra ou d�gito
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
