#include <stdio.h>
#include "BSTSelection.h"

BSTSelection::BSTSelection(Person* array[], unsigned int arrSize, int k, int *NumComp, Person** personK) : tree(NumComp)
{
    for(int i=0; i<arrSize; i++)
        this->tree.Insert(array[i]->getIdNumber(), array[i]);
    
    *personK=tree.Findk(k)->getData();
}
