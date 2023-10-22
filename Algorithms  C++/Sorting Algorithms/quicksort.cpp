#include <iostream>

//For quicksort, the algorithm goes ass follows...

// 1. Pick an element as pivot (Can be any. Easiest is to pick the last element)
// 2. 


//Function accepts pointer to original array so we can arrange items around the pivot element
void partitionArray(int arr[], int start, int end){
    // Create a temporary pointer to start pointing at the first element 
    int pivot = arr[end];
    int tempPtr = start - 1;

    for(int i = start; i <= end; i++){
        if(arr[i] < pivot){
            tempPtr++;
            int swapPtr = arr[i];
            arr[i] = arr[tempPtr];
            arr[tempPtr] = swapPtr;
        }
    }
    // int swapPtr = arr[end + 1];
    // arr[end + 1] = arr[tempPtr];
    // arr[tempPtr] = swapPtr;

    
    
}


int main(){
 //We will use 5 as the pivot element
//  int arr [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int arr [] = {1, 4, 10, 8, 5, 3, 2, 6, 7, 9};
  int length = sizeof(arr) / sizeof(arr[0]);
 
 //Rearranging array elements based on pivot
 partitionArray(arr, 0, length);

 for(auto i : arr){
    std::cout << i << '\n';
 }
 
}