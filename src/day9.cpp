#include "includes/adventofcode.hpp"

#include <iostream>
#include <string>
#include <functional>

size_t inline day9_find_unescaped(const std::string& input,
                                  const size_t start=0,
                                  char value='>',
                                  char escape_char='!')
{
    // Unfortantely the below code produces an error
    // It's a very simple answer, but it doesn't work all the time :(
    // size_t index{0};
    // do {
    //     index = input.find(value, index);
    // } while (input[index-1] != escape_char && index != std::string::npos);
    // return index;

    for(size_t index=start; index < input.size(); index++)
    {
        if(input[index] == escape_char)
        {
            index++;
            continue;
        }
        if(input[index] == value)
        {
            return index;
        }
    }
    return std::string::npos;
}

long day9p1(std::string input)
{
    //remove all garbage data first
    size_t found = input.find('<');
    size_t end;
    while(found != std::string::npos)
    {
        end = day9_find_unescaped(input, found+1);
        input.erase(found, end-found+1);

        found = input.find('<',found);
    }
    // std::cout << input << std::endl;

    long sum{0};
    long inc{0};
    for(auto c: input)
    {
        if(c == '{')
        {
            inc++;
            sum += inc;
        } else if (c == '}') {
            inc--;
        }
    }
    return sum;

    // I'm so disappointed. This is a perfect way to show off my knowledge of
    // recursive lambdas. But there's an obvious better solution to it.
    // // A parser of things
    // // is a function from strings
    // // to list of pairs
    // // of things and strings!

    // std::function<long(const std::string&)> parser;
    // parser = [](const std::string& input) {
    //     
    // };

}
long day9p2(const std::string& input)
{
    //remove all garbage data first
    size_t found = input.find('<');
    long sum=0;
    while(found != std::string::npos)
    {
        size_t index;
        for(index=found+1; index < input.size() && input[index] != '>'; index++)
        {
            if(input[index] == '!')
            {
                index++;
                continue;
            }
            sum++;
        }

        found = input.find('<',index);
    }
    return sum;
}
