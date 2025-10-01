#ifndef QUARTO_HPP_INCLUDED
#define QUARTO_HPP_INCLUDED

#include <sstream>
#include <string>

#include "domain/Numero.hpp"
#include "domain/Capacidade.hpp"
#include "domain/Dinheiro.hpp"
#include "domain/Ramal.hpp"

using namespace std;

class Quarto {
    private:
        Numero numero;
        Capacidade capacidade;
        Dinheiro diaria;
        Ramal ramal;

    public:
        Quarto(string numero, string capacidade, string diaria, string ramal){
            this->numero.setValor(numero);
            this->capacidade.setValor(capacidade);
            this->diaria.setValor(diaria);
            this->ramal.setValor(ramal);
        }

        inline string getNumero(){
            return numero.getValor();
        }

        inline string getCapacidade(){
            return capacidade.getValor();
        }

        inline string getDiaria(){
            return diaria.getValor();
        }

        inline string getRamal(){
            return ramal.getValor();
        }

        inline bool setNumero(string numero){
            return this->numero.setValor(numero);
        }

        inline bool setCapacidade(string capacidade){
            return this->capacidade.setValor(capacidade);
        }

        inline bool setDiaria(string diaria){
            return this->diaria.setValor(diaria);
        }

        inline bool setRamal(string ramal){
            return this->ramal.setValor(ramal);
        }

        inline string toString(){
            stringstream ss;
            ss << "Quarto: " << endl;
            ss << "  Numero: " << numero.getValor() << endl;
            ss << "  Capacidade: " << capacidade.getValor() << endl;
            ss << "  Diaria: " << diaria.getValor() << endl;
            ss << "  Ramal: " << ramal.getValor() << endl;
            return ss.str();
        }
};
#endif // QUARTO_HPP_INCLUDED
