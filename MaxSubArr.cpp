/**
 * Jack Robbins
 * 12/28/2023
 * 
 * %%%%%%%%%%%%%%%%%% Problem Description %%%%%%%%%%%%%%%%%%%
 * Given two arrays of nonzero positive integers, arr1 and arr2, of equal size,
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
#include <vector>

using namespace std;


//predeclare
vector<vector<int>> findAllIncrSubArrays(int array[], int size);
bool isIncreasing(vector<int> subArr);

int main(){
    int arr1[] = {2, 1, 4, 2};
    int arr2[] = {4, 3, 2, 1};


    int result[4];
    
    vector<vector<int>> arr1Subs = findAllIncrSubArrays(arr1, sizeof(arr1)/sizeof(arr1[0]));

    for(auto &row: arr1Subs){
        for(auto &column: row){
            cout << column << " ";
        }
        cout << endl;
    }
}



bool findMaxSubArray(int arr1[], int arr2[], int (&result)[]){


    return true;

}


/**
 * Iteratively find all nonempty subarrays
*/
vector<vector<int>> findAllIncrSubArrays(int array[], int size){
    //Stores all of our subarrays
    vector<vector<int>> subarrays;

    //starting point
    for(int i = 0; i < size; i++){
        //ending point
        for(int j = i; j < size; j++){

            vector<int> tempVec;
            //Grab every element between start and end indexes
            for(int k = i; k <= j; k++){
                tempVec.push_back(array[k]);
            }

            //we only want tempvec if it is increasing
            if (isIncreasing(tempVec)){
                subarrays.push_back(tempVec);
            }

        }
    }

    return subarrays;
}


/**
 * Determine if a vector is increasing
*/
bool isIncreasing(vector<int> subArr){
    //Automatically increasing it is of size 1
    if (subArr.size() == 1){
        return true;
    }

    for(int i = 1; i < subArr.capacity(); i++){
        if (subArr.at(i-1) > subArr.at(i)){
            return false;
        }
    }

    return true;
}