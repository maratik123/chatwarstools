#ifndef TREENODE_H
#define TREENODE_H

#include <array>
#include <memory>

class TreeNode
{
public:
    TreeNode() {}
    TreeNode(const TreeNode &) = delete;
    TreeNode &operator=(const TreeNode &) = delete;
    virtual ~TreeNode();

    using WeightType = int;
    using WeightDiffType = int;
    WeightType weight() const { return _weight; }
    void addToWeight(WeightDiffType diff);

protected:
    void putChild(std::size_t index, std::unique_ptr<TreeNode> newChild);
    virtual std::weak_ptr<TreeNode> child(std::size_t index) const = 0;
    virtual std::shared_ptr<TreeNode> &child(std::size_t index) = 0;

private:
    void updateParentWeight(WeightDiffType diff);
    std::weak_ptr<TreeNode> _parent;
    WeightType _weight;
};

template <std::size_t TotalNodes>
class BaseTreeNode : public TreeNode
{
protected:
    std::shared_ptr<TreeNode> &child(std::size_t index) { return _children[index]; }
    std::weak_ptr<TreeNode> child(std::size_t index) const { return _children[index]; }

private:
    std::array<std::shared_ptr<TreeNode>, TotalNodes> _children;
};

#endif // TREENODE_H
