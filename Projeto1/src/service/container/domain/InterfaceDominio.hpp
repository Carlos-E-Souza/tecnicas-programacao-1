#ifndef INTERFACEDOMINIO_HPP_INCLUDED
#define INTERFACEDOMINIO_HPP_INCLUDED

#include <string>
#include <stdexcept>

using namespace std;

template<typename T> class InterfaceDominio {
    protected:
        T valor;

    public:
        virtual inline const T getValor() const {
            return valor;
        };

        virtual inline void setValor(T valor){
            isValido(valor);
            this->valor = valor;
        };
        virtual void isValido(T valor) = 0;
        virtual ~InterfaceDominio() = default;
};

#endif // INTERFACEDOMINIO_HPP_INCLUDED
