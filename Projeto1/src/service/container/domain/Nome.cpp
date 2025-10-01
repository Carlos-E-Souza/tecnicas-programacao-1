#include "Nome.hpp"

Nome::Nome(string valor) {
    isValido(valor);
    this->valor = valor;
}

void Nome::isValido(string valor) {
    // Verifica comprimento (5 a 20 caracteres)
    if (valor.length() < 5 || valor.length() > 20) {
        throw invalid_argument("Nome deve ter 5 a 20 caracteres com regras especificas");
    }

    // Verifica se todos os caracteres são válidos
    for (char c : valor) {
        if (!isCaracterValido(c)) {
            throw invalid_argument("Nome deve ter 5 a 20 caracteres com regras especificas");
        }
    }

    // Verifica se o último caractere não é espaço
    if (!isUltimoCaracterValido(valor)) {
        throw invalid_argument("Nome deve ter 5 a 20 caracteres com regras especificas");
    }

    // Verifica se espaço é seguido por letra
    if (!isEspacoSeguidoPorLetra(valor)) {
        throw invalid_argument("Nome deve ter 5 a 20 caracteres com regras especificas");
    }

    // Verifica se primeiro caractere de cada termo é maiúscula
    if (!isPrimeiroCaracterTermoValido(valor)) {
        throw invalid_argument("Nome deve ter 5 a 20 caracteres com regras especificas");
    }

    return;
}

bool Nome::isCaracterValido(char c) {
    // Letra (a-z ou A-Z) ou espaço em branco
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == ' ';
}

bool Nome::isUltimoCaracterValido(string valor) {
    // Último caractere não pode ser espaço em branco
    return valor.back() != ' ';
}

bool Nome::isEspacoSeguidoPorLetra(string valor) {
    for (size_t i = 0; i < valor.length() - 1; i++) {
        char atual = valor[i];
        char proximo = valor[i + 1];

        // Espaço em branco deve ser seguido por letra
        if (atual == ' ') {
            if (!((proximo >= 'a' && proximo <= 'z') ||
                  (proximo >= 'A' && proximo <= 'Z'))) {
                return false;
            }
        }
    }

    return true;
}

bool Nome::isPrimeiroCaracterTermoValido(string valor) {
    // Primeiro caractere da string deve ser maiúscula
    if (!(valor[0] >= 'A' && valor[0] <= 'Z')) {
        return false;
    }

    // Verifica primeiro caractere após cada espaço
    for (size_t i = 0; i < valor.length() - 1; i++) {
        char atual = valor[i];
        char proximo = valor[i + 1];

        // Se encontrar espaço, o próximo caractere deve ser maiúscula
        if (atual == ' ') {
            if (!(proximo >= 'A' && proximo <= 'Z')) {
                return false;
            }
        }
    }

    return true;
}
