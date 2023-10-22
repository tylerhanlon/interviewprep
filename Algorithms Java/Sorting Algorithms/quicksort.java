

class QuickSort {


    static void swap(int[] arr, int element1, int element2){
        System.out.println("Swapping");

        int swapPtr = arr[element1];
        arr[element1] = arr[element2];
        arr[element2] = swapPtr;
    }

    static void partitionArray(int[] arr, int start, int end){
        
        // Assign pivot to be right-most element of the array
        int pivot = 5;
        int tempPtr = start - 1;

        for(int i = 0; i <= end; i++){
            if(arr[i] < pivot){
                // Increment tempPtr
                tempPtr++;
                swap(arr, tempPtr, i);
            }
        }

        //Once loop completes, swap pivot with tempptr value
        swap(arr, tempPtr + 1, end);
    }

    static void quicksort(){
        System.out.println("Quicksort");
    }

    public static void main(String[] args){
        
        int[] arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        int len = arr.length;

        partitionArray(arr, 0, len - 1);
        for(int x: arr){
            System.out.println(x);
        }
    }
}