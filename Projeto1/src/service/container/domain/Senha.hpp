#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include "InterfaceDominio.hpp"

class Senha : public InterfaceDominio<string> {
    private:
        inline static const string CARACTERES_ESPECIAIS = "!\"#$%&?";
        bool isCaracterValido(char c);
        bool isLetraMinuscula(char c);
        bool isLetraMaiuscula(char c);
        bool isDigito(char c);
        bool isCaracterEspecial(char c);
        bool isSequenciaValida(string valor);
        bool temTodosRequisitos(string valor);

    public:
        Senha() = default;
        Senha(string valor);

        void isValido(string valor) override;
};

#endif // SENHA_HPP_INCLUDED
