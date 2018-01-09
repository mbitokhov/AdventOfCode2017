#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <type_traits>
#include <limits.h>

constexpr size_t integral_hash(size_t x)
{
    return (sizeof(size_t) * CHAR_BIT <= 32) ?
       x * 2654435761:
       x * 0x9e3779b97f4a7c15 ;
}

// Combine already hashed values using small snippets of the Murmur Hash
// I wish I was using C++17 to actually implement it fully using constexpr
// So far the logic is too complicated for me to bother
constexpr size_t combine_hash_hash(const size_t&& state)
{
    return (state ^ (state >> 16)) * 0x85ebca6b;
}

template <typename... Args>
constexpr size_t combine_hash_hash(const size_t&& state, const size_t&& hashed, Args&&... rest)
{
    return combine_hash_hash(
        (
           state ^
          (state << 4) ^
          (state >> 4)
        ) ^ (
         (
          ((hashed * 0xcc9e2d51) << 15) ^
          ((hashed * 0xcc9e2d51) >> 17)
         ) * 0x1b873593
        ),
        std::forward<Args>(rest)...);
}

template <typename... Args>
constexpr size_t combine_hash(Args&&... all)
{
    return combine_hash_hash(0, std::forward<Args>(all)...);
}

// Vector hash using FNV
template <typename dtype, typename = void>
struct vector_hash;

template <typename dtype>
struct vector_hash<std::vector<dtype>, std::enable_if_t<std::is_arithmetic<dtype>::value > >
{
    size_t operator()(const std::vector<dtype> &input) const
    {
        // Use different constants for different values sizeof(size_t)
        constexpr auto size_of_size_t = sizeof(size_t) * CHAR_BIT;
        static_assert(size_of_size_t <=64, "FNV > 64 bits is not implemented");

        constexpr size_t FNV_prime = size_of_size_t < 64 ? 16777619ul : 1099511628211ul;
        constexpr size_t FNV_offset = size_of_size_t < 64 ? 2166136261ul : 14695981039346656037ul;

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

template<typename T>
constexpr T max_of(T a)
{
    return a;
}

template<typename T, typename... Args>
constexpr T max_of(T first_value, T second_value, Args... rest)
{
    return (first_value < second_value)   ?
            max_of(second_value, rest...) :
            max_of(first_value, rest...)  ;
}
