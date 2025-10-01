#ifndef HOTEL_HPP_INCLUDED
#define HOTEL_HPP_INCLUDED

#include <sstream>
#include <string>

#include "domain/Codigo.hpp"
#include "domain/Nome.hpp"
#include "domain/Endereco.hpp"
#include "domain/Telefone.hpp"

using namespace std;

class Hotel{
    private:
        Codigo codigo;
        Nome nome;
        Endereco endereco;
        Telefone telefone;


    public:
        Hotel(string codigo, string nome, string endereco, string telefone){
            this->codigo.setValor(codigo);
            this->nome.setValor(nome);
            this->endereco.setValor(endereco);
            this->telefone.setValor(telefone);
        }

        inline string getCodigo(){
            return codigo.getValor();
        }

        inline string getNome(){
            return nome.getValor();
        }

        inline string getEndereco(){
            return endereco.getValor();
        }

        inline string getTelefone(){
            return telefone.getValor();
        }

        inline bool setCodigo(string codigo){
            return this->codigo.setValor(codigo);
        }

        inline bool setNome(string nome){
            return this->nome.setValor(nome);
        }

        inline bool setEndereco(string endereco){
            return this->endereco.setValor(endereco);
        }

        inline bool setTelefone(string telefone){
            return this->telefone.setValor(telefone);
        }

        inline string toString(){
            stringstream ss;
            ss << "Hotel::Hotel: " << endl;
            ss << "  Codigo: " << codigo.getValor() << endl;
            ss << "  Nome: " << nome.getValor() << endl;
            ss << "  Endereco: " << endereco.getValor() << endl;
            ss << "  Telefone: " << telefone.getValor() << endl;
            return ss.str();
        }
};

#endif // HOTEL_HPP_INCLUDED
