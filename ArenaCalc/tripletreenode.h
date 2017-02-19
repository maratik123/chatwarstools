#ifndef TRIPLETREENODE_H
#define TRIPLETREENODE_H

#include "treenode.h"
#include "enums.h"
#include "enumclassutil.h"

class TripleTreeNode : public BaseTreeNode<3> {
public:
    TripleTreeNode();
    std::shared_ptr<TripleTreeNode> operator[](PrivateParts part) { return childPtrDerived<TripleTreeNode>(enumToIndex(part)); }
    void putChild(PrivateParts part, std::unique_ptr<TripleTreeNode> newChild);
};

#endif // TRIPLETREENODE_H
