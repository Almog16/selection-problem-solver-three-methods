/*
 This class solves the partition problem using a random pivot, using the selection algorithm.
 
 Runtime efficiency:
 Worst case: Θ(n^2)
 Average case: Θ(n)
 */

#ifndef RandomSelection_h
#define RandomSelection_h
#include "Person.h"
#include <stdlib.h>
#include "time.h"
using namespace std;

class RandomSelection
{
private:
    char direction;
    unsigned int arrSize;
    Person** array;
    int k;
    int* NumComp;
    
public:
    RandomSelection(Person* array[],unsigned int arrSize ,int k, int* NumComp, Person** person);
    ~RandomSelection();
    int Partition(int left, int right);
    Person* RandomSelectionAlg(int left, int right, int i);
    void swapArr(int index1, int index2);

};

#endif /* RandomSelection_h */
