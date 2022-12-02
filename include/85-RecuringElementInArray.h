#ifndef __85__RECURRING_ELEM_IN_ARRAY__
#define __85__RECURRING_ELEM_IN_ARRAY__

#include <vector>
#include <stdexcept>

class NoRecurringElemException : public std::runtime_error
{
public:
    NoRecurringElemException(const char* msg): std::runtime_error(msg) { /* body empty */ }
};

const int find_recurring_elem(const std::vector<int>& a);

#endif // __85__RECURRING_ELEM_IN_ARRAY__
