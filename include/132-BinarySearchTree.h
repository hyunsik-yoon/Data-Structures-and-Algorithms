#ifndef __132__BINARY_SEARCH_TREE__
#define __132__BINARY_SEARCH_TREE__

#include <cassert>
#include <stdexcept>
#include <vector>

namespace n132
{

template <typename T> class Node
{
public:
    Node(const T &val): _val(val), _left(nullptr), _right(nullptr) { /* empty */ }

    using NodeP = Node *;

    // For expression like `node->left() = new Node(0);`
    NodeP &left() { return _left; }
    NodeP &right() { return _right; }

    const T val() { return _val; }
private:
    const T _val;
    Node *_left;
    Node *_right;
};

template <typename T> class BinarySearchTree
{
public:
    BinarySearchTree() { _root = nullptr; }
    ~BinarySearchTree() { delete_tree(root()); }

private:
    void delete_tree(Node<T> *r)
    {
        if (r == nullptr)
        {
            return;
        }
        else
        {
            delete_tree(r->left());
            delete_tree(r->right());
            delete r;
        }
    }

public:
    void insert(const T &item)
    {
        if (is_empty())
        {
            _root = new Node<T>(item);
            return;
        }

        for (auto r = _root; ;)
        {
            if (item == r->val())
            {
                // already existing value. Do not add.
                return;
            }
            else if (item < r->val())
            {
                if (r->left() == nullptr)
                {
                    r->left() = new Node<T>(item);
                    return;
                }
                else
                {
                    r = r->left();
                }
            }
            else if (item > r->val())
            {
                if (r->right() == nullptr)
                {
                    r->right() = new Node<T>(item);
                    return;
                }
                else
                {
                    r = r->right();
                }
            }
        }
    }

    // This returns a smallest number in the right tree of node r
    // r must have right tree
    // *ptr is upper level node of smallest node
    Node<T> *smallest_of_right_tree(Node<T> *r, Node<T> **&ptr)
    {
        assert(r->right());

        ptr = &(r->right());
        r = r->right();

        while (r->left() != nullptr)
        {
            ptr = &(r->left());
            r = r->left();
        }

        return r;
    }

    // This returns a largest number in the left tree of node r
    // r must have left tree
    // *ptr is _left of upper level node of largest node
    Node<T> *largest_of_left_tree(Node<T> *r, Node<T> **&ptr)
    {
        assert(r->left());

        ptr = &(r->left());
        r = r->left();

        while (r->right() != nullptr)
        {
            ptr = &(r->right());
            r = r->right();
        }

        return r;
    }

    // Assume that lookup(..) returns a node *r.
    // When r == root(), *ptr is nullptr;
    // when r != root(), *ptr is pointer or _left or _right of upper level node of r;
    Node<T> *lookup(const T &item, Node<T> **&ptr)
    {
        for (auto r = _root; r != nullptr; )
        {
            if (r->val() == item)
            {
                return r;
            }
            else if (item < r->val())
            {
                ptr = &(r->left());
                r = r->left();
            }
            else if (item > r->val())
            {
                ptr = &(r->right());
                r = r->right();
            }
        }
        return nullptr;
    }

    Node<T> *lookup(const T &item)
    {
        Node<T> **ptr = nullptr;
        // let's ignore ptr in case of this method
        return lookup(item, ptr);
    }

    bool remove(const T &item)
    {
        Node<T> **p_removee = nullptr;
        auto removee = lookup(item, p_removee);

        if (removee == nullptr)
        {
            return false;
        }

        Node<T> *replacer = nullptr;    // This will replace removee after removal

        // if removee has right(), replace removee with the smallest node of right tree
        // if removee does not have right(), replace removee with the largest node of left tree
        if (removee->right())
        {
            Node<T> **s_ptr = nullptr;
            replacer = smallest_of_right_tree(removee, s_ptr);

            // remove link in a tree to the smallest node
            *s_ptr = nullptr;

            // replace removee with smallest node
            replacer->right() = removee->right();
            replacer->left() = removee->left();

            // remove removee
            delete removee;
        }
        else if (removee->left()) // node has left tree only (no right tree)
        {
            Node<T> **l_ptr = nullptr;
            replacer = largest_of_left_tree(removee, l_ptr);

            // remove link in a tree to the smallest node
            *l_ptr = nullptr;

            // replace removee with smallest node
            replacer->right() = removee->right();
            replacer->left() = removee->left();

            // remove removee
            delete removee;
        }
        else // no left or right tree
        {
            // remove removee
            delete removee;
        }

        if (removee == root())
        {
            _root = replacer;
        }
        else
        {
            // ptr to removee should be updated to point replacer
            *p_removee = replacer;
        }

        return true;
    }

    bool is_empty()
    {
        return (_root == nullptr);
    }

    Node<T> *root() { return _root; }

private:
    Node<T> *_root;
};

} // namespace n132

#endif
