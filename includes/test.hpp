#pragma once

#include "includes/test.hpp"
#include "includes/adventofcode.hpp"

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

TEST_CASE( "Day 1 Part 1 ", "[day1]") {
    REQUIRE(day1p1("1122") == 3);
    REQUIRE(day1p1("1111") == 4);
    REQUIRE(day1p1("1234") == 0);
    REQUIRE(day1p1("91212129") == 9);
}
TEST_CASE( "Day 1 Part 2 ", "[day1]") {
    REQUIRE(day1p2("1212") == 6);
    REQUIRE(day1p2("1221") == 0);
    REQUIRE(day1p2("123425") == 4);
    REQUIRE(day1p2("123123") == 12);
    REQUIRE(day1p2("12131415") == 4);
}

TEST_CASE( "Day 2 Part 1 ", "[day2]") {
    REQUIRE(day2p1({
            {5,1,9,5},
            {7,5,3},
            {2,4,6,8}
          }) == 18);
}
TEST_CASE( "Day 2 Part 2 ", "[day2]") {
    REQUIRE(day2p2({
            {5,9,2,8},
            {9,4,7,3},
            {3,8,6,5}
          }) == 9);
}

TEST_CASE( "Day 3 Part 1 ", "[day3]") {
    // REQUIRE(day3p1(1) == 0); TODO FIX THIS
    REQUIRE(day3p1(12) == 3);
    REQUIRE(day3p1(23) == 2);
    REQUIRE(day3p1(1024) == 31);
}
TEST_CASE( "Day 3 Part 2 ", "[day3]") {
    REQUIRE(day3p2(1) == 2);
    REQUIRE(day3p2(3) == 4);
    REQUIRE(day3p2(100) == 122);
    REQUIRE(day3p2(140) == 142);
    REQUIRE(day3p2(800) == 806);
}
