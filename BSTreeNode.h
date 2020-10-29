/*
This class defines the Binary Search Tree Node.
 This class is used by the Binary Search Tree ADT class.
 */

#ifndef BSTreeNode_h
#define BSTreeNode_h
#include "BSTree.h"
#include <iostream>

class BSTreeNode
{
private:
    KeyType key;
    DataType data;
    BSTreeNode *left, *right;
    int leftChilds=0;
    int rightChilds=0;
public:
    friend class BSTree;
    BSTreeNode(KeyType key, DataType data, BSTreeNode* left, BSTreeNode* right); //c'tor
    void Inorder(); //print the tree Inorder
    void Preorder();//print the tree Preoder
    void Postorder();//print the tree Postorder
    const DataType getData(); //return the node's data
};

#endif /* BSTreeNode_h */
