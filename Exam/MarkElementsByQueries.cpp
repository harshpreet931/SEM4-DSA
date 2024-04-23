//
// Created by HARSHPREET SINGH on 16/03/2024.
//
#include <bits/stdc++.h>
using namespace std;

//100209. Mark Elements on Array by Performing Queries
//User Accepted:0
//User Tried:0
//Total Accepted:0
//Total Submissions:0
//Difficulty:Medium
//You are given a 0-indexed array nums of size n consisting of positive integers.
//
//You are also given a 2D array queries of size m where queries[i] = [indexi, ki].
//
//Initially all elements of the array are unmarked.
//
//You need to apply m queries on the array in order, where on the ith query you do the following:
//
//Mark the element at index indexi if it is not already marked.
//Then mark ki unmarked elements in the array with the smallest values. If multiple such elements exist, mark the ones with the smallest indices. And if less than ki unmarked elements exist, then mark all of them.
//Return an array answer of size m where answer[i] is the sum of unmarked elements in the array after the ith query.
//
//
//
//Example 1:
//
//Input: nums = [1,2,2,1,2,3,1], queries = [[1,2],[3,3],[4,2]]
//
//Output: [8,3,0]
//
//Explanation:
//
//We do the following queries on the array:
//
//Mark the element at index 1, and 2 of the smallest unmarked elements with the smallest indices if they exist, the marked elements now are nums = [1,2,2,1,2,3,1]. The sum of unmarked elements is 2 + 2 + 3 + 1 = 8.
//Mark the element at index 3, since it is already marked we skip it. Then we mark 3 of the smallest unmarked elements with the smallest indices, the marked elements now are nums = [1,2,2,1,2,3,1]. The sum of unmarked elements is 3.
//Mark the element at index 4, since it is already marked we skip it. Then we mark 2 of the smallest unmarked elements with the smallest indices if they exist, the marked elements now are nums = [1,2,2,1,2,3,1]. The sum of unmarked elements is 0.
//Example 2:
//
//Input: nums = [1,4,2,3], queries = [[0,1]]
//
//Output: [7]
//
//Explanation: We do one query which is mark the element at index 0 and mark the smallest element among unmarked elements. The marked elements will be nums = [1,4,2,3], and the sum of unmarked elements is 4 + 3 = 7.
//
//#include <bits/stdc++.h>
//using namespace std;
//
//struct Num {
//    int val, idx;
//    bool operator<(const Num& o) const {
//        return val == o.val ? idx < o.idx : val < o.val;
//    }
//};
//
//vector<long long> solve(vector<int>& nums, vector<vector<int>>& queries) {
//    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
//    set<int> marked;
//    vector<long long> ans;
//    vector<Num> sorted(nums.size());
//    for (int i = 0; i < nums.size(); i++) sorted[i] = {nums[i], i};
//    sort(sorted.begin(), sorted.end());
//    int next = 0;
//    for (auto& q : queries) {
//        int idx = q[0], k = q[1];
//        if (marked.find(idx) == marked.end()) {
//            marked.insert(idx);
//            sum -= nums[idx];
//        }
//        while (k && next < nums.size()) {
//            while (next < nums.size() && marked.count(sorted[next].idx)) next++;
//            if (next < nums.size()) {
//                marked.insert(sorted[next].idx);
//                sum -= sorted[next++].val;
//                k--;
//            }
//        }
//        ans.push_back(sum);
//    }
//    return ans;
//}
//
//int main() {
//    vector<int> nums = {1, 2, 2, 1, 2, 3, 1};
//    vector<vector<int>> queries = {{1, 2}, {3, 3}, {4, 2}};
//    for (auto r : solve(nums, queries)) cout << r << " ";
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

vector<long long> solve(vector<int>& nums, vector<vector<int>>& queries) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    set<int> marked;
    vector<long long> ans;
    vector<pair<int, int>> sorted(nums.size());
    for (int i = 0; i < nums.size(); i++) sorted[i] = {nums[i], i};
    sort(sorted.begin(), sorted.end(), cmp);
    int next = 0;
    for (auto& q : queries) {
        int idx = q[0], k = q[1];
        if (!marked.count(idx)) {
            marked.insert(idx);
            sum -= nums[idx];
        }
        while (k && next < nums.size()) {
            while (next < nums.size() && marked.count(sorted[next].second)) next++;
            if (next < nums.size()) {
                marked.insert(sorted[next].second);
                sum -= sorted[next++].first;
                k--;
            }
        }
        ans.push_back(sum);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 1, 2, 3, 1};
    vector<vector<int>> queries = {{1, 2}, {3, 3}, {4, 2}};
    for (auto r : solve(nums, queries)) cout << r << " ";
    return 0;
}