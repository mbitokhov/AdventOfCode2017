#include <iostream>
#include "includes/adventofcode.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    std::string input;
    if(argc == 1) {
        cin >> input;
    } else {
        input = argv[1];
    }

    cout << "Day 1: Part 1 " << day1p1(input.c_str()) << endl;
    cout << "Day 1: Part 2 " << day1p2(input.c_str()) << endl;


    return 0;
}
