#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

// 1. Given array of size n, calculate the maximum sum of "k" consecutive elements in the array. [ERROR: Return -1]


int question1(vector<int> input, int k){

    //First things first do some basic error handling

    if (k > input.size()){
        std::cout << "Window is greater than input size" << endl;
        return -1;
    }

    //Sliding window requires that we first gather the info for the first window

    int maxSum = 0;
    
    //Max sum will be equal to the sum of the first 'k' elements in the input vector

    for(int i = 0; i < k; i++){
        maxSum = maxSum + input[i];
    }

    //Now we check the rest of the array against the first window
    for(int i = k; i < input.size(); i++){

        //Using the "window" method starting after the first window has been initialized

        //If the previous "window" (maxSum) is less than the current "window" (maxSum if it was moved over one index)
        if(maxSum < maxSum - input[i - k] + input[i]){
            //Then remove the first element (start of window) and add the current element (extend the end of the window)
            maxSum = maxSum - input[i - k];  
            maxSum = maxSum + input[i];
        }
    }

    return maxSum;
}

// 2. For a given string of size n, find the longest substring with "k" unique characters [ERROR: return "error"]

#define MAX_CHARS 26 
//For alphabet string all lowercase. Can be doubled to include uppercase
//Should try to figure out a solution that doesn't rely on an alphabet boundary


string question2(string input, int k){

    //For this question the first thing to do is find the number of unique characters

    //We can do so by creating an int array and logging the occurences of each char

    //TODO: Try a linear map solution as well as opposed to an array

    int charCount[MAX_CHARS];

    //Fills charCount with 0's
    memset(charCount, 0, sizeof(charCount));

    int uniqueCharCount = 0;

    for(int i = 0; i < input.length(); i++){
        //If the coordinating index in charCount is 0, increment uniqueCharCount as well as the number at that index for error checking
        if(charCount[input[i] - 'a'] == 0){
            uniqueCharCount++;
            charCount[input[i] - 'a']++;
        }
    }

    if(k > uniqueCharCount){
        return "error";
    }

    //Since the size of the window is dynamic, we will just set it to the first element

    //We need variables to keep track of the previous and current location of the window in this problem since we can't use sum to compare

    int maxWindowStart, maxWindowEnd, windowStart = 0;
    int windowEnd = 1;

    //As of right now window goes from [0] - > 1 so just the first element

    for(int i = 1; i < input.length(); i++){
        //Hint: remember to use count to keep track of stuff
    }



        std::cout << "Number of unique chars is " << uniqueCharCount;

    return "hello";
}

int main () {

    //First we are going to test the functions for question 1

    vector<int> input1 = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;

    int solution1 = question1(input1, k);

    std::cout << "The solution to question 1 is: " << solution1 << endl;

    //Next up is the function for question 2

    string inputString = "aabcdaabbd";
    k = 3;

    string solution2 = question2(inputString, k);



}

