//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
//
//
//
//Input Format
//First Line contains size of input array
//Second Line contains Array
//
//Constraints
//1 <= heights.length <= 105
//0 <= heights[i] <= 104
//
//Output Format
//Print Largest Area
//
//Sample Input
//6
//2 1 5 6 2 3
//Sample Output
//10
//Explanation
//The above is a histogram where width of each bar is 1. The largest rectangle is shown in the red area, which has an area = 10 units

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestArea(vector<int>& arr){
    stack<int> s; int m = 0, i = 0;
    while(i <= arr.size()){
        int val = i < arr.size() ? arr[i] : 0;
        if(s.empty() || val >= arr[s.top()]) s.push(i), i++;
        else{
            int h = arr[s.top()]; s.pop();
            int w = s.empty() ? i : i-s.top()-1;
            m = max(m , h*w);
        }
    }
    return m;
}

int main(){
    int n; cin >> n; vector<int> arr;
    while(n--){
        int val; cin >> val;
        arr.push_back(val);
    }
    cout << largestArea(arr);
    return 0;
}