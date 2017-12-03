#include "includes/adventofcode.hpp"
#include <iostream>

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
