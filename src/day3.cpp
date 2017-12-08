#include "includes/adventofcode.hpp"
#include "includes/helpers.hpp"
#include <iostream>
#include <unordered_map>
#include <tuple>
#include <limits.h>

long FindNearestOddSquare(const long& input)
{
    int i=1;
    while(i*i < input)
    {
        i+=2;
    }
    return i-2;
}
long day3p1(const long& input)
{
    // Find the "radius" by using the next greatest odd square
    long side = FindNearestOddSquare(input)+2;
    long radius = side / 2;

    //The maximum value it could be
    //Also it's the bottom right value of the square
    long start = (side)*(side);

    //Find the side of where the input is
    while(start >= input)
    {
        start -= side-1;
    }

    //Calculate the middle of the side and subtract it from the input
    long middle = start + (side/2);
    long distance_from_middle = std::abs(middle - input);

    //return the distance from the middle of the side + the radius
    return distance_from_middle + radius;
}
long day3p2(const long& input)
{
    typedef std::tuple<int, int> Coordinate;

    auto tuple_hash = [](Coordinate value){
        auto hashed = integral_hash(std::get<0>(value));
        hashed = integral_hash(hashed ^ std::get<1>(value));

        return hashed;
    };

    std::unordered_map<Coordinate, long, decltype(tuple_hash)> grid(128,tuple_hash);
    grid[{0,0}] = 1;

    auto sum_nearby_elements = [&grid](Coordinate position)
    {
        if(grid[position] != 0)
        {
            std::cout << "redoing the same coordinate "
                      << "x: " << std::get<0>(position)
                      << "y: " << std::get<1>(position)
                      << std::endl;

        }

        int x = std::get<0> (position);
        int y = std::get<1> (position);
        long sum = 0;
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                long found = grid[{x+i, y+j}];
                // std::cout << "element: "
                //           << "i: " << i << " "
                //           << "j: " << j << " "
                //           << "found: " << found << " "
                //           << std::endl;
                sum += found;
            }
        }
        // std::cout << "x: " << x << " "
        //           << "y: " << y << " "
        //           << "sum: " << sum << " "
        //           << std::endl;
        grid[position] = sum;
        return sum;
    };

    Coordinate position{1,0};
    //bool on_x{false};

    ////Value is just a pair where the second element is the value to add to
    ////the position depending on on_x
    //Coordinate value{-1,1};
    int corner = 1;
    while (true)
    {
        //I had to unroll the loop manually because the logic became tricky to
        //implement efficiently. I worried that gcc and clang would not be able
        //to unroll it itself

        //The logic goes as follows
        //  while position is not on the corner
        //    sum up the values around it
        //    move the position toward the corner
        //  move the position closer to the next corner

        //Everything is just copy pasted

        // y++
        while(std::get<1>(position) <= corner)
        {
            auto sum = sum_nearby_elements(position);
            if(sum > input)
            {
                return sum;
            }
            std::get<1>(position)++;
        }
        std::get<1>(position)--;

        // x--
        std::get<0>(position)--;
        while(std::get<0>(position) >= -corner)
        {
            auto sum = sum_nearby_elements(position);
            if(sum > input)
            {
                return sum;
            }
            std::get<0>(position)--;
        }
        std::get<0>(position)++;

        // y--
        std::get<1>(position)--;
        while(std::get<1>(position) >= -corner)
        {
            auto sum = sum_nearby_elements(position);
            if(sum > input)
            {
                return sum;
            }
            std::get<1>(position)--;
        }
        std::get<1>(position)++;

        // x++
        std::get<0>(position)++;
        while(std::get<0>(position) <= corner)
        {
            auto sum = sum_nearby_elements(position);
            if(sum > input)
            {
                return sum;
            }
            std::get<0>(position)++;
        }
        std::get<0>(position)--;

        //This is my other implementation that involved looping it based off of
        //logic

        //It didn't work entirely, but the issue is fixed easily. The
        //implementation goes

        //  for each side:
        //    sum nearby elements
        //    if a side that's on x, move x closer to the corner
        //    else move y closer to the corner
        //    if we're currently on the corner, break
        //
        //  swap the x,y incrememnt/decrement value and multiple the new x by -1
        //  flip on_x

        //Doing this, there's just one central piece of code, but might lead
        //to poorer performance

        // for(int side=0; side<4; side++)
        // {
        //     int current_position;
        //     do
        //     {
        //         long sum;
        //         sum = sum_nearby_elements(position);
        //         if(sum > input)
        //         {
        //             return sum;
        //         }
        //
        //         std::cout << "x: "
        //                   << std::get<0>(position)
        //                   << " y: "
        //                   << std::get<1>(position)
        //                   << " sum: "
        //                   << sum
        //                   << std::endl;

        //         if(on_x)
        //         {
        //           std::get<0>(position) += std::get<1>(value);
        //           current_position = std::get<0>(position);
        //         } else
        //         {
        //           std::get<1>(position) += std::get<1>(value);
        //           current_position = std::get<1>(position);
        //         }
        //     } while(std::abs(current_position) <= corner);
        //     std::cout << "Finished loop" << std::endl;

        //     value = {std::get<1>(value)*-1, std::get<0>(value)};
        //     on_x = !on_x;
        // }

        // std::cout << "Increasing x" << std::endl;
        std::get<0>(position)++;
        corner++;
    }
}
