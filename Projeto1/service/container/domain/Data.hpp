#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED

#include <map>
#include <regex>

#include "InterfaceDominio.hpp"

class Data : public InterfaceDominio<string> {
    private:
        inline static const vector<string> MESES = {
            "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
            "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
        };
        inline static const map<string, int> MESES_DIAS = {
            {"JAN", 31}, {"FEV", 28}, {"MAR", 31}, {"ABR", 30},
            {"MAI", 31}, {"JUN", 30}, {"JUL", 31}, {"AGO", 31},
            {"SET", 30}, {"OUT", 31}, {"NOV", 30}, {"DEZ", 31}
        };

        bool isAnoBissexto(int ano);
        bool isDataValida(int dia, string mes, int ano);

    public:
        Data() = default;
        Data(string valor);

        bool setValor(string valor) override;
        bool isValido(string valor) override;
};

#endif // DATA_HPP_INCLUDED
