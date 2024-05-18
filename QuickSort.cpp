#include <iostream>
#include <vector>
#include <time.h>

void printArray(const std::vector<int>::iterator& start, const std::vector<int>::iterator& end)
{
    if (start == end)
    return;
    auto it = start;
    while (it != end)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void swap(int index1, int index2, const std::vector<int>::iterator& start)
{
    int helper = *(start+index1);
    int other = *(start + index2);
    *(start + index1) = *(start + index2);
    *(start + index2) = helper;
}
int partition(const std::vector<int>::iterator& start, const std::vector<int>::iterator& end)
{
    int size = end - start;
    int checkedBound = 1;
    int pivotBound = 1;
    int pivot = *start;

    while (checkedBound < size)
    {
        if (*(start+checkedBound) <= pivot)
        {
            swap(checkedBound, pivotBound, start);
            ++pivotBound;
        }
        ++checkedBound;
    }
    swap(0,pivotBound-1,start);
    return pivotBound-1;
}
void quickSort(const std::vector<int>::iterator& start, const std::vector<int>::iterator& end)
{
    int s = end-start;
    if (s <= 1)
    {
        return;
    }
    srand( (unsigned)time( NULL ) );
    
    //Random pivot
    int pivotIndex = (float) (s-1)* rand()/RAND_MAX;
    int pivot = *(start+pivotIndex);

     //send pivot to front

    swap(0, pivotIndex, start);
    // printArray(array);

    int separation = partition(start, end);


    int lowerBound = separation;
    int upperBound = separation == s ? separation : separation + 1  ;

    quickSort(start, start + lowerBound);
    quickSort(start + upperBound, end);

    return;
}



int main()
{
    std::vector<int> arr {5,1,2,-5,423,5,4,3,3,6,3};
    quickSort(arr.begin(), arr.end());
    printArray(arr.begin(), arr.end());
    return 0;
}
