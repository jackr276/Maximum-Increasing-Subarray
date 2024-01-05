/**
 * Jack Robbins
 * 12/28/2023
 * 
 * %%%%%%%%%%%%%%%%%% Problem Description %%%%%%%%%%%%%%%%%%%
 * Given an array of k nonzero positive integers,
 * find the length n of the largest possible subarray in
 * which all elements are increasing
*/


//For printing
#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <time.h>

using namespace std;


//predeclare
void findAllIncrSubArraysIter(set<vector<int>> &arrSubs, int array[], int size);
vector<int> findMaxSubArray(int (&arr)[], int size, int &option);
bool isIncreasing(vector<int> &subArr);


// 0 for recursive, one for iterative
int main(int argc, char *argv[]){
    if (argc < 2){
        return -1;
    }

    int option = stoi(argv[1]);

    int arr[100];
    //generate a random array
    cout << "Initial Array:\n[";
    srand(time(NULL));
    for(int i = 0; i < 100; i++){
        //cut the random numbers down some
        arr[i] = rand()%1000;
        cout << arr[i]<< " ";
    }
    cout << "]" << endl;

    vector<int> maxSubArray = findMaxSubArray(arr, 100, option);

    cout << "Largest increasing subarray\n[";
    
    for (auto &elem : maxSubArray){
        cout << elem << ",";
    }

    cout << "]" << endl;
}


// Option: 0 for recursion, 1 for iterative
vector<int> findMaxSubArray(int (&arr)[], int size, int &option){
    set<vector<int>> arrSubs;

    //result
    vector<int> vec;

    cout << "All increasing subarrays generated:" << endl; 
    int max = 0;

    //Show the user all subarrays that are increasing
    for(auto &row: arr1Subs){
        cout << "[";
        if (row.size() > max){
            max = row.size();
            vec = row;
        }
        for(auto &column: row){
            cout << column << ",";
        }
        cout << "]" << endl;
    }

    return vec;
}


/**
 * Iteratively find all nonempty subarrays
*/
void findAllIncrSubArraysIter(set<vector<int>> &arrSubs, int array[], int size){

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
                arrSubs.insert(tempVec);
            }
        }
    }
}


/**
 * Determine if a vector is increasing
*/
bool isIncreasing(vector<int> &subArr){
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