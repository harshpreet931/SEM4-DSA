//
// Created by HARSHPREET SINGH on 15/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int bS(vector<int> arr){
    int start = 0, end = arr.size()-1;
    int idx = -1;
    while(start <= end){
        int mid = (start + end) / 2;

        if(arr[mid]%2==1){
            start = mid + 1;
        }
        else{
            idx = mid;
            end = mid - 1;
        }
    }
    return idx;
}

int main() {
    vector<int> arr = {1,3,5,9,11,13,15,17,2,6,8,10,16};
    cout << bS(arr);
    return 0;
}