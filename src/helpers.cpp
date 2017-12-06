#include "includes/helpers.hpp"


uint64_t integral_hash(uint64_t i)
{
    //The nearest prime to (2^64)/phi where phi is the golden ratio (1+sqrt(5))/2
    //There are better ways to hash, but I only have 1-2 hours a day of
    //research/coding and I've been stuck on this puzzle for 2 days now
    //To be fair I haven't really spent that much time working on it
    i *= 11400714819323198549ul;
    return i;
}
