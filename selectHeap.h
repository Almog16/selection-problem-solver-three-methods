/*
This class solves the Selection problem, using Heap
 */

#ifndef selectHeap_h
#define selectHeap_h
#include "Heap.h"
#include "Person.h"

class selectHeap
{
private:
    int k;
    int* NumComp;
    Heap heap;
    
public:
    selectHeap(Person* array[],unsigned int arrSize ,int k, int* NumComp, Person** personK); //c'tor

};

#endif /* selectHeap_h */
