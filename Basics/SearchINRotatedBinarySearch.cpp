//
// Created by HARSHPREET SINGH on 12/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int bS(vector<int>&arr, int target){
    int start = 0, end = arr.size()-1;
    int mid;
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == target) return mid;

        //if left
        if(arr[mid] >= arr[start]){
            if(arr[start] <= target && arr[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid  + 1;
            }
        }
        //right
        else {
            if (arr[mid] < target && arr[end] >= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}



int main() {
    vector<int> arr = {7,8,9,10,11,12,13,14,1,2,3,4,5,6};
    cout << bS(arr,12);
    return 0;
}