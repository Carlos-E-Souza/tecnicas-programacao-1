#include <sstream>
#include <iomanip>

#include "Dinheiro.hpp"

Dinheiro::Dinheiro(string valor) {
    isValido(valor);
    this->valor = valor;
}

void Dinheiro::isValido(string valor) {
    // Verifica formato básico
    if (!isFormatoValido(valor)) {
        throw invalid_argument("Dinheiro deve estar entre 0,01 e 1.000.000,00");
    }

    // Converte para double para verificar o range
    double valorNumerico = converterParaDouble(valor);

    // Verifica se está no range válido (0,01 a 1.000.000,00)
    if (valorNumerico < 0.01 || valorNumerico > 1000000.00) {
        throw invalid_argument("Dinheiro deve estar entre 0,01 e 1.000.000,00");
    }

    return;
}

bool Dinheiro::isFormatoValido(string valor) {
    // Regex para valores monetários com ponto como separador de milhares e vírgula como decimal
    regex pattern("^([1-9]\\d{0,2}(\\.\\d{3})*(,\\d{2})|[1-9]\\d*(,\\d{2})|0,\\d[1-9]|0,[1-9]\\d)$");

    if (!regex_match(valor, pattern)) {
        return false;
    }

    // Verifica se tem exatamente 2 casas decimais após a vírgula
    size_t pos_virgula = valor.find(',');
    if (pos_virgula == string::npos) {
        return false;
    }

    string parte_decimal = valor.substr(pos_virgula + 1);
    if (parte_decimal.length() != 2) {
        return false;
    }

    return true;
}

double Dinheiro::converterParaDouble(string valor) {
    string valorLimpo = valor;

    // Remove pontos (separadores de milhares)
    size_t pos = 0;
    while ((pos = valorLimpo.find('.', pos)) != string::npos) {
        valorLimpo.erase(pos, 1);
    }

    // Substitui vírgula por ponto (separador decimal)
    pos = valorLimpo.find(',');
    if (pos != string::npos) {
        valorLimpo[pos] = '.';
    }

    return stod(valorLimpo);
}
