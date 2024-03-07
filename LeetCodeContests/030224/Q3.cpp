//
// Created by HARSHPREET SINGH on 3/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

//100183. Maximum Good Subarray Sum
//User Accepted:382
//User Tried:1739
//Total Accepted:383
//Total Submissions:3624
//Difficulty:Medium
//You are given an array nums of length n and a positive integer k.
//
//A subarray of nums is called good if the absolute difference between its first and last element is exactly k, in other words, the subarray nums[i..j] is good if |nums[i] - nums[j]| == k.
//
//Return the maximum sum of a good subarray of nums. If there are no good subarrays, return 0.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3,4,5,6], k = 1
//Output: 11
//Explanation: The absolute difference between the first and last element must be 1 for a good subarray. All the good subarrays are: [1,2], [2,3], [3,4], [4,5], and [5,6]. The maximum subarray sum is 11 for the subarray [5,6].
//Example 2:
//
//Input: nums = [-1,3,2,4,5], k = 3
//Output: 11
//Explanation: The absolute difference between the first and last element must be 3 for a good subarray. All the good subarrays are: [-1,3,2], and [2,4,5]. The maximum subarray sum is 11 for the subarray [2,4,5].
//Example 3:
//
//Input: nums = [-1,-2,-3,-4], k = 2
//Output: -6
//Explanation: The absolute difference between the first and last element must be 2 for a good subarray. All the good subarrays are: [-1,-2,-3], and [-

long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n);
    prefix[0] = nums[0];
    unordered_map<int, vector<int>> indices;
    indices[nums[0]].push_back(0);

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + nums[i];
        indices[nums[i]].push_back(i);
    }

    long long ans = -(pow(2, 53) - 1);
    for(int i = 0; i < n; i++) {
        for(int diff : {k, -k}) {
            if(indices.count(nums[i] + diff)) {
                for(int j : indices[nums[i] + diff]) {
                    if(j > i) {
                        long long sum = prefix[j] - (i > 0 ? prefix[i-1] : 0);
                        ans = max(ans, sum);
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    int k = 1;
    cout<<maximumSubarraySum(nums,k) << endl;
    vector<int> nums1 = {-1,3,2,4,5};
    int k1 = 3;
    cout<<maximumSubarraySum(nums1,k1) << endl;
    vector<int> nums2 = {-1,-2,-3,-4};
    int k2 = 2;
    cout<<maximumSubarraySum(nums2,k2) << endl;

    cout << abs(-1-(-3)) << endl;
    return 0;
}