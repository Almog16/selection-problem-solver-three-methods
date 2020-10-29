/*
 This class solves the Selection problem, using the Binary Search Tree class
 
 Runtime efficiency analysis:
 Worst case: Θ(n)
 Average case: Θ(log(n))
 */

#ifndef BSTSelection_h
#define BSTSelection_h
#include "BSTree.h"
#include "BSTreeNode.h"
#include "Person.h"
class BSTSelection
{

private:
    unsigned int arrSize;
    int k;
    int* NumComp;
    BSTree tree;
    
public:
    BSTSelection(Person* array[], unsigned int arrSize, int k, int *NumComp, Person** personK); //c'tor
};

#endif /* BSTSelection_h */
