#ifndef RESERVA_HPP_INCLUDED
#define RESERVA_HPP_INCLUDED

#include "domain/Data.hpp"
#include "domain/Dinheiro.hpp"
#include "domain/Codigo.hpp"

class Reserva {
    private:
        Codigo codigo;
        Data chegada;
        Data partida;
        Dinheiro valor;

    public:
        Reserva(string codigo, string chegada, string partida, string valor){
            this->codigo.setValor(codigo);
            this->chegada.setValor(chegada);
            this->partida.setValor(partida);
            this->valor.setValor(valor);
        }

        inline string getCodigo(){
            return codigo.getValor();
        }

        inline string getChegada(){
            return chegada.getValor();
        }

        inline string getPartida(){
            return partida.getValor();
        }

        inline string getValor(){
            return valor.getValor();
        }

        inline bool setCodigo(string codigo){
            return this->codigo.setValor(codigo);
        }

        inline bool setChegada(string chegada){
            return this->chegada.setValor(chegada);
        }

        inline bool setPartida(string partida){
            return this->partida.setValor(partida);
        }

        inline bool setValor(string valor){
            return this->valor.setValor(valor);
        }

        inline string toString(){
            stringstream ss;
            ss << "Reserva: " << endl;
            ss << "  Codigo: " << codigo.getValor() << endl;
            ss << "  Chegada: " << chegada.getValor() << endl;
            ss << "  Partida: " << partida.getValor() << endl;
            ss << "  Valor: " << valor.getValor() << endl;
            return ss.str();
        }
};

#endif // RESERVA_HPP_INCLUDED
