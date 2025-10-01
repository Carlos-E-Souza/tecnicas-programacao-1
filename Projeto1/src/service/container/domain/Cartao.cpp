#include "Cartao.hpp"

void Cartao::isValido(string valor) {
    if(valor.length() != Cartao::MAX_LEN) {
        throw invalid_argument("Cartao deve ter 16 digitos");
    }
    int sum = 0;
    bool alternar = false;

    // -2 para remover o digito verificador
    for(int i = valor.length() - 2; i >= 0; i--){
        if(valor[i] < '0' || valor[i] > '9') {
            throw invalid_argument("Cartao deve conter apenas digitos");
        }

        int digito = valor[i] - '0'; // Converte char -> int
        if(alternar){
            digito *= 2;
            // Somar os digitos caso tenha 2 digitos
            if(digito > 9){
                digito = (digito / 10) + (digito % 10);
            }
        }
        sum += digito;
        alternar = !alternar;
    }

    int digitoVerificador = valor[Cartao::MAX_LEN - 1] - '0';
    bool valido = ((10 - (sum % 10)) % 10) == digitoVerificador;
    if(!valido) throw invalid_argument("Digito verificador do cartao e invalido");
}
