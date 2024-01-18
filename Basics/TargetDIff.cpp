//
// Created by HARSHPREET SINGH on 15/01/2024.
//\

#include <bits/stdc++.h>
using namespace std;

int bSC(vector<int> arr, int target){
    int start = 0, end = arr.size()-1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == target) return mid;
        if(target > arr[mid]) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

pair<int,int> bS(vector<int> arr, int target){
    for(auto i : arr){
        int t = target+i;
        int val = bSC(arr,t);
        if(val==-1) continue;
        else return {i,arr[val]};
    }
}



int main() {
    vector<int> arr = {1,3,5,6,8,9,11,13,19,21};
    pair<int,int> p = bS(arr,8);
    cout << p.first << " " << p.second << endl;
    return 0;
}