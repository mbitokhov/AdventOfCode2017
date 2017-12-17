#include "includes/helpers.hpp"

uint64_t integral_hash(uint64_t x)
{
    x *= 0x9e3779b97f4a7c15;
    return x;
}
