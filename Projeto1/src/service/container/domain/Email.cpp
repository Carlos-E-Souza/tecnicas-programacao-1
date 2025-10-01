#include "Email.hpp"

Email::Email(string valor) {
    isValido(valor);
    this->valor = valor;
}

void Email::isValido(string valor) {
    // Verifica se cont�m exatamente um @
    size_t pos_arroba = valor.find('@');
    if (pos_arroba == string::npos || valor.find('@', pos_arroba + 1) != string::npos) {
        throw invalid_argument("Email deve ter formato parte-local@dominio com regras especificas");
    }

    // Separa parte local e dom�nio
    string parteLocal = valor.substr(0, pos_arroba);
    string dominio = valor.substr(pos_arroba + 1);

    // Verifica se ambas as partes existem
    if (parteLocal.empty() || dominio.empty()) {
        throw invalid_argument("Email deve ter formato parte-local@dominio com regras especificas");
    }

    // Valida parte local
    if (!isParteLocalValida(parteLocal)) {
        throw invalid_argument("Email deve ter formato parte-local@dominio com regras especificas");
    }

    // Valida dom�nio
    if (!isDominioValido(dominio)) {
        throw invalid_argument("Email deve ter formato parte-local@dominio com regras especificas");
    }

    return;
}

bool Email::isParteLocalValida(string parteLocal) {
    // Verifica comprimento m�ximo (64 caracteres)
    if (parteLocal.length() > 64) {
        return false;
    }

    // Verifica se n�o inicia ou termina com ponto ou h�fen
    if (parteLocal.front() == '.' || parteLocal.front() == '-' ||
        parteLocal.back() == '.' || parteLocal.back() == '-') {
        return false;
    }

    // Verifica cada caractere e regras espec�ficas
    for (size_t i = 0; i < parteLocal.length(); i++) {
        char c = parteLocal[i];

        // Verifica se o caractere � v�lido (a-z, 0-9, . ou -)
        if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '.' || c == '-')) {
            return false;
        }

        // Se for ponto ou h�fen, verifica se � seguido por letra ou d�gito
        if ((c == '.' || c == '-') && i < parteLocal.length() - 1) {
            char proximo = parteLocal[i + 1];
            if (!((proximo >= 'a' && proximo <= 'z') || (proximo >= '0' && proximo <= '9'))) {
                return false;
            }
        }
    }

    return true;
}

bool Email::isDominioValido(string dominio) {
    // Verifica comprimento m�ximo (255 caracteres)
    if (dominio.length() > 255) {
        return false;
    }

    // Separa as partes do dom�nio por ponto
    vector<string> partes = split(dominio, '.');

    // Deve ter pelo menos uma parte
    if (partes.empty()) {
        return false;
    }

    // Valida cada parte do dom�nio
    return isPartesDominioValidas(partes);
}

bool Email::isPartesDominioValidas(const vector<string>& partes) {
    for (const string& parte : partes) {
        // Cada parte n�o pode estar vazia
        if (parte.empty()) {
            return false;
        }

        // N�o pode iniciar ou terminar com h�fen
        if (parte.front() == '-' || parte.back() == '-') {
            return false;
        }

        // Verifica cada caractere da parte
        for (char c : parte) {
            // Deve conter apenas a-z, 0-9 ou h�fen
            if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-')) {
                return false;
            }
        }
    }

    return true;
}

vector<string> Email::split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;

    for (char c : str) {
        if (c == delimiter) {
            tokens.push_back(token);
            token.clear();
        } else {
            token += c;
        }
    }

    // Adiciona o �ltimo token
    tokens.push_back(token);

    return tokens;
}
