#ifndef GERENTE_HPP_INCLUDED
#define GERENTE_HPP_INCLUDED

#include <sstream>

#include "Pessoa.hpp"
#include "domain/Ramal.hpp"
#include "domain/Senha.hpp"

class Gerente : public Pessoa {
    private:
        Ramal ramal;
        Senha senha;

    public:
        Gerente(string nome, string email, string ramal, string senha){
            this->nome.setValor(nome);
            this->email.setValor(email);
            this->ramal.setValor(ramal);
            this->senha.setValor(senha);
        }

        inline const string getRamal() const {
            return ramal.getValor();
        }

        inline const string getSenha() const {
            return senha.getValor();
        }

        inline void setRamal(string ramal){
            return this->ramal.setValor(ramal);
        }

        inline void setSenha(string senha){
            return this->senha.setValor(senha);
        }

        inline string toString(){
            stringstream ss;
            ss << "Gerente: " << endl;
            ss << "  Nome: " << nome.getValor() << endl;
            ss << "  Email: " << email.getValor() << endl;
            ss << "  Ramal: " << ramal.getValor() << endl;
            ss << "  Senha: " << senha.getValor() << endl;
            return ss.str();
        }
};

#endif // GERENTE_HPP_INCLUDED
