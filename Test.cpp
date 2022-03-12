/**
 *
 * AUTHORS: <Or cohen>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

TEST_CASE("Good input")
{
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                    "@-------@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-@---@-@\n"
                                                    "@-@@@@@-@\n"
                                                    "@-------@\n"
                                                    "@@@@@@@@@"));

    CHECK(nospaces(mat(5, 1, '@', '-')) == nospaces("@@@@@"));
    CHECK(nospaces(mat(7, 9, '#', '-')) == nospaces("#######\n"
                                                    "#-----#\n"
                                                    "#-###-#\n"
                                                    "#-#-#-#\n"
                                                    "#-#-#-#\n"
                                                    "#-#-#-#\n"
                                                    "#-###-#\n"
                                                    "#-----#\n"
                                                    "#######"));

    CHECK(nospaces(mat(1, 1, '@', '$')) == nospaces("@"));

    CHECK(nospaces(mat(3, 3, '0', '-')) == nospaces("000\n"
                                                    "0-0\n"
                                                    "000"));

    CHECK(nospaces(mat(5, 5, '0', '-')) == nospaces("00000\n"
                                                    "0---0\n"
                                                    "0-0-0\n"
                                                    "0---0\n"
                                                    "00000"));

    CHECK(nospaces(mat(7, 7, '0', '-')) == nospaces("0000000\n"
                                                    "0-----0\n"
                                                    "0-000-0\n"
                                                    "0-0-0-0\n"
                                                    "0-000-0\n"
                                                    "0-----0\n"
                                                    "0000000"));

    CHECK(nospaces(mat(9, 9, '0', '-')) == nospaces("000000000\n"
                                                    "0-------0\n"
                                                    "0-00000-0\n"
                                                    "0-0---0-0\n"
                                                    "0-0-0-0-0\n"
                                                    "0-0---0-0\n"
                                                    "0-00000-0\n"
                                                    "0-------0\n"
                                                    "000000000"));

    CHECK(nospaces(mat(3, 5, '0', '-')) == nospaces("000\n"
                                                    "0-0\n"
                                                    "0-0\n"
                                                    "0-0\n"
                                                    "000"));

    CHECK(nospaces(mat(7, 5, '0', '-')) == nospaces("0000000\n"
                                                    "0-----0\n"
                                                    "0-000-0\n"
                                                    "0-----0\n"
                                                    "0000000"));

    // NOT EQUAL

    CHECK(nospaces(mat(3, 1, '0', '-')) != nospaces("00000")); // Not equal

    CHECK(nospaces(mat(7, 5, '0', '-')) != nospaces("0000000\n"
                                                    "0-----0\n"
                                                    "0-0-0-0\n"
                                                    "0-----0\n"
                                                    "0000000")); // Not equal

    CHECK(nospaces(mat(3, 3, '0', '1')) != nospaces("000\n"
                                                    "000\n"
                                                    "000"));

    CHECK(nospaces(mat(3, 5, '0', '1')) != nospaces("000\n"
                                                    "000\n"
                                                    "000\n"
                                                    "000\n"
                                                    "000"));
    CHECK(nospaces(mat(1, 1, '0', '1')) != nospaces("1"));

}

TEST_CASE("Bad input")
{
    CHECK_THROWS(mat(10, 5, '$', '%'));  // Even number.
    CHECK_THROWS(mat(10, 5, 6, '%'));    // Bad input (number instead of char).
    CHECK_THROWS(mat(3, 3, '$', 6));     // Valid number but wrong char (int instead of char).
    CHECK_THROWS(mat(-1, 3, '0', '-'));  // Negative number, bad input.
    CHECK_THROWS(mat(1, 1, 1, 1));       // int instead of chars
    CHECK_THROWS(mat(-3, -3, '0', '1')); // Negative numbers
}