#include "csv_download.hpp"
#include "csv_parser.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <utility>
#include <algorithm>
#include<queue>
#include<fstream>
#include<iomanip>
#include <ctime>
#include <sstream>

void sleep(int seconds) {
   std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

struct VooAlocado{
   int start, finish, route;
};

std::string converter(int tmp){
    std::time_t tempo = tmp; 
    std::tm* tm_info = std::gmtime(&tempo); 
    std::stringstream ss; 
    ss << std::put_time(tm_info, "%d/%m/%Y %H:%M:%S");
    return ss.str(); 
}

int interval_partitioning(std::vector<std::pair<int, int>>& events, int month, int year) {
   std::sort(events.begin(), events.end());
   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> opr;
   std::vector<VooAlocado> ans;
   int next_route = 1;

   for(const auto& voo: events){
       int start = voo.first;
       int finish = voo.second;
       int route;

       if(!opr.empty() && opr.top().first <= start){
           route = opr.top().second;
           opr.pop();
       } else {
           route = next_route++;
       }
       opr.push({finish, route});
       ans.push_back({start, finish, route});
   }

   std::string arquivo= "relatorio_alocacao_" + std::to_string(month) + "_" + std::to_string(year) + ".txt";
   std::ofstream out(arquivo);

   if(out.is_open()){
       out << "Relatório de alocação de rotas - Aeroporto de Brasília - " << month << "/" << year << "\n";
       out << "Total de rotas necessárias: " << next_route-1 << "\n";
       out << "\n";
       out << std::left << std::setw(13) << "Rota"
       << std::left << std::setw(22) << "Chegada"
       << std::left << std::setw(22) << "Partida" << "\n";

       for(const auto&voo: ans){
           out << "Rota " << std::left << std::setw(8) << voo.route 
           << std::left << std::setw(22) << converter(voo.start) 
           << converter(voo.finish) << "\n";
       }
       out.close();
       std::cout << "\033[36m-> Relatorio detalhado gerado em: " << arquivo<< "\033[m" << std::endl;
   }
   return next_route - 1;
}  

int main() {
   int month, year;
   std::cout << "--------------------------- Simulador de Alocação de Rotas Aéreas ---------------------------" << std::endl;
   std::cout << std::endl;

   std::cout << "Vamos puxar dados de voos da ANAC do aeroporto de Brasília da data que você escolher e" << std::endl;
   std::cout << "descobriremos a quantidade mínima de rotas aéreas (as salas do scheduling) que precisariam estar" << std::endl;
   std::cout << "abertas simultaneamente para que esses aviões possam realizar a viagem nesse período escolhido." << std::endl;
   std::cout << std::endl;
   std::cout << "A base de dados utilizada tem informações desde o ano 2000." << std::endl;
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
       std::cout << std::endl;
        
       std::vector<std::pair<int, int>> events = csv_parser(month, year);

       int min_gates = interval_partitioning(events, month, year);
       std::cout << std::endl;
       std::cout << "Número mínimo de rotas necessárias: " << min_gates << std::endl;

       csv_erase(month, year);
       return 0;
   }
}
