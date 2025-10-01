#ifndef RAMAL_HPP_INCLUDED
#define RAMAL_HPP_INCLUDED

#include "InterfaceDominio.hpp"

class Ramal : public InterfaceDominio<string> {
    private:
        bool isFormatoValido(string valor);
        int converterParaInt(string valor);

    public:
        Ramal() = default;
        Ramal(string valor);

        void isValido(string valor) override;
};

#endif // RAMAL_HPP_INCLUDED
