#include "Capacidade.hpp"

void Capacidade::isValido(int valor) {
    for(auto& num : Capacidade::CAP_ENUM) {
        if (valor == num) {
            return;
        }
    }
    throw invalid_argument("A capacidade so vai de 1 a 4");
}
