#include "csv_download.hpp"

#include <string>
#include <vector>
#include <filesystem>

const std::string ANAC_URL = "https://sistemas.anac.gov.br/dadosabertos/Voos%20e%20opera%C3%A7%C3%B5es%20a%C3%A9reas/Voo%20Regular%20Ativo%20%28VRA%29/";

const std::string MONTHS[] = {
    "",  // Para indexar de 1.
    "Janeiro",
    "Fevereiro",
    "Março",
    "Abril",
    "Maio",
    "Junho",
    "Julho",
    "Agosto",
    "Setembro",
    "Outubro",
    "Novembro",
    "Dezembro",
};

std::string get_file_name(int month, int year) {
    std::string file_name = "VRA_" + std::to_string(year) + std::to_string(month) + ".csv";
    return file_name;
}

int csv_download(int month, int year) {
    std::string padded_month = (month < 10 ? "0" : "") + std::to_string(month);
    std::string file_name = get_file_name(month, year);
    std::string url = ANAC_URL + std::to_string(year) + "/" + padded_month + "%20-%20" + MONTHS[month] + "/" + file_name;
    std::string command = "curl -f -O \"" + url + "\"";
    int status = std::system(command.c_str());
    return status;
}

void csv_erase(int month, int year) {
    std::filesystem::remove(get_file_name(month, year));
}
