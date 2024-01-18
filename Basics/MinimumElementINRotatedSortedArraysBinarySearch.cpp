//
// Created by HARSHPREET SINGH on 12/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int bS(vector<int>&arr){
    int start = 0; int end = arr.size()-1;
    int m = arr[0];
    while(start <= end){
        if(arr[start] < arr[end]){
            m = min(m,arr[start]);
            break;
        }
        int mid = start + (end - start)/2;
        m = min(m,arr[mid]);

        if(arr[mid] >= arr[start]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return m;
}

int sirEdition(vector<int>&arr){
    int start = 0; int end = arr.size()-1;
    int mid;
    while(start < end){
        mid = (start + end) / 2;

        if(arr[mid] > arr[end]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return start;
}

int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    cout << bS(arr) << endl;
    cout << sirEdition(arr) << endl;
    return 0;
}