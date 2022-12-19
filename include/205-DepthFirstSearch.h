#ifndef __205_DEPTH_FIRST_SEARCH__
#define __205_DEPTH_FIRST_SEARCH__

#include "132-BinarySearchTree.h"

#include <vector>

namespace
{

enum class DFSOrder
{
    IN_ORDER, PRE_ORDER, POST_ORDER
};

template <typename T, DFSOrder OrderT> class DepthFirstSearh;

template <typename T> class DepthFirstSearh<T, DFSOrder::IN_ORDER>
{
public:
    void traverse(n132::Node<T> *node, std::vector<T> &result)
    {
        if (! node)
        {
            return;
        }

        traverse(node->left(), result);
        result.emplace_back(node->val());
        traverse(node->right(), result);
    }
};

template <typename T> class DepthFirstSearh<T, DFSOrder::PRE_ORDER>
{
public:
    void traverse(n132::Node<T> *node, std::vector<T> &result)
    {
        if (! node)
        {
            return;
        }

        result.emplace_back(node->val());
        traverse(node->left(), result);
        traverse(node->right(), result);
    }
};

template <typename T> class DepthFirstSearh<T, DFSOrder::POST_ORDER>
{
public:
    void traverse(n132::Node<T> *node, std::vector<T> &result)
    {
        if (! node)
        {
            return;
        }

        traverse(node->left(), result);
        traverse(node->right(), result);
        result.emplace_back(node->val());
    }
};

} // namespace

namespace n205
{
    template <typename T> std::vector<T> DFSInorder(n132::BinarySearchTree<T> &tree)
    {
        std::vector<int32_t> v;
        DepthFirstSearh<T, DFSOrder::IN_ORDER> dfs;
        dfs.traverse(tree.root(), v);
        return v;
    }

    template <typename T> std::vector<T> DFSPreorder(n132::BinarySearchTree<T> &tree)
    {
        std::vector<int32_t> v;
        DepthFirstSearh<T, DFSOrder::PRE_ORDER> dfs;
        dfs.traverse(tree.root(), v);
        return v;
    }

    template <typename T> std::vector<T> DFSPostorder(n132::BinarySearchTree<T> &tree)
    {
        std::vector<int32_t> v;
        DepthFirstSearh<T, DFSOrder::POST_ORDER> dfs;
        dfs.traverse(tree.root(), v);
        return v;
    }

} // namespace n202

#endif // __205_DEPTH_FIRST_SEARCH__
