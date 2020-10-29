#include <stdio.h>
#include "BSTreeNode.h"

BSTreeNode::BSTreeNode(KeyType key, DataType data, BSTreeNode* left, BSTreeNode* right)
{
    this->key=key;
    this->data=data;
    this->left=left;
    this->right=right;
}

void BSTreeNode::Inorder()
{
    if(this-> left == NULL && this->right == NULL){
        cout << "Name: " << this->data->getName() << ", ID: " << this->key << endl;
        return;
    }
    if(this->left)
        this->left->Inorder();
    cout << "Name: " << this->data->getName() << ", ID: " << this->key << endl;
    if(this->right)
        this->right->Inorder();
}

void BSTreeNode::Preorder()
{
    if(this-> left == NULL && this->right == NULL){
        cout << "Name: " << this->data->getName() << ", ID: " << this->key << endl;
        return;
    }
    cout << "Name: " << this->data->getName() << ", ID: " << this->key << endl;
    if(this->left)
        this->left->Preorder();
    if(this->right)
        this->right->Preorder();
}
void BSTreeNode::Postorder()
{
    if(this-> left == NULL && this->right == NULL){
        cout << "Name: " << this->data->getName() << ", ID: " << this->key << endl;
        return;
    }
    if(this->left)
        this->left->Postorder();
    if(this->right)
        this->right->Postorder();
    cout << "Name: " << this->data->getName() << ", ID: " << this->key << endl;
}

const DataType BSTreeNode::getData()
{
    return this->data;
}
