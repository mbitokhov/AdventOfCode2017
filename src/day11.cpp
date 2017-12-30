#include "includes/adventofcode.hpp"

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <unordered_map>
#include "includes/helpers.hpp"
#include <climits>


struct hex_position {
  int x=0;
  int y=0;
  int z=0;
};

enum movement {
  NW,
  N,
  NE,
  SW,
  S,
  SE
};

inline void day11_perform(const movement &mov, hex_position &position)
{
    switch (mov)
    {
        case NW:
            position.x--;
            position.y++;
            break;
        case N:
            position.y++;
            position.z--;
            break;
        case NE:
            position.x++;
            position.z--;
            break;
        case SW:
            position.x--;
            position.z++;
            break;
        case S:
            position.y--;
            position.z++;
            break;
        case SE:
            position.x++;
            position.y--;
            break;
    }
}

movement day11_map(const std::string &input)
{
    const static std::unordered_map<std::string, movement> mapping {
      {"nw", NW},
      {"n" , N},
      {"ne", NE},
      {"sw", SW},
      {"s" , S},
      {"se", SE},
      {"NW", NW},
      {"N" , N},
      {"NE", NE},
      {"SW", SW},
      {"S" , S},
      {"SE", SE}
    };
    return mapping.at(input);
}

constexpr long distance_from_zero(const hex_position &pos)
{
    // No constexpr abs?
    return max_of(pos.x < 0 ? -pos.x : pos.x,
                  pos.y < 0 ? -pos.y : pos.y,
                  pos.z < 0 ? -pos.z : pos.z);
}

long day11p1(const std::vector<std::string> &input)
{
    hex_position position;
    for(const auto &n:input)
    {
        movement mapped = day11_map(n);
        day11_perform(mapped, position);
    }

    return distance_from_zero(position);
}
long day11p2(const std::vector<std::string> &input)
{
    long maximum{LONG_MIN};

    hex_position position;
    for(const auto &n:input)
    {
        movement mapped = day11_map(n);
        day11_perform(mapped, position);

        maximum = std::max(maximum, distance_from_zero(position));
    }

    return maximum;
}
