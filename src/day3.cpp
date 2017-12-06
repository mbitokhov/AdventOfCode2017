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
        auto hashed_1 = integral_hash(std::get<0>(value));
        auto hashed_2 = integral_hash(std::get<1>(value));

        //Can't just add them because that leads to -1,3 = 3,-1
        auto hashed = hashed_1 << 32;
        hashed ^= hashed_2 >> 32;
        return hashed;
    };

    std::unordered_map<Coordinate, long, decltype(tuple_hash)> grid(128,tuple_hash);
    grid[{0,0}] = 1;

    auto sum_nearby_elements = [grid](int x, int y)
    {
        long sum = 0;
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                auto found = grid.find({x+i, y+j});
                if(found != grid.end())
                {
                    sum += found->second;
                }
            }
        }
        return sum;
    };

    int x = 0;
    int y = 0;
    int radius = 1;
    int corner;
    while (true)
    {
        x += 1;
        corner = y+radius;
        for(;y<=corner; y++)
        {
            long sum = sum_nearby_elements(x,y);
            if(sum > input)
            {
                return sum;
            }
            grid[{x,y}] = sum;
        }
        y--;
        corner = 2*radius + 1;
        for(;x>=corner; x--)
        {
            long sum = sum_nearby_elements(x,y);
            if(sum > input)
            {
                return sum;
            }
            grid[{x,y}] = sum;
        }
        x++;
        for(;y>=corner; y--)
        {
            long sum = sum_nearby_elements(x,y);
            if(sum > input)
            {
                return sum;
            }
            grid[{x,y}] = sum;
        }
        y++;
        corner *= -1;
        for(;x>=corner; x++)
        {
            long sum = sum_nearby_elements(x,y);
            if(sum > input)
            {
                return sum;
            }
            grid[{x,y}] = sum;
        }
        x--;
        radius += 1;
    }
}
