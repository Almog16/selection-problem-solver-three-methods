/*
This class defines the Binary Search Tree ADT, and all of its required methods
 */

#ifndef BSTree_h
#define BSTree_h
class BSTreeNode;
#include "Person.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

typedef int KeyType;
typedef Person* DataType;

class BSTree
{
private:
    BSTreeNode* root;
    int* NumComp;

public:
    BSTree(int* NumComp); //c'tor
    ~BSTree(); //d'tor
    void MakeEmpty(BSTreeNode* rootNode); //clears all of the elements of the tree
    bool isEmpty() {return root==NULL;}; //checks if the tree is empty
    BSTreeNode* Find(KeyType key); //this function looks for a key in the tree
    BSTreeNode* Findk(int k); //returns the kth smallest key
    BSTreeNode* FindWithParent(KeyType k,BSTreeNode** parent); //returns the node along with its parent
    BSTreeNode* FindMaxWithParent(BSTreeNode** parent,BSTreeNode* rootNode); //returns the maximun key in a subtree, along with its parent
    void Insert(KeyType key, DataType data); //insert a key to the BST
    void Delete(KeyType key); //delets a key from the BST
    KeyType Min(void); //returns the minimun key of the BST
    KeyType Max(void); //returns the maximun key of the tree
    void PrintTree(void); //prints the tree
};

#endif /* BSTree_h */
