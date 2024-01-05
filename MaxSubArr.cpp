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
#include <chrono>

using namespace std;


//predeclare
void findAllIncrSubArraysIter(set<vector<int>> &arrSubs, int (&array)[], int size);
void findAllIncrSubArraysRec(set<vector<int>> &arrSubs, int (&array)[], int size, int start, int end);
vector<int> findMaxSubArray(int (&arr)[], int size, int &option);
bool isIncreasing(vector<int> &subArr);


// 0 for recursive, one for iterative
int main(int argc, char *argv[]){
    if (argc < 2){
        return -1;
    }

    int option = stoi(argv[1]);

    int arr[200];
    //generate a random array
    cout << "Initial Array:\n[";
    srand(time(NULL));
    for(int i = 0; i < 200; i++){
        //cut the random numbers down some
        arr[i] = rand()%1000;
        cout << arr[i]<< " ";
    }
    cout << "]" << endl;

    vector<int> maxSubArray = findMaxSubArray(arr, 200, option);

    cout << "Largest increasing subarray\n[";
    
    for (auto &elem : maxSubArray){
        cout << elem << ",";
    }

    cout << "]" << endl;
}


// Option: 0 for recursion, 1 for iterative
vector<int> findMaxSubArray(int (&arr)[], int size, int &option){
    set<vector<int>> arrSubs;

    //for timing
    chrono::time_point<chrono::system_clock> start, end;

    if(option == 0){
        cout << "Using Recursive Subarray Generation" << endl;
        start = chrono::system_clock::now();
        findAllIncrSubArraysRec(arrSubs, arr, size, 0, 0);
        end = chrono::system_clock::now();
    } else {
        cout << "Using Iterative Subarray Generation" << endl;
        start = chrono::system_clock::now();
        findAllIncrSubArraysIter(arrSubs, arr, size);
        end = chrono::system_clock::now();
    }

    //result
    vector<int> vec;

    cout << "All increasing subarrays generated:" << endl; 
    int max = 0;

    //Show the user all subarrays that are increasing
    for(auto &row: arrSubs){
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

    //elapsed time
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "\nSubarray generation took: " << elapsed_seconds.count() << " seconds\n" << endl;

    return vec;
}



//recursive way of finding all increasing subarrays
//works by moving start and end around, until end equals the size of the array
void findAllIncrSubArraysRec(set<vector<int>> &arrSubs, int (&array)[], int size, int start, int end){
    //if the end = the size of the array, we're done(base case)
    if(end == size){
        return;
    }

    //start has ranged from 0 to current end, so range from 0 to end + 1
    if(start > end) {
        findAllIncrSubArraysRec(arrSubs, array, size, 0, end+1);
    } else {
        //actually make the sub array
        vector<int> subArr;

        for(int i = start; i < end; i++){
            subArr.push_back(array[i]);
        }

        //only put in if increasing
        if(isIncreasing(subArr)){
            //put the subarray in arrSubs
            arrSubs.insert(subArr);
        }

        //increment start by 1 and do again
        findAllIncrSubArraysRec(arrSubs, array, size, start+1, end);
    }

    return;
}


/**
 * Iteratively find all nonempty subarrays
*/
void findAllIncrSubArraysIter(set<vector<int>> &arrSubs, int (&array)[], int size){

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

    for(int i = 1; i < subArr.size(); i++){
        if (subArr.at(i-1) > subArr.at(i)){
            return false;
        }
    }

    return true;
}