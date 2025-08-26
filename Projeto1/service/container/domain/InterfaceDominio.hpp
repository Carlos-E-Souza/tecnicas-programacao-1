#ifndef INTERFACEDOMINIO_HPP_INCLUDED
#define INTERFACEDOMINIO_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

template<typename T> class InterfaceDominio {
    protected:
        T valor;

    public:
        virtual T getValor(){
            return valor;
        };

        virtual bool setValor(T valor) = 0;
        virtual bool isValido(T valor) = 0;
        virtual ~InterfaceDominio() = default;
};

#endif // INTERFACEDOMINIO_HPP_INCLUDED
