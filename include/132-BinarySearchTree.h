#ifndef __132__BINARY_SEARCH_TREE__
#define __132__BINARY_SEARCH_TREE__

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

    // Assume that lookup(..) returns a node *r.
    // When r == root(), *prev_node is nullptr;
    // when r != root(), *prev_node is upper level node of r;
    Node<T> *lookup(const T &item, Node<T> **&prev_node)
    {
        for (auto r = _root; r != nullptr; )
        {
            if (r->val() == item)
            {
                return r;
            }
            else if (item < r->val())
            {
                prev_node = &(r->left());
                r = r->left();
            }
            else if (item > r->val())
            {
                prev_node = &(r->right());
                r = r->right();
            }
        }
        return nullptr;
    }

    Node<T> *lookup(const T &item)
    {
        Node<T> **prev_node = nullptr;
        // let's ignore prev_node in case of this method
        return lookup(item, prev_node);
    }

    const T remove(const T &item)
    {
        throw std::runtime_error("Not yet implemented");
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
