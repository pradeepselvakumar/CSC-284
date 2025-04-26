#pragma once

#include <string>
#include <vector>

class CsvParserLib {
public:
    std::vector<std::vector<std::string>> Parse(const std::string& csvContent);
};
