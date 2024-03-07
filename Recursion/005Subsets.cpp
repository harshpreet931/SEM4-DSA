//
// Created by HARSHPREET SINGH on 6/02/2024.
//


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;
void subset(vector<int> arr, vector<int> temp, int idx){
    subsets.push_back(temp);

    for(int i=idx;i<arr.size();i++){
        temp.push_back(arr[i]);
        subset(n,arr,temp, i+1);
        temp.pop_back();
    }

}
    

int main() {
    vector<int> arr = {1,2,3};
    subset(arr,{},0);
    for(auto i : subsets){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}