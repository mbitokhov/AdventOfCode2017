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
long day2p2(std::vector<std::vector<int>> input)
{
    long running_sum{0};
    for(const auto &vec:input)
    {
        bool found = false;
        //loop through numbers in one line
        for(size_t i=1; i<vec.size(); i++)
        {
            //loop through all numbers before current number
            for(size_t j=0; j<i; j++)
            {
                auto minmax_pair = std::minmax(vec[i],vec[j]);
                int mod = minmax_pair.second % minmax_pair.first;
                if(mod == 0)
                {
                    running_sum += minmax_pair.second / minmax_pair.first;
                    found =true;
                    break;
                }
            }
            if(found)
            {
                break;
            }
        }
    }
    return running_sum;
}
