#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

template <typename dtype>
std::vector<std::vector<dtype>> vectorize(std::istream &input)
{
    std::vector<std::vector<dtype>> return_value;
    std::vector<dtype> line_values;
    std::string line;
    dtype single_value;

    std::stringstream line_stream;
    while(std::getline(input,line))
    {
        line_stream << line;
        while(line_stream >> single_value)
        {
            line_values.push_back(single_value);
        }
        if(line_values.size() != 0)
        {
            return_value.push_back(line_values);
        }
        line_values.clear();
        line_stream.clear();
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
