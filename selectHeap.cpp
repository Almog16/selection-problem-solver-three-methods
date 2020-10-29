#include <stdio.h>
#include "selectHeap.h"

selectHeap::selectHeap(Person* array[],unsigned int arrSize ,int k, int* NumComp, Person** personK) : heap(array, arrSize, NumComp)
{
    for(int i = 0; i < k; i++)
    {
        *personK=heap.DeleteMin();
    }
    
}

