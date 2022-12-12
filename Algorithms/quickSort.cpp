#include <iostream>
#include <string>
#include <vector>


//Quicksort is a divide and conquer algorithm

void swap(int *a, int *b){
    std::cout << a;
    int temp = *a;
    *a = *b;
    *b = temp;
    
}

int main(){
    std::vector<int> input = {4, 2, 1, 5, 3, 6};

    swap(&input[0], &input[1]);

    int len = input.size();

    for(int i = 0; i < len; i++){
        std::cout << input[i] << ", ";
    }

    return 0;
}