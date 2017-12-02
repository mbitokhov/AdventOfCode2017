#include <iostream>
#include <vector>
#include <algorithm>
#include "includes/adventofcode.hpp"

long day2p1(std::vector<std::vector<int>> input)
{
    long running_sum{0};
    for(const auto &vec:input)
    {
        auto minmax_pair = std::minmax_element(vec.begin(), vec.end());
        running_sum += (*minmax_pair.second) - (*minmax_pair.first);
    }
    return running_sum;
}
