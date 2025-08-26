#ifndef ENDERECO_HPP_INCLUDED
#define ENDERECO_HPP_INCLUDED

#include "InterfaceDominio.hpp"

class Endereco : public InterfaceDominio<string> {
    private:
        bool isCaracterValido(char c);
        bool isSequenciaValida(string valor);
        bool isPrimeiroUltimoCaracterValido(string valor);

    public:
        Endereco() = default;
        Endereco(string valor);

        bool setValor(string valor) override;
        bool isValido(string valor) override;
};

#endif // ENDERECO_HPP_INCLUDED
