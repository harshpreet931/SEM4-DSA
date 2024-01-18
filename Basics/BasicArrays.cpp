//
// Created by HARSHPREET SINGH on 10/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,4,3,4,5,2,7,5,8,9};
    int *p;
    p = arr;
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout << p+i << " ";
    }
    cout << endl;
    return 0;
}