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

bool isValid(int charCount[], int k){
    int uniqueWindowCount = 0;

    for(int i = 0; i < MAX_CHARS; i++){
        if(charCount[i] > 0){
            uniqueWindowCount++;
        }
    }

    return (k >= uniqueWindowCount);
}

//For alphabet string all lowercase. Can be doubled to include uppercase
//Should try to figure out a solution that doesn't rely on an alphabet boundary

string question2(string input, int k){
    int length = input.length();

    int charCount[MAX_CHARS];

    memset(charCount, 0, sizeof(charCount)); //WHY DOES IT NOT WORK TO USE MAX_CHARS INSTEAD OF CHARCOUNT?


    //Add in some error checking

    for(int i = 0; i < length; i++){
        charCount[input[i] - 'a']++;
    }

    int uniqueChar = 0;

    for(int i = 0; i < MAX_CHARS; i++){
        if(charCount[i] > 0){
            uniqueChar++;
        }
    }

    if(uniqueChar < k){
        return "error";
    }

    memset(charCount, 0, sizeof(charCount));

    charCount[input[0] - 'a']++;

    int currentWindowStart = 0;
    int maxWindowStart = 0;
    int maxWindowEnd = 1;
    int currentWindowEnd = 0;

    for(int i = 1; i < length; i++){

    charCount[input[i] - 'a']++;
    currentWindowEnd++;

    while(!isValid(charCount, k)){
        charCount[input[currentWindowStart] - 'a']--;
        currentWindowStart++;
    }

    if((currentWindowEnd - currentWindowStart+1) > maxWindowEnd){
        maxWindowStart = currentWindowStart;
        maxWindowEnd = currentWindowEnd - currentWindowStart+1;
    }


    }

    return input.substr(maxWindowStart, maxWindowEnd);
}


//3. For a string of size k, find the shortest substring containing k unique characters

bool isValid2(int charCount[], int k){
    int uniqueWindowCount = 0;

    for(int i = 0; i < MAX_CHARS; i++){
        if(charCount[i] > 0){
            uniqueWindowCount++;
        }
    }

    return (k == uniqueWindowCount);
}

string question3(string input, int k){

        int length = input.length();

        int charCount[MAX_CHARS];

        memset(charCount, 0, sizeof(charCount)); //WHY DOES IT NOT WORK TO USE MAX_CHARS INSTEAD OF CHARCOUNT?

        charCount[input[0] - 'a']++;

        int currentWindowStart = 0;
        int maxWindowStart = 0;
        int minWindowEnd = length;
        int currentWindowEnd = 0;

        for(int i = 0; i < length; i++){
            charCount[input[i] - 'a']++;
            currentWindowEnd++;

            while(!isValid(charCount, k)){
                charCount[input[i] - 'a']--;
                currentWindowStart++;
            }


        }
        return input.substr(maxWindowStart, minWindowEnd);
}


int main () {

    //First we are going to test the functions for question 1

    vector<int> input1 = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;

    int solution1 = question1(input1, k);

    std::cout << "The solution to question 1 is: " << solution1 << endl;

    //Next up is the function for question 2

    string inputString = "aabacbebebe";
    k = 3;

    string solution2 = question2(inputString, k);

    std::cout << "The solution to question 2 is: " << solution2 << endl;

    //Next is for question 3 (similar to question 2)

    string solution3 = question3(inputString, k);

    std::cout << "The solution to question 4 is: " << solution3 << endl;



}

