#ifndef __217_DYNAMIC_PROGRAMMING__
#define __217_DYNAMIC_PROGRAMMING__

#include <cassert>
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

uint32_t recursive_dynamic_fibonacci(uint32_t n, std::vector<uint32_t>& cache)
{
    if (n < 2)
    {
        return n;
    }

    if (cache[n] == 0)
    {
        auto val = recursive_dynamic_fibonacci(n - 1, cache) + recursive_dynamic_fibonacci(n - 2, cache);
        cache[n] = val;
    }

    return cache[n];
}

}

namespace n217
{

uint32_t recursive_dynamic_fibonacci(uint32_t n)
{
    uint32_t cache_size = n + 1;
    // let's use vector as cache. (of course, map can be used as a cache)
    // note: cache[0] and cache[1] are not used.
    std::vector<uint32_t> cache(cache_size);

    return ::recursive_dynamic_fibonacci(n, cache);
}

uint32_t iterative_dynamic_fibonacci(uint32_t n)
{
    if (n < 2)
    {
        return n;
    }

    // here, we know that n >= 2

    uint32_t cache_size = n + 1;
    std::vector<uint32_t> cache(cache_size);
    cache[0] = 0;
    cache[1] = 1;

    for (uint32_t k = 2; k <= n; k++)
    {
        if (cache[k] == 0)
        {
            cache[k] = cache[k - 1] + cache[k - 2];
        }
    }

    assert(cache[n] != 0);
    return cache[n];
}

} // namespace n217

#endif // __217_DYNAMIC_PROGRAMMING__
