#include "163-ReverseString.h"

namespace
{

void reverse(std::string &src, uint32_t start, uint32_t end, std::string &dest, uint32_t dest_ind)
{
    dest[dest_ind] = src[end];

    if (start == end)
    {
        return;
    }

    reverse(src, start, end - 1, dest, dest_ind + 1);
}

} // namespace n163


namespace n163
{

const std::string Solution::reverse(std::string &str)
{

    if (str.empty())
    {
        return "";
    }

    std::string dest(str);  // to allocate same length
    ::reverse(str, 0, str.size() - 1, dest, 0);

    return dest;
}

} // namespace n163
