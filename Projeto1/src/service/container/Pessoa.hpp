#ifndef PESSOA_HPP_INCLUDED
#define PESSOA_HPP_INCLUDED

#include <string>

#include "domain/Nome.hpp"
#include "domain/Email.hpp"

class Pessoa {
    protected:
        Nome nome;
        Email email;

    public:
        virtual inline const string getNome() const {
            return nome.getValor();
        }

        virtual inline const string getEmail() const {
            return email.getValor();
        }

        virtual inline void setNome(string nome){
            return this->nome.setValor(nome);
        };

        virtual inline void setEmail(string email){
            return this->email.setValor(email);
        };

        virtual ~Pessoa() = default;
};

#endif // PESSOA_HPP_INCLUDED
