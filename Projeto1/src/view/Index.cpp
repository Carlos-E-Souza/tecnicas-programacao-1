#include "Index.hpp"

using namespace std;

void Index::apresentar() {
    int opcao = 0;

    while(opcao != 0) {
        std::cout << "=== MENU PRINCIPAL ===" endl;
        std::cout << "1. Carteiras" endl;
        std::cout << "2. Ordens" endl;
        std::cout << "3. Conta" endl;
        std::cout << "0. Sair" endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                ctrlCarteira->executar();
                break;
            case 2:
                ctrlOrdem->executar();
                break;
            case 3:
                try {
                    ctrlConta->executar();
                } catch (const ExcecaoSolicitacaoExclusaoConta& e) {
                    std::cout << "\n" << e.what() << "\n";

                    ctrlOrdem->excluirOrdensUsuario();
                    ctrlCarteira->excluirCarteirasUsuario();
                    ctrlConta->excluirConta();

                    std::cout << "Pressione Enter para continuar...\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();

                    ctrlAutenticacao->executar();
                }
                break;

            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    }
}
