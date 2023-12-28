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


    return true;

}


/**
 * Iteratively find all nonempty subarrays
*/
int** findAllSubArrays(int array[]){
    int length = sizeof(array) / sizeof(array[0]);

    /**
     * Using formula: number of sub arrays = n(n+1)/2
    */

    int numSub = length * (length+1) / 2;

    //hold all of our sub arrays
    int** arr = new int*[length];

    //starting point(potentially 0 to len(array))
    for(int i = 0; i < length; i++){
        //ending point(potentially i to len(array))
        for(int j = i; j < length; j++){
            
            //for everything between, add to a result array
            //TODO need some new kind of datastructure to push to, arrays won't work, not resizeable


        }
    }

    return arr;
}


/**
 * Determine if an array is increasing
*/
bool isIncreasing(int arr[]){

    for(int i = 1; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i-1] > arr[i]){
            return false;
        }
    }

    return true;
}