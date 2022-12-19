#include "205-DepthFirstSearch.h"

namespace n205
{

// template instantiation
template std::vector<int32_t> DFSInorder<int32_t>(n132::BinarySearchTree<int32_t> &tree);
template std::vector<int32_t> DFSPreorder<int32_t>(n132::BinarySearchTree<int32_t> &tree);
template std::vector<int32_t> DFSPostorder<int32_t>(n132::BinarySearchTree<int32_t> &tree);

};
