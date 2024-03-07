//
// Created by HARSHPREET SINGH on 16/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int l, int r){
    int pivot = arr[r];
    int i = (l - 1);
    for(int j=l;j<r;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(vector<int>&arr, int l, int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main() {
    vector<int> arr = {10,9,8,6,45,4,3,12,2,43,2,3213,31,33,24};
    quickSort(arr,0,arr.size()-1);
    for(auto i : arr) cout << i << " ";
    return 0;
}