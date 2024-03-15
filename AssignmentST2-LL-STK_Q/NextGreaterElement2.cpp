//You are given a circular integer array nums
//
//The next element of nums[nums.length - 1] is nums[0]), print the next greater number for every element in nums.
//The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, print -1 for this number.
//
//Input Format
//First line contains an integer n ( size of the array).
//
//Second line contains an integer array of size n.
//
//Constraints
//1 <= n <= 105
//-104 nums[i] <= 104
//
//Output Format
//print the next greater number for every element in nums.
//
//Sample Input
//5
//1 2 3 4 3
//Sample Output
//2 3 4 -1 4
//Explanation
//2 3 4 -1 4 are the next greater elements of the corresponding array elements .

#include <bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int>&nums){
    int n = nums.size();
    vector<int> res(n,-1);
    stack<int>st;
    for(int i=0;i<n*2;i++){
        while(!st.empty() && nums[i%n] > nums[st.top()]){
            res[st.top()] = nums[i%n];
            st.pop();
        }
        st.push(i%n);
    }
    return res;
}

int main() {
    int n; cin >> n; vector<int> arr; for(int i=0;i<n;i++){
        int val; cin >> val; arr.push_back(val);
    }
    vector<int> res = nge(arr);
    for(int i : res){
        cout << i << " ";
    }
}
