#include "csv_download.hpp"
#include "csv_parser.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <utility>

void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int main() {
    int month, year;
    std::cout << "----------- Alocador de portões de embarque -----------" << std::endl;
    std::cout << std::endl;

    std::cout << "Vamos puxar dados de voos da ANAC do aeroporto de Brasília da data que você escolher" << std::endl;
    std::cout << "e descobriremos a quantidade mínima de portões de embarque (as salas do scheduling) que precisariam estar" << std::endl;
    std::cout << "abertos simultaneamente para que esses aviões conseguissem embarcar no aeroporto nesse data escolhida." << std::endl;
    std::cout << std::endl;

    while (true) {
        std::cout << "Escolha a data desejada" << std::endl;
        std::cout << "Mês (e.g.: 2): ";
        std::cin >> month;
        std::cout << "Ano (e.g.: 2026): ";
        std::cin >> year;
        std::cout << std::endl;

        std::cout << "\033[32mIniciando download da base de dados sobre voos aéreos do aeroporto de Brasília via sistema...\033[m" << std::endl;
        std::cout << std::endl;
        
        int status = csv_download(month, year);
        std::cout << std::endl;
        
        if (status != 0) {
            std::cout << "\033[31mFalha no download ou não há dados nesta data." << std::endl;
            sleep(1);
            std::cout << "Tente novamente.\033[m" << std::endl;
            std::cout << std::endl;
            sleep(1);
            continue;
        }

        std::cout << std::endl;
        std::cout << "\033[32mDownload concluído!\033[m" << std::endl;
        
        std::vector<std::pair<int, int>> events = csv_parser(month, year);
        
        // aqui chama o scheduling e tals.
        
        csv_erase(month, year);
        return 0;
    }
}