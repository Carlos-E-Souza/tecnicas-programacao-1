#ifndef TELEFONE_HPP_INCLUDED
#define TELEFONE_HPP_INCLUDED

#include "InterfaceDominio.hpp"

class Telefone : public InterfaceDominio<string> {
    private:
        bool isFormatoValido(string valor);

    public:
        Telefone() = default;
        Telefone(string valor);

        bool setValor(string valor) override;
        bool isValido(string valor) override;
};

#endif // TELEFONE_HPP_INCLUDED
