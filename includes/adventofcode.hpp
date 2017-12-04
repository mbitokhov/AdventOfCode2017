#pragma once

#include <vector>
#include <cstring>


constexpr long day1p1(const char input[], const size_t &index=0);
constexpr long day1p2(const char input[], const size_t &index=0);
long day2p1(const std::vector<std::vector<int>>&);
long day2p2(const std::vector<std::vector<int>>&);
long day3p1(const long&);
long day3p2(const long&);


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
