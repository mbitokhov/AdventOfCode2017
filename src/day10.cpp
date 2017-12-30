#include "includes/adventofcode.hpp"

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cassert>

void inline day10_perform(std::vector<int> &state, int first_position, int swap_count)
{
    int last_position = first_position + swap_count - 1;

    for(; first_position < last_position; first_position++, last_position--)
    {
        std::swap(state[first_position%256], state[last_position%256]);
    }
}

// Find the value of a single position (after the hash) using O(n) time and
// constant space
int inline day10p1_quick_perform(const std::vector<int> &input, int position, int size=256)
{
    int step_size = input.size()-1;
    //Sum_positions is the way of keeping track of the position
    //It's the sum of the values from 1 to step_size and the sum of the input
    int sum_positions = std::accumulate(input.begin(),input.end(),((step_size) * (step_size+1)) /2);

    for(auto n = input.rbegin(); n != input.rend(); n++)
    {
        // Set the first and last position of what is being swapped
        sum_positions -= step_size;
        sum_positions -= *n;
        int first_position = sum_positions % size;
        int last_position = first_position + *n -1;

        step_size--;

        // check that if the current position is being changed
        int looped_position = position < first_position ? position + size: position;
        if(looped_position >= first_position && looped_position <= last_position)
        {
            //"swap"
            int distance_left = looped_position - first_position;
            int distance_right = last_position - looped_position;

            if(distance_left < distance_right)
            {
                position = last_position - distance_left;
            } else {
                position = first_position + distance_right;
            }

            position %= size;
        }
    }
    return position;
}

long day10p1(const std::vector<int> &input)
{
    // std::vector<int> test {3,4,1,5};
    // int ans;
    // for(int i=0; i<5; i++)
    // {
    //     ans = day10p1_quick_perform(test,i,5);
    //     std::cout << "answer for " << i << " is " << ans << std::endl;
    // }
    // return 1l;

    auto multi = day10p1_quick_perform(input, 0);
    multi *= day10p1_quick_perform(input, 1);
    return multi;
}
std::string day10p2(std::string input)
{
    input += {(unsigned char) 17,
              (unsigned char) 31,
              (unsigned char) 73,
              (unsigned char) 47,
              (unsigned char) 23};

    int position = 0;
    int step_size=0;
    std::vector<int> state(256);
    std::iota(state.begin(),state.end(),0);

    // Preform hash
    for(int i=0; i<64; i++)
    {
        for(const auto &n:input)
        {
            day10_perform(state, position, n);

            position += n + step_size++;
            position %= 256;
        }
    }

    // Generate hex code
    auto to_hex = [](int i)->char{
        assert(i < 16 && "passing a non hex to to_hex");
        if(i < 10)
        {
            return i + '0';
        } else {
            return i + 'a' - 10;
        }
    };
    // Get actual hash value
    std::string hash_value;
    for(int i=0; i<256; i+= 16)
    {
        // Get dense hash
        int hashed{0};
        for(auto n=state.begin() + i; n != (state.begin() + i + 16); n++)
        {
            hashed ^= *n;
        }

        hash_value += {to_hex(hashed/16), to_hex(hashed%16)};
    }
    return hash_value;
}
