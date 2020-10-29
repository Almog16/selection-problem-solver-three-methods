#include "BSTree.h"
#include "BSTreeNode.h"

BSTree::BSTree(int* NumComp) {
    root=NULL;
    this->NumComp = NumComp;
}

void BSTree::PrintTree(void) //prints the tree in increasing order
{
    if(root != NULL) root->Inorder();
}

void BSTree::MakeEmpty(BSTreeNode* rootNode)
{
    if(isEmpty())
        return;
    if (rootNode->left)
    {
        MakeEmpty(rootNode->left);
        rootNode->left=NULL;
    }
    if (rootNode->right)
    {
        MakeEmpty(rootNode->right);
        rootNode->right=NULL;
    }
    if(rootNode->left == NULL && rootNode->right == NULL)
        delete rootNode;
}
BSTree::~BSTree()
{
    MakeEmpty(root);
}

/*
 Find: Return pointer to node containing key k.
 Return NULL if item not in tree.
 */
BSTreeNode* BSTree::Find(KeyType k)
{
    if(isEmpty())
        return NULL;
    BSTreeNode* temp = root;
    while(temp != NULL) {

        if(k == temp->key)
        {
            *(this->NumComp)+=1;
            return temp;
        }
        else if (k < temp->key)
        {
            temp = temp->left;
            *(this->NumComp)+=2;
        }
        else
        {
            temp = temp->right;
            *(this->NumComp)+=2;
        }
    }
    return NULL;
}

BSTreeNode* BSTree::FindWithParent(KeyType k,BSTreeNode** parent)
{
    BSTreeNode* temp = root;
    BSTreeNode* tempParent = NULL;
    if(isEmpty())
        return NULL;
    while(temp != NULL) {
        if(k == temp->key)
        {
            *(this->NumComp)+=1;
            *parent=tempParent;
            return temp;
        }
        else if (k < temp->key)
        {
            *(this->NumComp)+=2;
            tempParent=temp;
            temp = temp->left;
        }
        else
        {
            *(this->NumComp)+=2;
            tempParent=temp;
            temp = temp->right;
        }
    }
    *parent=NULL;
    return NULL;
}

BSTreeNode* BSTree::Findk(int k)
{
    if(isEmpty())
        return NULL;
    BSTreeNode* temp = root;
    while(temp != NULL) {
        if(k == (temp->leftChilds+1))
            return temp;
        else if (k <= temp->leftChilds)
            temp = temp->left;
        else if (k <= (temp->leftChilds + temp->rightChilds + 1))
        {
            k = k - (temp->leftChilds + 1);
            temp = temp->right;
        }
        else
            return NULL;
    }
    return NULL;
}

//Insert into Binary Search Tree
void BSTree::Insert(KeyType k, DataType d)
{
    BSTreeNode* temp = root;    //Current node in tree
    BSTreeNode* parent = NULL;  //Parent of temp
    BSTreeNode* newnode;        //New allocated node
    
    while(temp != NULL){
        parent = temp;
        if(k < temp->key)
        {
            *(this->NumComp)+=1;
            temp->leftChilds++;
            temp = temp->left;
        }
        else
        {
            *(this->NumComp)+=1;
            temp->rightChilds++;
            temp = temp->right;
        }
    }
    newnode = new BSTreeNode(k, d, NULL, NULL); //memory for new node
    if(parent == NULL)
        root = newnode;
    else if(k < parent->key)
    {
        parent->left = newnode; //insert as left child
        *(this->NumComp)+=1;
    }
    else
    {
        parent->right = newnode; //insert as right child
        *(this->NumComp)+=1;
    }
}

void BSTree::Delete(KeyType key)
{
    if(isEmpty())
        return;
    if (Find(key) == NULL) //Check if key exists
        cout << "Error: key doesn't exists";
    BSTreeNode* temp=NULL;
    BSTreeNode* vparent = NULL;  //Parent of temp
    temp=FindWithParent(key,&vparent);
    if(!temp->left || !temp->right)
    {
        if(vparent->key > temp->key)
        {
            *(this->NumComp)+=1;
            if(temp->left)
            {
                vparent->left=temp->left;
                delete temp;
            }
            else if(temp->right)
            {
                vparent->left=temp->right;
                delete temp;
            }
            else
            {
                vparent->left=NULL;
                delete temp;
            }
        }
        else
        {
            *(this->NumComp)+=1;
            if(temp->left)
            {
                vparent->right=temp->left;
                delete temp;
            }
            else if(temp->right)
            {
                vparent->right=temp->right;
                delete temp;
            }
            else
            {
                vparent->right=NULL;
                delete temp;
            }
        }
    }
    else
    {
        BSTreeNode* rParent=temp;
        BSTreeNode* r;
        if(temp->left)
        {
            r=temp->left;
            if(!r->right)
            {
                temp->data=r->data;
                temp->key=r->key;
                temp->left=r->left;
                delete r;
            }
        }
        else
        {
            r=FindMaxWithParent(&rParent,temp->left);
            temp->data=r->data;
            temp->key=r->key;
            if(r->left)
                rParent->right=temp->left;
            else
                rParent->right=NULL;
            delete temp;
        }
    }

}

KeyType BSTree::Min(void)
{
    BSTreeNode* temp = root;
    while(temp->left != NULL)
        temp = temp->left;
    return temp->key;
}

KeyType BSTree::Max(void)
{
    BSTreeNode* temp = root;
    while(temp->right != NULL)
        temp = temp->right;
    return temp->key;
}

BSTreeNode* BSTree::FindMaxWithParent(BSTreeNode** parent,BSTreeNode* rootNode)
{
    BSTreeNode* tempParent = *parent;
    BSTreeNode* temp = rootNode;
    if(rootNode == root)
        tempParent = NULL;
    else
    {
        while(temp->right != NULL)
        {
            tempParent=temp;
            temp = temp->right;
        }
    }
    *parent=tempParent;
    return temp;
}
