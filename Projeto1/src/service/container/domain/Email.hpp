#ifndef EMAIL_HPP_INCLUDED
#define EMAIL_HPP_INCLUDED

#include <vector>

#include "InterfaceDominio.hpp"

class Email : public InterfaceDominio<string> {
    private:
        bool isParteLocalValida(string parteLocal);
        bool isDominioValido(string dominio);
        bool isPartesDominioValidas(const vector<string>& partes);
        vector<string> split(const string& str, char delimiter);

    public:
        Email() = default;
        Email(string valor);

        void isValido(string valor) override;
};

#endif // EMAIL_HPP_INCLUDED
