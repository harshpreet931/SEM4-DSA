//
// Created by HARSHPREET SINGH on 25/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sum3(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    set<vector<int>> s;
    vector<vector<int>> vec;

    for(int i=0;i<n-2;i++){
        int left = i+1;
        int right = n-1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0){
                s.insert({nums[i],nums[left],nums[right]});
                left++;
                right--;
            }
            else if(sum < 0){
                left++;
            }
            else{
                right--;
            }
        }
    }

    for(auto i : s){
        vec.push_back(i);
    }
    return vec;
}

int main() {
    vector<int> li = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = sum3(li);
    for(auto i : res){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}