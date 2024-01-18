//
// Created by HARSHPREET SINGH on 11/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int first(vector<int>&arr, int target){
    int start = 0; int end = arr.size()-1;
    int ans = -1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == target){
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

int last(vector<int>&arr, int target){
    int start = 0; int end = arr.size()-1;
    int ans = -1;
    while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid] == target){
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int f = first(arr,k);
    int e = last(arr,k);
    pair<int,int> p1 = {f,e};
    return p1;
}

int main() {
    vector<int> arr = {1,2,3,4,5,5,5,6,7,8,9,10};
    int n = arr.size();
    int k = 5;
    pair<int,int> p1 = firstAndLastPosition(arr,n,k);
    cout << p1.first << " " << p1.second << endl;
    return 0;
}