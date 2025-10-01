#ifndef DINHEIRO_HPP_INCLUDED
#define DINHEIRO_HPP_INCLUDED

#include <regex>

#include "InterfaceDominio.hpp"

class Dinheiro : public InterfaceDominio<string> {
    private:
        bool isFormatoValido(string valor);
        double converterParaDouble(string valor);

    public:
        Dinheiro() = default;
        Dinheiro(string valor);

        void isValido(string valor) override;
};

#endif // DINHEIRO_HPP_INCLUDED
