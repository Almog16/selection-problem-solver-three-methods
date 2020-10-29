#include <stdio.h>
#include "RandomSelection.h"

RandomSelection::RandomSelection(Person* array[],unsigned int arrSize ,int k, int* NumComp, Person** person)
{
    this->direction='R';
    this->arrSize = arrSize;
    this->array = new Person*[arrSize];
    for (int i=0; i<arrSize; i++){
        this->array[i] = array[i];
    }
    this->k=k;
    this->NumComp=NumComp;
    *person=RandomSelectionAlg(0, (this->arrSize)-1, k);
}

RandomSelection::~RandomSelection()
{
    delete array;
}

void RandomSelection::swapArr(int index1, int index2){
        Person* temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
}

int RandomSelection::Partition(int left, int right)
{
    this->direction='R';
    srand((unsigned)time(NULL));
    int pivot = (rand() % (right-left+1))+left;
    if(pivot != left) {//Move the selected pivot to the left index
        swapArr(pivot, left);
    }
    //Perform normal partition
    while(left < right)
    {
        (*this->NumComp)++;
        if(array[left]->getIdNumber() > array[right]->getIdNumber()){
            swapArr(left, right);
            
            if(this->direction=='R')
                this->direction='L';
            else
                this->direction='R';
        }
        if(this->direction=='R')
            right--;
        else
            left++;
    }
    if(this->direction=='R')
        return right;
    else
        return left;
}

Person* RandomSelection::RandomSelectionAlg(int left, int right, int i)
{
    int pivot;  //location of pivot
    int leftPart;   //size of part left of pivot(including pivot)
    
    pivot = Partition(left,right);
    leftPart = pivot - left + 1;
    if (i == leftPart)
        return array[pivot];
    if(i<leftPart)
        return RandomSelectionAlg(left,pivot-1,i);
    else
        return RandomSelectionAlg(pivot+1,right,i-leftPart);
}

