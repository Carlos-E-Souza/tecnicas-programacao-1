#ifndef NUMERO_HPP_INCLUDED
#define NUMERO_HPP_INCLUDED

#include "InterfaceDominio.hpp"

class Numero : public InterfaceDominio<string> {
    private:
        bool isFormatoValido(string valor);
        int converterParaInt(string valor);

    public:
        Numero() = default;
        Numero(string valor);

        void isValido(string valor) override;
};

#endif // NUMERO_HPP_INCLUDED
