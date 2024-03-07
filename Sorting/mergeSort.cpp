//
// Created by HARSHPREET SINGH on 16/02/2024.
//
#include <bits/stdc++.h>
using namespace std;


void merge(vector<int>& arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1,0) , M(n2,0);

    for(int i=0;i<n1;i++)   L[i] = arr[l+i];
    for(int j=0;j<n2;j++)   M[j] = arr[m+1+j];

    int i,j,k;
    i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] <= M[j])    arr[k] = L[i++];
        else    arr[k] = M[j++];
        k++;
    }
    while(i < n1)   arr[k++] = L[i++];
    while(j < n2)   arr[k++] = M[j++];
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
    vector<int> arr = {5,2,10,2,4,1};
    mergeSort(arr,0,arr.size()-1);
    for(auto i : arr) cout << i << " ";
    return 0;
}