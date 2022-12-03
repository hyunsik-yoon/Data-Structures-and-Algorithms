#include "108-ReverseLinkedList.h"

namespace n108
{

void reverse(LinkedList* l)
{
    if (l == nullptr || l->head() == nullptr) 
    {
        return;
    }

    Node* evantual_tail = l->head();
    Node* new_head = l->head()->next();

    while (new_head != nullptr)
    {
        evantual_tail->next(new_head->next());
        new_head->next(l->head());

        l->head(new_head);
        l->tail(evantual_tail);

        new_head = evantual_tail->next();
    }
}

}
