#include "includes/helpers.hpp"

uint64_t integral_hash(uint64_t x)
{
    //With credits going to Thomas Mueller on StackOverflow
    //https://stackoverflow.com/questions/664014
    x = (x ^ (x >> 31) ^ (x >> 62)) * UINT64_C(0x319642b2d24d8ec3);
    x = (x ^ (x >> 27) ^ (x >> 54)) * UINT64_C(0x96de1b173f119089);
    x = x ^ (x >> 30) ^ (x >> 60);
    return x;
}
