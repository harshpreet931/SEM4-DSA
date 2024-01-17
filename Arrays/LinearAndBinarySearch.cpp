//
// Created by HARSHPREET SINGH on 11/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int binaryS(int arr[], int n, int key){
    int s=0;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int linearS(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 5, 6, 7, 9, 12, 15, 18, 20};
    int n = sizeof(arr) / sizeof(int);
    int key = 15;
    cout << binaryS(arr, n, key) << endl;
    cout << linearS(arr, n, key) << endl;
    return 0;
}