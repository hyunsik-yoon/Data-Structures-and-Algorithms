#include "85-RecuringElementInArray.h"

#include <map>

const int32_t find_recurring_elem(const std::vector<int32_t>& a)
{
    std::map<int32_t, bool> m;

    for (auto item : a) 
    {
        auto found = m.find(item);
        if (found == m.end())
        {
            m[item] = true;
        }
        else 
        {
            return item;
        }
    }
    throw NoRecurringElemException("Not Found");
}
