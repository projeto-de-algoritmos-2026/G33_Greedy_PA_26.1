#include "csv_download.hpp"
#include "csv_parser.hpp"

#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <chrono>
#include <sstream>

const std::string FORMATS[] = {"%F %T", "%F %H:%M:%S", "%F %R"};

int datetime_to_epoch(const std::string& datetime) {
    std::stringstream ss{datetime};
    std::chrono::sys_time<std::chrono::milliseconds> tp;
    
    if (datetime.size() > 19)       ss >> std::chrono::parse(FORMATS[0], tp);
    else if (datetime.size() == 19) ss >> std::chrono::parse(FORMATS[1], tp);
    else if (datetime.size() == 16) ss >> std::chrono::parse(FORMATS[2], tp);
    
    return std::chrono::floor<std::chrono::seconds>(tp).time_since_epoch().count();
}

std::vector<std::pair<int, int>> csv_parser(int month, int year) {
    std::string file_name = get_file_name(month, year);
    std::ifstream file(file_name);
    std::string line;

    std::vector<std::pair<int, int>> events;
    std::string cur, l, r, l_real, r_real;
    
    while (std::getline(file, line)) {
        if (line.find("SBBR") == std::string::npos) continue;
        
        int cnt = 0;
        
        for (char c : line) {
            if (c == ';') {
                if (cnt == 6) l = cur;
                if (cnt == 7) l_real = cur;
                if (cnt == 8) r = cur;
                if (cnt == 9) r_real = cur;
                cur.clear();
                ++cnt;
            }
            else if (c != '"') cur += c;
        }

        if (l_real.size() >= 16 && std::isdigit(l_real[0])) l = l_real;
        if (r_real.size() >= 16 && std::isdigit(r_real[0])) r = r_real;
        if (l.size() >= 16 && std::isdigit(l[0]) && r.size() >= 16 && std::isdigit(r[0])) {
            int l_epoch = datetime_to_epoch(l);
            int r_epoch = datetime_to_epoch(r);
            events.emplace_back(l_epoch, r_epoch);
        }
    }

    file.close();
    return events;
}