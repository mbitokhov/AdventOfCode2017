#include "includes/adventofcode.hpp"
#include "includes/helpers.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

long day4p1(const std::vector<std::vector<std::string>>& input)
{
    long sum{0};
    std::unordered_map<std::string, short> memory;

    for(const auto& vec:input)
    {
        bool not_found{true};
        for(const auto& word: vec)
        {
            if(memory[word] != 0)
            {
                not_found = false;
                break;
            }
            memory[word] = 1;
        }
        if(not_found)
        {
            sum++;
        }
        memory.clear();
    }
    return sum;
}
long day4p2(const std::vector<std::vector<std::string>>&input)
{
    long sum{0};
    std::unordered_map<std::string, short> memory;

    for(const auto& vec:input)
    {
        bool not_found{true};
        for(auto word: vec)
        {
            std::sort(word.begin(), word.end());
            if(memory[word] != 0)
            {
                not_found = false;
                break;
            }
            memory[word] = 1;
        }
        if(not_found)
        {
            sum++;
        }
        memory.clear();
    }
    return sum;
}
