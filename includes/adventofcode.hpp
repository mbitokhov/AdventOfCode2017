#pragma once

#include <vector>
#include <cstring>
#include <string>


constexpr long day1p1(const char input[], const size_t &index=0);
constexpr long day1p2(const char input[], const size_t &index=0);
long day2p1(const std::vector<std::vector<int>>&);
long day2p2(const std::vector<std::vector<int>>&);
long day3p1(const long&);
long day3p2(const long&);
long day4p1(const std::vector<std::vector<std::string>>&);
long day4p2(const std::vector<std::vector<std::string>>&);
unsigned long day5p1(std::vector<int>);
unsigned long day5p2(std::vector<int>);
long day6p1(std::vector<int>);
long day6p2(std::vector<int>);
std::string day7p1(std::vector<std::vector<std::string>>);
long        day7p2(std::vector<std::vector<std::string>>);
long day8p1(std::vector<std::vector<std::string>>);
long day8p2(std::vector<std::vector<std::string>>);
long day9p1(std::string);
long day9p2(const std::string&);
long day10p1(const std::vector<int> &input);
std::string day10p2(std::string input);
long day11p1(const std::vector<std::string> &input);
long day11p2(const std::vector<std::string> &input);

constexpr long day1p1(const char input[], const size_t &index)
{
    /*
     * Sum up integers that are the same as the the value ahead of them
     *
     * This code is the same as the following
     * if(input[index != 0]) {
     *     if(input[index] == input[(index+1) % strlen(input)]) {
     *         return (input[index] - '0') + day1p1(input,index+1);
     *     } else {
     *         return day1p1(input,index+1);
     *     }
     * } else {
     *     return 0;
     * }
     */
    return (input[index] != 0) ?
      (
        (
         (input[index] == input[(index + 1) % strlen(input)]) ?
          input[index] - '0':
          0
        ) + day1p1(input, index+1)
      ): 0;
}

constexpr long day1p2(const char input[], const size_t &index)
{
    /*
     * Sum up integers that are the same as the the value half way
     * around the list
     *
     * This code is the same as the following
     * if(input[index != 0]) {
     *     if(input[index] == input[(index+ strlen(input)/2) % strlen(input)]) {
     *         return (input[index] - '0') + day1p2(input,index+1);
     *     } else {
     *         return day1p2(input,index+1);
     *     }
     * } else {
     *     return 0;
     * }
     */
    return (input[index] != 0) ?
      (
        (
         (input[index] == input[(index + (strlen(input) / 2)) % strlen(input)]) ?
          input[index] - '0':
          0
        ) + day1p2(input, index+1)
      ): 0;
}
