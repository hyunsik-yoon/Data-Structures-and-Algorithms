#ifndef __217_DYNAMIC_PROGRAMMING__
#define __217_DYNAMIC_PROGRAMMING__

#include <stdint.h>
#include <vector>

namespace n217
{

uint32_t inefficient_fibonacci(uint32_t n)
{
    if (n < 2)
    {
        return n;
    }

    return inefficient_fibonacci(n - 1) + inefficient_fibonacci(n - 2);
}

} // namespace n217


namespace
{

uint32_t dynamic_fibonacci_helper(uint32_t n, std::vector<uint32_t>& cache)
{
    if (n < 2)
    {
        return n;
    }

    if (cache[n] == 0)
    {
        auto val = dynamic_fibonacci_helper(n - 1, cache) + dynamic_fibonacci_helper(n - 2, cache);
        cache[n] = val;
    }

    return cache[n];
}

}

namespace n217
{

uint32_t dynamic_fibonacci(uint32_t n)
{
    uint32_t cache_size = n + 1;
    // let's use vector as cache. (of course, map can be used as a cache)
    // note: cache[0] and cache[1] are not used.
    std::vector<uint32_t> cache(cache_size);

    return dynamic_fibonacci_helper(n, cache);
}


} // namespace n217

#endif // __217_DYNAMIC_PROGRAMMING__
