#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    std::string input;
    if(argc == 1) {
        cin >> input;
    } else {
        input = argv[1];
    }

    return 0;
}
