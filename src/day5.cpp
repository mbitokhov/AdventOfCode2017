#include "includes/adventofcode.hpp"
#include "includes/helpers.hpp"

unsigned long day5p1(std::vector<int> input)
{
    size_t position{0};
    size_t vec_size{input.size()};
    unsigned long counter{0};

    while(position < vec_size)
    {
        position += input[position]++;
        counter++;
    }

    return counter;
}
unsigned long day5p2(std::vector<int> input)
{
    size_t previous_position{0};
    size_t position{0};
    size_t vec_size{input.size()};
    unsigned long counter{0};

    while(position < vec_size)
    {
        position += input[position];
        if(input[previous_position] >= 3)
        {
            input[previous_position]--;
        } else {
            input[previous_position]++;
        }

        previous_position = position;
        counter++;
    }

    return counter;
}
