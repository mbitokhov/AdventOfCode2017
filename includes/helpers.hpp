#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <type_traits>
#include <limits.h>

uint64_t integral_hash(uint64_t);

namespace std {

    template <typename dtype>
    struct hash<std::vector<dtype> >
    {
        template <typename T = dtype,
                  typename = std::enable_if_t<std::is_arithmetic<T>::value> >

        size_t operator()(const std::vector<T> &input) const
        {
            // Use different constants for different values sizeof(size_t)
            const auto FNV_prime = [](){
                constexpr int type = sizeof(size_t) * CHAR_BIT;
                static_assert(type <= 64, "FNV > 64 bits is not implemented");

                if(type <= 32)
                {
                    return (size_t) 16777619ul;
                } else {
                    return (size_t) 1099511628211ul;
                }
            }();
            const auto FNV_offset = [](){
                constexpr int type = sizeof(size_t) * CHAR_BIT;
                static_assert(type <= 64, "FNV > 64 bits is not implemented");

                if(type <= 32)
                {
                    return (size_t) 2166136261ul;
                } else {
                    return (size_t) 14695981039346656037ul;
                }
            }();

            // Perform hash
            size_t hashed = FNV_offset;
            for(const auto &n:input)
            {
                hashed ^= n;
                hashed *= FNV_prime;
            }
            return hashed;
        }
    };
}

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
