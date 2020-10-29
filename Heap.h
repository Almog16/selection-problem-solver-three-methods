/*
 This class defines the Heap ADT and its required methods
 
 Runtime efficiency analysis:
 Worst case: Θ(n*log(n))
 (Avg. case was not required)
 */

#ifndef Heap_h
#define Heap_h
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Person.h"

class Heap{

private:
    Person** data;    //Points to data array
 //   Person** array;
    int maxSize;   //Min size of heap
    int heapSize;  //Current size of heap
    int allocated; //1 if heap allocated memory
    static int Left(int node);
    static int Right(int node);
    static int Parent(int node);
    void FixHeap(int node);
    int* NumComp;
public:
    Heap(int max, int* NumComp);          //Allocate memory
    Heap(Person* A[], int n, int* NumComp);  //Turn A[] into heap
    ~Heap();
    Person* Min(void);
    Person* DeleteMin();
    void Insert(Person* item);
    void swapArr(int index1, int index2);


};

#endif /* Heap_h */
