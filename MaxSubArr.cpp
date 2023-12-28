/**
 * Jack Robbins
 * 12/28/2023
 * 
 * %%%%%%%%%%%%%%%%%% Problem Description %%%%%%%%%%%%%%%%%%%
 * Given two arrays, arr1 and arr2, of equal size,
 * find the length n of the largest possible subarray in
 * which all elements are increasing, taking the "i"th element
 * from arr1 and the "i"th element from array 2 at any given time
 * 
 * Example: arr1 = [2, 1, 4, 2], [4, 3, 2, 1]
 * i = 0: take 2 from arr1; result = [2]
 * i = 1: take 3 from arr2; result = [2, 3]
 * i = 2: take 4 from arr1; result = [2, 3, 4]
 * i = 3: no valid answers
 * 
 * Max subarray = [2, 3, 4]
*/


//For printing
#include <iostream>

using namespace std;


int main(){
    int arr1[] = {2, 1, 4, 2};
    int arr2[] = {4, 3, 2, 1};


    int result[4];
    
    findMaxSubArray(arr1, arr2, result);

    cout << result << endl;
}



bool findMaxSubArray(int arr1[], int arr2[], int (&result)[]){

    int arrSize = sizeof(arr1)/sizeof(int);

    for(int i = 0; i < arrSize; i++){
        
    }


    return true;

}