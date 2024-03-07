//
// Created by HARSHPREET SINGH on 7/02/2024.
//
#include <bits/stdc++.h>
using namespace std;
// we will use custom comparator to sort the array
void sortArr1byArr2(vector<int>& A1, vector<int>& A2){
    unordered_map<int,int> idx;
    for(int i=0;i<A2.size();i++){
        idx[A2[i]] = i;
    }
    sort(A1.begin(),A1.end(),[&](int a, int b){
        if(idx.find(a) != idx.end() && idx.find(b) != idx.end()){
            return idx[a] < idx[b];
        }
        else if(idx.find(a) != idx.end()){
            return true;
        }
        else if(idx.find(b) != idx.end()){
            return false;
        }
        else{
            return a < b;
        }
    });
}

void sirMethod(vector<int>& arr1, vector<int>& arr2){
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    vector<int> ans;
    sort(arr1.begin(),arr1.end());

    for(int i = 0 ; i<arr1.size(); i++){
        mp1[arr1[i]]++;
    }
    for(int i=0; i<arr2.size();i++){
        mp2[arr2[i]]++;
    }

    for(int i=0;i<arr2.size();i++){
        for(int j=0;j<mp1[arr2[i]];j++){
            ans.push_back(arr2[i]);
        }
    }

    for(int i=0;i<arr1.size();i++){
        if(mp2.find(arr1[i]) == mp2.end()){
            ans.push_back(arr1[i]);
        }
    }

}

int main() {
    vector<int> arr1 = {1,2,2,5,5,6,5,4,3,3,2,3,1,1,7,8,9,7,8};
    vector<int> arr2 = {5,3,1,2,4,6,10};
    sortArr1byArr2(arr1,arr2);
    for(auto i : arr1){
        cout << i << " ";
    }
    return 0;
}