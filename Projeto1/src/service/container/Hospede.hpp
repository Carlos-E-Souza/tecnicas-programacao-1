#ifndef HOSPEDE_HPP_INCLUDED
#define HOSPEDE_HPP_INCLUDED

#include <sstream>

#include "Pessoa.hpp"
#include "domain/Endereco.hpp"
#include "domain/Cartao.hpp"

class Hospede : public Pessoa {
    private:
        Endereco endereco;
        Cartao cartao;

    public:
        Hospede(string nome, string email, string endereco, string cartao){
            this->nome.setValor(nome);
            this->email.setValor(email);
            this->endereco.setValor(endereco);
            this->cartao.setValor(cartao);
        }

        inline string getEndereco(){
            return endereco.getValor();
        }

        inline string getCartao(){
            return cartao.getValor();
        }

        inline bool setEndereco(string endereco){
            return this->endereco.setValor(endereco);
        }

        inline bool setCartao(string cartao){
            return this->cartao.setValor(cartao);
        }

        inline string toString(){
            stringstream ss;
            ss << "Hospede: " << endl;
            ss << "  Nome: " << nome.getValor() << endl;
            ss << "  Email: " << email.getValor() << endl;
            ss << "  Endereco: " << endereco.getValor() << endl;
            ss << "  Cartao: " << cartao.getValor() << endl;
            return ss.str();
        }
};

#endif // HOSPEDE_HPP_INCLUDED
