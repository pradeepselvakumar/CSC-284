#include "gtest/gtest.h"
#include "../CsvParserLib/CsvParserLib.h"  // Adjust path as needed

TEST(CsvParserTest, SimpleUnquotedFields) {
    CsvParserLib parser;
    std::string csv = "a,b,c\n1,2,3";
    auto result = parser.Parse(csv);

    // TODO: Assert that result has 2 rows
    // TODO: Assert that the first row contains "a", "b", "c"
    // TODO: Assert that the second row contains "1", "2", "3"
}

TEST(CsvParserTest, QuotedFieldsWithCommas) {
    CsvParserLib parser; 
    std::string csv = "\"a,1\",b,c\nx,\"y,z\",w";
    auto result = parser.Parse(csv);

    // TODO: Assert that result has 2 rows
    // TODO: Assert that the first row contains "a,1", "b", "c"
    // TODO: Assert that the second row contains "x", "y,z", "w"
}

TEST(CsvParserTest, EscapedQuotes) {
    CsvParserLib parser;
    std::string csv = "\"He said \"\"hello\"\"\",123";
    auto result = parser.Parse(csv);

    // TODO: Assert that result has 1 row
    // TODO: Assert that the row contains 'He said "hello"' and "123"
}

TEST(CsvParserTest, MixedQuotedAndUnquotedFields) {
    CsvParserLib parser;
    std::string csv = "one,\"two, three\",four";
    auto result = parser.Parse(csv);

    // TODO: Assert that result has 1 row
    // TODO: Assert that the row contains "one", "two, three", and "four"
}

TEST(CsvParserTest, EmptyFields) {
    CsvParserLib parser;
    std::string csv = "a,,c\n,,";
    auto result = parser.Parse(csv);

    // TODO: Assert that result has 2 rows
    // TODO: Assert that the first row contains "a", "", "c"
    // TODO: Assert that the second row contains "", "", ""
}
