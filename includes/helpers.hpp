#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

uint64_t integral_hash(uint64_t);

template <typename dtype>
std::vector<dtype> vectorize(std::istream &input)
{
    std::vector<dtype> values;
    dtype single_value;

    while(input >> single_value)
    {
        values.push_back(single_value);
    }
    return values;
}

template <typename dtype>
std::vector<std::vector<dtype>> multi_vectorize(std::istream &input)
{
    std::vector<std::vector<dtype>> return_value;
    std::string line;

    while(std::getline(input,line))
    {
        std::istringstream ss(line);
        auto vec = vectorize<dtype>(ss);
        if(vec.size() != 0)
        {
            return_value.push_back( vec );
        }
    }
    return return_value;
}

template <typename dtype>
void print_multi_vector(std::vector<std::vector<dtype>> input)
{
    for(const auto &vec: input)
    {
        for(const auto &val: vec)
        {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }
}
