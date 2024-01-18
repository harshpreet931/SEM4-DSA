//
// Created by HARSHPREET SINGH on 18/01/2024.
//


#include <bits/stdc++.h>
using namespace std;

pair<int,int> sliding(vector<int> arr, int k, int target){
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    if(sum == target) return {0,k};
    int idx = 0;
    for(int i=k;i<arr.size();i++){
        sum += arr[i];
        sum -= arr[idx++];
        if(sum == target) return {idx,i};
    }
    return {-1,-1};
}

pair<int,int> subarraySIREDITION(int arr[], int n, int k, int target){
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    int i = 0; int  j = k-1;
    while(j < n){
        if(sum == target) return {i,j};
        sum = sum - arr[i] + arr[j+1];
        i++; j++;
    }
    return {-1,-1};
}

int main() {
    vector<int> arr = {1,2,-1,3,4,9,5,2,3,1,4};
    int arr2[] = {1,2,-1,3,4,9,5,2,3,1,4};
    pair<int,int> p,p2;
    p = sliding(arr,5,20);
    cout << p.first << " " << p.second<< endl;

    p2 = subarraySIREDITION(arr2,sizeof(arr2)/sizeof(arr2[0]),3,16);
    cout << p2.first << " " << p2.second << endl;
    return 0;
}