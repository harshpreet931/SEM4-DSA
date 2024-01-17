//
// Created by HARSHPREET SINGH on 15/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int missing(vector<int> arr){
    int n = arr.size();
    int temp[n] = {0};
    for(auto i : arr){
        if(i >= 1 && i <= n){
            temp[i-1]++;
        }
    }
    for(int i=0;i<n;i++){
        if(temp[i] == 0){
            return i + 1;
        }
    }
    return -1;
}

int cyclicSort(vector<int> arr){
    int i = 0;
    while(i < arr.size()){
        int pos = arr[i] - 1;
        if(arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[pos]){
            swap(arr[i],arr[pos]);
        }
        else{
            i++;
        }
    }
    for(int j=0;j<arr.size();j++){
        if(arr[j]!=j+1){
            return j+1;
        }
    }
    return arr.size()+1;
}

// in an array of numbers we need to find the first missing positive number in the array in O(n) time and O(1) space
// the array isn't sorted and can contain negative numbers as well
int main() {
//    vector<int> arr = {10,1,-5,4,2,6,-2,5,3};
//    int n = arr.size();
//
//    // first we need to segregate the positive and negative numbers
//    int j = 0;
//    for(int i = 0;i<n;i++){
//        if(arr[i] <= 0){
//            swap(arr[i],arr[j]);
//            j++;
//        }
//    }
//
//    // now we need to mark the numbers as visited
//    for(int i = j;i<n;i++){
//        if(abs(arr[i])-1 < n && arr[abs(arr[i])-1] > 0){
//            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
//        }
//    }
//
//    // now we need to find the first positive number
//    for(int i = 0;i<n;i++){
//        if(arr[i] > 0){
//            cout << i+1;
//            break;
//        }
//    }
//    return 0;

    // Sir Edition
    vector<int> arr = {10,1,-5,4,2,6,-2,5,3};
    cout << missing(arr);


}