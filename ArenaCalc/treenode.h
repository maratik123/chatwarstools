#ifndef TREENODE_H
#define TREENODE_H

#include <array>
#include <memory>

class TreeNode : public std::enable_shared_from_this<TreeNode>
{
public:
    using WeightType = int;
    using WeightDiffType = int;

    TreeNode() {}
    TreeNode(const TreeNode &) = delete;
    TreeNode &operator=(const TreeNode &) = delete;
    virtual ~TreeNode();

    WeightType weight() const { return _weight; }
    void addToWeight(WeightDiffType diff);

protected:
    void putChild(std::size_t index, std::unique_ptr<TreeNode> newChild);
    virtual std::shared_ptr<TreeNode> &childPtrRef(std::size_t index) = 0;
    std::shared_ptr<TreeNode> childPtr(std::size_t index) { return childPtrRef(index); }

private:
    void updateParentWeight(WeightDiffType diff);
    std::weak_ptr<TreeNode> _parent;
    WeightType _weight;
};

template <std::size_t TotalNodes>
class BaseTreeNode : public TreeNode
{
protected:
    template <typename DerivedType>
    std::shared_ptr<DerivedType> childPtrDerived(std::size_t index) { return std::static_pointer_cast<DerivedType>(childPtr(index)); }

private:
    std::shared_ptr<TreeNode> &childPtrRef(std::size_t index) { return _children[index]; }
    std::array<std::shared_ptr<TreeNode>, TotalNodes> _children;
};

#endif // TREENODE_H
