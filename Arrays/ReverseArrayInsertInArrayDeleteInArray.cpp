//
// Created by HARSHPREET SINGH on 10/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

void rev(int arr[], int start, int end){
    while(start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void insert(int arr[], int& n, int pos, int key){
    for(int i=n; i >= pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = key;
    n++;
}

void del(int arr[], int pos, int &n){
    for(int i=pos;i<n;i++){
        arr[i] = arr[i+1];
    }
    n--;
}


int main() {
    int arr[] = {1,4,3,4,5,2,7,5,8,9};
    int n = 10;
    rev(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}