// #define TESTING

#include "includes/helpers.hpp"
#include "includes/adventofcode.hpp"

#ifdef TESTING
  #include "includes/test.hpp"
#else

  #include <sstream>
  #include <iostream>
  using namespace std;

  int main(int argc, char *argv[])
  {
      //TODO: make some flags like --test, --benchmark, --dayn, --dayall
      std::vector<std::string> args;

      // std::vector<std::vector<std::string>> input;
      std::vector<int> input;

      if(argc == 1) {
          input = vectorize<int>(cin);
      } else {
          std::stringstream arguments;
          for(int i=1; i<argc; i++)
          {
              arguments << argv[i];
          }

          input = vectorize<int>(arguments);
      }
      // print_multi_vector(input);

      // cout << "Day 1 Part 1 " << day1p1(input[0][0].c_str()) << endl;
      // cout << "Day 1 Part 2 " << day1p2(input[0][0].c_str()) << endl;

      // cout << "Day 2 Part 1: " << day2p1(input) << endl;
      // cout << "Day 2 Part 2: " << day2p2(input) << endl;

      // cout << "Day 3 Part 1: " << day3p1(input[0][0]) << endl;
      // cout << "Day 3 Part 2: " << day3p2(input[0][0]) << endl;

      // cout << "Day 4 Part 1: " << day4p1(input) << endl;
      // cout << "Day 4 Part 2: " << day4p2(input) << endl;

      cout << "Day 5 Part 1: " << day5p1(input) << endl;
      cout << "Day 5 Part 2: " << day5p2(input) << endl;

      return 0;
  }
#endif
