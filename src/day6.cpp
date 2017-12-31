#include "includes/adventofcode.hpp"
#include "includes/helpers.hpp"

#include <algorithm>
#include <unordered_map>

void inline perform(std::vector<int> &input)
{
    auto max_ptr = std::max_element(input.begin(), input.end());
    int max_index = std::distance(input.begin(), max_ptr);
    int max_value = input[max_index];

    input[max_index] = 0;

    int size_array = input.size();
    for(int i = 1; i <= max_value; i++)
    {
        input[(max_index + i) % size_array]++;
    }
}

long day6p1(std::vector<int> input)
{
    using hash_functor = vector_hash<std::vector<int> >;
    long counter=0;
    std::unordered_map<std::vector<int>, bool, hash_functor> memory;
    while(memory[input] == 0)
    {
        memory[input] = 1;
        counter++;
        perform(input);
    }
    return counter;
}
long day6p2(std::vector<int> input)
{
    using hash_functor = vector_hash<std::vector<int> >;
    long counter=0;
    std::unordered_map<std::vector<int>, std::pair<bool,long>, hash_functor > memory;
    while(memory[input].first == 0)
    {
        memory[input] = {1, counter};
        counter++;
        perform(input);
    }
    return counter - memory[input].second;
}
