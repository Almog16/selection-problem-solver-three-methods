/*
 Submitted by:
 Almog Shimon, ID number: 205965437
 Oron Bortman, ID number: 311141188
 
 This program solves the selection problem in three different ways:
    1. Using the Binary Search Tree ADT
    2. Using the normal Selection algorithm, and randomly selecting a pivot
    3. Using the Heap ADT
 
 Once you run the program, you need to submit the following details as input:
    1. The number of elements you want to submit
    2. The actual elements, in the following order: key value
    3. An int: k
 
 The output will be the k-th smallest element of your input.
 */

#include <iostream>
#include "Person.h"
#include "RandomSelection.h"
#include "selectHeap.h"
#include "BSTSelection.h"

void checkCin();
bool elemExists(Person** arr, int size, int id);

int main() {
    const int MAX_LENGTH = 20;

    int arrSize;
    int logicSize=0;
    cin >> arrSize;
    checkCin();
    if(arrSize < 1)
    {
        cout <<  "input invalid" << endl;
        exit(1);
    }
    
    Person ** arr = new Person*[arrSize];
    char name[MAX_LENGTH];
    int id;
    
    for(int i=0;i<arrSize;i++)
    {
        cin >> id;
        checkCin();
        cin.ignore();
        cin.getline(name, MAX_LENGTH);
        char ch;
        int stringSize = strlen(name);
        for(unsigned int j=0; j < stringSize; j++)
        {
            ch = name[j];
            if(!((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A')))
            {
                cout <<  "input invalid" << endl;
                exit(1);
            }
        }


        if(!elemExists(arr, logicSize, id))
        {
            arr[i] = new Person(id, name);
            logicSize++;
        }
        else
        {
            cout <<  "input invalid" << endl;
            exit(1);
        }
    }
    int k;
    cin >> k;
    checkCin();
    if((k < 1) || (k > arrSize))
    {
        cout <<  "input invalid" << endl;
        exit(1);
    }
    
    int NumCompRand = 0, NumCompHeap = 0, NumCompBST = 0;
    Person* pRandk;
    Person* pHeapk;
    Person* pBSTk;
    RandomSelection(arr, arrSize, k, &NumCompRand, &pRandk);
    selectHeap(arr, arrSize, k, &NumCompHeap, &pHeapk);
    BSTSelection(arr, arrSize, k, &NumCompBST, &pBSTk);
    
    cout << pHeapk->getIdNumber() << " " << pHeapk->getName() << endl;
    cout << "RandSelection: " << NumCompRand << " comparisons" << endl;
    cout << "selectHeap: " << NumCompHeap << " comparisons" << endl;
    cout << "BST: " << NumCompBST << " comparisons" << endl;
    
    

}

bool elemExists(Person** arr, int size, int id)
{
    for(unsigned int i=0; i<size; i++)
    {
        if(arr[i]->getIdNumber()==id)
            return true;
    }
    return false;
}

void checkCin()
{
    if(cin.fail())
    {
        cout <<  "input invalid" << endl;
        exit(1);
    }
}
