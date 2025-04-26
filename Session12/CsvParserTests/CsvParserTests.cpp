#include "gtest/gtest.h"
#include "../CsvParserLib/CsvParserLib.h"  // Adjust path as needed

TEST(CsvParserTest, SimpleUnquotedFields) {
    CsvParserLib parser;
    std::string csv = "a,b,c\n1,2,3";
    auto result = parser.Parse(csv);

    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], (std::vector<std::string>{"a", "b", "c"}));
    EXPECT_EQ(result[1], (std::vector<std::string>{"1", "2", "3"}));
}

TEST(CsvParserTest, QuotedFieldsWithCommas) {
    CsvParserLib parser;
    std::string csv = "\"a,1\",b,c\nx,\"y,z\",w";
    auto result = parser.Parse(csv);

    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], (std::vector<std::string>{"a,1", "b", "c"}));
    EXPECT_EQ(result[1], (std::vector<std::string>{"x", "y,z", "w"}));
}

TEST(CsvParserTest, EscapedQuotes) {
    CsvParserLib parser;
    std::string csv = "\"He said \"\"hello\"\"\",123";
    auto result = parser.Parse(csv);

    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], (std::vector<std::string>{"He said \"hello\"", "123"}));
}

TEST(CsvParserTest, MixedQuotedAndUnquotedFields) {
    CsvParserLib parser;
    std::string csv = "one,\"two, three\",four";
    auto result = parser.Parse(csv);

    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], (std::vector<std::string>{"one", "two, three", "four"}));
}

TEST(CsvParserTest, EmptyFields) {
    CsvParserLib parser;
    std::string csv = "a,,c\n,,";
    auto result = parser.Parse(csv);

    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], (std::vector<std::string>{"a", "", "c"}));
    EXPECT_EQ(result[1], (std::vector<std::string>{"", "", ""}));
}
