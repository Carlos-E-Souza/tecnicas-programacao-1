#ifndef CARTAO_HPP_INCLUDED
#define CARTAO_HPP_INCLUDED

#include "InterfaceDominio.hpp"

class Cartao : public InterfaceDominio<string>{
    private:
        static const int MAX_LEN = 16;

    public:
        bool setValor(string valor) override;
        bool isValido(string valor) override;
};

#endif // CARTAO_HPP_INCLUDED
