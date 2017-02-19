#include "treenode.h"

TreeNode::~TreeNode()
{
    updateParentWeight(-_weight);
}

void TreeNode::updateParentWeight(WeightDiffType diff)
{
    if (auto parent = _parent.lock()) {
        parent->addToWeight(diff);
    }
}

void TreeNode::addToWeight(WeightDiffType diff)
{
    _weight += diff;
    updateParentWeight(diff);
}

void TreeNode::putChild(std::size_t index, std::unique_ptr<TreeNode> newChild)
{
    TreeNode &childNode = *newChild;
    updateParentWeight(childNode.weight());
    childNode._parent = shared_from_this();
    childPtrRef(index) = std::shared_ptr<TreeNode>(std::move(newChild));
}
