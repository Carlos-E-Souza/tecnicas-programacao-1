#ifndef CODIGO_HPP_INCLUDED
#define CODIGO_HPP_INCLUDED

#include <regex>

#include "InterfaceDominio.hpp"

class Codigo : public InterfaceDominio<string> {
    public:
        Codigo() = default;
        Codigo(string valor);

        void isValido(string valor) override;
};

#endif // CODIGO_HPP_INCLUDED
