#ifndef __202_BREADTH_FIRST_SEARCH__
#define __202_BREADTH_FIRST_SEARCH__

#include "132-BinarySearchTree.h"
#include "122-Queue.h"

namespace n202
{

template <typename T>
class BreadthFirstSearhTree : public n132::BinarySearchTree<T>
{
public:
    std::vector<T> traverse()
    {
        std::vector<T> v;

        if (this->is_empty())
        {
            return v;    // return empty vector
        }

        n122::Queue<n132::Node<T> *, n122::DS::LinkedList> q;
        auto *node = this->root();
        q.queue(node);

        while (! q.is_empty())
        {
            // move to next node
            node = q.dequeue();

            // evalute current node
            v.emplace_back(node->val());

            // push next nodes
            if (auto *l = node->left())
            {
                q.queue(l);
            }
            if (auto *r = node->right())
            {
                q.queue(r);
            }
        }

        return v;
    }
};

} // namespace n202

#endif // __202_BREADTH_FIRST_SEARCH__
