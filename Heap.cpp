
#include "Heap.h"
using namespace std;

//Constructor: allocate memory for the heap and make the heap empty
Heap::Heap(int max, int* NumComp)
{
    
    this->NumComp = NumComp;
    data = new Person*[maxSize];
    maxSize = max;
    heapSize = 0;
    allocated = 1;
}

//Destructor: delete memory
//Only if allocated by heap.
Heap::~Heap()
{
    if(allocated)
        delete [] data;
    data = NULL;
}

//Private Member functions oh Heap class
int Heap::Parent(int node)
{
    return(node-1)/2;
}

int Heap::Left(int node)
{
    return (2*node + 1);
}

int Heap::Right(int node)
{
    return (2*node + 2);
}

void Heap::FixHeap(int node) //Fixes the heap that has node as root
{
    int min;
    int left = Left(node); //left child
    int right = Right(node); //right child
    
    //Find maximum among node, left and right.
    if((left < heapSize) && (data[left]->getIdNumber() < data[node]->getIdNumber()))
    {
        min = left;
    }
    else
        min = node;
    if(left < heapSize)
    {
        *(this->NumComp)+=1;
    }
    
    if((right < heapSize) && (data[right]->getIdNumber() < data[min]->getIdNumber()))
        min = right;
    if(right < heapSize)
    {
        *(this->NumComp)+=1;

    }
    //Swap values if necessary, and continure
    //Fixing the heap towards the leaves
    if(min != node)
    {
        swapArr(node, min);
        FixHeap(min);
    }
}

Person* Heap::Min(void)
{
    return data[0];
}

//Delete minimum which is found
//in the root oh heap, and fix heap
Person* Heap::DeleteMin()
{
    if(heapSize < 1)
    {
        cout << "Error: EMPTY HEAP\n";
        exit(1);
    }
    Person* min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    FixHeap(0);
    return(min);
}

//Add a new lead for item, and swap upwards
//until item in its correct position.

void Heap::Insert(Person* item)
{
    if(heapSize == maxSize)
    {
        cout << "Error: HEAP FULL\n";
        exit(1);
    }
    int i = heapSize;
    heapSize++;
    
    while((i>0) && (data[Parent(i)]->getIdNumber() < item->getIdNumber()))
    {
        *(this->NumComp)+=1;
        data[i] = data[Parent(i)];
        i = Parent(i);
    }
    if(i>0)
    {
        *(this->NumComp)+=1;
    }
    data[i] = item;
}

//Constructor: convert an array which contains n numbers into a heap.
//Idea: the numbers in places n-1,...,n/2 are leaves.
//Build small heaps starting from leaves.
//and fix heap while going towards the root.

Heap::Heap(Person* A[], int n, int* NumComp)
{
    this->data = new Person*[n];
    for (int i=0; i<n; i++){
        this->data[i] = A[i];
    }
    heapSize = maxSize = n;
    this->NumComp=NumComp;
    allocated = 0;  //Memory not allocated by heap.
    
    for(int i = (n/2)-1; i >= 0; i--)
        FixHeap(i);
}

void Heap::swapArr(int index1, int index2){
        Person* temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
}
