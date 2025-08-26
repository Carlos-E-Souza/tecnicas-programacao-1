#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include "InterfaceDominio.hpp"

class Nome : public InterfaceDominio<string> {
    private:
        bool isCaracterValido(char c);
        bool isPrimeiroCaracterTermoValido(string valor);
        bool isEspacoSeguidoPorLetra(string valor);
        bool isUltimoCaracterValido(string valor);

    public:
        Nome() = default;
        Nome(string valor);

        bool setValor(string valor) override;
        bool isValido(string valor) override;
};

#endif // NOME_HPP_INCLUDED
