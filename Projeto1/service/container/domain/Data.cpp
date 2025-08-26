#include "Data.hpp"

Data::Data(string valor) {
    if(isValido(valor)) {
        this->valor = valor;
    } else {
        throw invalid_argument("Data deve ter formato dia-mes-ano com data valida");
    }
}

bool Data::setValor(string valor) {
    if(isValido(valor)){
        this->valor = valor;
        return true;
    }
    return false;
}

bool Data::isValido(string valor) {
    // Verifica formato b�sico com regex: dia-mes-ano
    regex pattern("^([1-9]|[12][0-9]|3[01])-(JAN|FEV|MAR|ABR|MAI|JUN|JUL|AGO|SET|OUT|NOV|DEZ)-(2[0-9]{3})$");

    if (!regex_match(valor, pattern)) {
        throw invalid_argument("Data deve ter formato dia-mes-ano com data valida");
    }

    // Extrai os componentes da data
    size_t primeira_pos = valor.find('-');
    size_t segunda_pos = valor.find('-', primeira_pos + 1);

    int dia = stoi(valor.substr(0, primeira_pos));
    string mes = valor.substr(primeira_pos + 1, segunda_pos - primeira_pos - 1);
    int ano = stoi(valor.substr(segunda_pos + 1));

    // Verifica se o ano est� no range v�lido
    if (ano < 2000 || ano > 2999) {
        throw invalid_argument("Data deve ter formato dia-mes-ano com data valida");
    }

    // Verifica se o m�s � v�lido
    bool mesValido = false;
    for(const auto& m : MESES) {
        if (mes == m) {
            mesValido = true;
            break;
        }
    }

    if (!mesValido) {
        throw invalid_argument("Data deve ter formato dia-mes-ano com data valida");
    }

    // Verifica se a data � v�lida considerando anos bissextos
    if (!isDataValida(dia, mes, ano)) {
        throw invalid_argument("Data deve ter formato dia-mes-ano com data valida");
    }

    return true;
}

bool Data::isAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool Data::isDataValida(int dia, string mes, int ano) {
    // Verifica se o dia est� no range b�sico
    if (dia < 1 || dia > 31) {
        return false;
    }

    // Obt�m o n�mero m�ximo de dias para o m�s
    int maxDias = MESES_DIAS.at(mes);

    // Ajusta para fevereiro em anos bissextos
    if (mes == "FEV" && isAnoBissexto(ano)) {
        maxDias = 29;
    }

    return dia <= maxDias;
}
