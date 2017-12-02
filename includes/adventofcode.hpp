#pragma once

#include <cstring>


constexpr long day1p1(const char input[], const size_t &index=0);
constexpr long day1p2(const char input[], const size_t &index=0);



constexpr long day1p1(const char input[], const size_t &index)
{
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
    return (input[index] != 0) ?
      (
        (
         (input[index] == input[(index + (strlen(input) / 2)) % strlen(input)]) ?
          input[index] - '0':
          0
        ) + day1p2(input, index+1)
      ): 0;
}
