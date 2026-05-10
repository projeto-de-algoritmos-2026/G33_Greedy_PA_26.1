#pragma once

#include <string>

// Retorna diferente de 0 se falhou.
int csv_download(int month, int year);
void csv_erase(int month, int year);
std::string get_file_name(int month, int year);
