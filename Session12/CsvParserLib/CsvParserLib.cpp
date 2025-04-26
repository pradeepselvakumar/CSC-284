#include "CsvParserLib.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

std::vector<std::vector<std::string>> CsvParserLib::Parse(const std::string& csvContent) {
    std::vector<std::vector<std::string>> rows;
    std::istringstream stream(csvContent);
    std::string line;

    while (std::getline(stream, line)) {
        std::vector<std::string> row;
        std::string field;
        bool insideQuotes = false;
        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];

            if (c == '"') {
                if (insideQuotes && i + 1 < line.size() && line[i + 1] == '"') {
                    field += '"'; // Escaped quote
                    ++i;
                }
                else {
                    insideQuotes = !insideQuotes;
                }
            }
            else if (c == ',' && !insideQuotes) {
                row.push_back(field);
                field.clear();
            }
            else {
                field += c;
            }
        }
        row.push_back(field);
        rows.push_back(row);
    }

    return rows;
}