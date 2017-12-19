#include "includes/adventofcode.hpp"

#include <map>
#include <unordered_map>
#include <string>
#include <functional>
#include <cstdlib>
#include <algorithm>
#include <iostream>

void inline day8_run_once(std::map<std::string, long> &memory,
                          const std::vector<std::string> &line )
{
    //This is where I envy my scripting brothers for having eval()

    // The reason why I have it with unordered_maps is that I'm trying to avoid
    // branching. but looking at it in hindsight, it's probably better to branch
    // than to hash a string, do a modulus, go to the function pointer, run the
    // code
    const static std::unordered_map<std::string, std::function<bool(const long&, const long&)>> logic{
      {"<",  [](const long &a, const long &b){return a <  b;}},
      {"<=", [](const long &a, const long &b){return a <= b;}},
      {">",  [](const long &a, const long &b){return a >  b;}},
      {">=", [](const long &a, const long &b){return a >= b;}},
      {"==", [](const long &a, const long &b){return a == b;}},
      {"!=", [](const long &a, const long &b){return a != b;}}
    };
    const static std::unordered_map<std::string, std::function<long(long&, long&)>> inc_dec{
      {"inc",[](const long &a, const long &b){return a + b;}},
      {"dec",[](const long &a, const long &b){return a - b;}}
    };

    std::string str_operator{line[5]};
    long lhs{memory[line[4]]};
    long rhs{atol(line[6].c_str())};

    if(logic.at(str_operator)(lhs, rhs))
    {
        long value{memory[line[0]]};
        long add{atol(line[2].c_str())};
        memory[line[0]] = inc_dec.at(line[1])(value, add);
    }
}

long day8p1(std::vector<std::vector<std::string>> input)
{
    typedef std::map<std::string, long> memory_pool;
    memory_pool memory;
    for(const auto& vec:input)
    {
        day8_run_once(memory, vec);
    }

    auto value_checker = [](memory_pool::value_type a, memory_pool::value_type b) {return a.second<b.second;};
    auto max_value = std::max_element(memory.begin(), memory.end(), value_checker);
    return (*max_value).second;

}


long day8p2(std::vector<std::vector<std::string>> input)
{
    typedef std::map<std::string, long> memory_pool;
    memory_pool memory;
    long max_value{0};
    for(const auto& vec:input)
    {
        day8_run_once(memory, vec);
        if(max_value < memory[vec[0]])
        {
            max_value = memory[vec[0]];
        }
    }
    return max_value;
}
