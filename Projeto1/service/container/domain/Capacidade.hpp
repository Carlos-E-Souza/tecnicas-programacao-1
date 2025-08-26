#ifndef CAPACIDADE_HPP_INCLUDED
#define CAPACIDADE_HPP_INCLUDED

#include <vector>

#include "InterfaceDominio.hpp"

class Capacidade : public InterfaceDominio<int> {
    private:
        inline static const vector<int> CAP_ENUM = {1, 2, 3, 4};

    public:
        bool setValor(int valor) override;
        bool isValido(int valor) override;
};

#endif // CAPACIDADE_HPP_INCLUDED
