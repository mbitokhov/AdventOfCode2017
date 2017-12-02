#include <sstream>
#include <iostream>
#include "includes/helpers.hpp"
#include "includes/adventofcode.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    std::vector<std::vector<int>> input;
    if(argc == 1) {
        input = vectorize<int>(cin);
    } else {
        std::stringstream args;
        for(int i=1; i<argc; i++)
        {
            args << argv[i];
        }
    }
    // print_multi_vector(input);

    // cout << "Day 1 Part 1 " << day1p1(input[0][0].c_str()) << endl;
    // cout << "Day 1 Part 2 " << day1p2(input[0][0].c_str()) << endl;

    cout << "Day 2 Part 1: " << day2p1(input) << endl;
    cout << "Day 2 Part 2: " << day2p2(input) << endl;

    return 0;
}
