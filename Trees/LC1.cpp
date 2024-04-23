#include <bits/stdc++.h>
using namespace std;
//100240. Minimize Manhattan Distances
//User Accepted:205
//User Tried:805
//Total Accepted:215
//Total Submissions:1252
//Difficulty:Hard
//You are given a 0-indexed array points representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].
//
//The distance between two points is defined as their Manhattan distance.
//
//Return the minimum possible value for maximum distance between any two points by removing exactly one point.
//
//
//
//Example 1:
//
//Input: points = [[3,10],[5,15],[10,2],[4,4]]
//Output: 12
//Explanation: The maximum distance after removing each point is the following:
//- After removing the 0th point the maximum distance is between points (5, 15) and (10, 2), which is |5 - 10| + |15 - 2| = 18.
//- After removing the 1st point the maximum distance is between points (3, 10) and (10, 2), which is |3 - 10| + |10 - 2| = 15.
//- After removing the 2nd point the maximum distance is between points (5, 15) and (4, 4), which is |5 - 4| + |15 - 4| = 12.
//- After removing the 3rd point the maximum distance is between points (5, 15) and (10, 2), which is |5 - 10| + |15 - 2| = 18.
//It can be seen that 12 is the minimum possible maximum distance between any two points after removing exactly one point.
//Example 2:
//
//Input: points = [[1,1],[1,1],[1,1]]
//Output: 0
//Explanation: It can be seen that removing any of the points results in the maximum distance between any two points of 0.
//
//
//Constraints:
//
//3 <= points.length <= 105
//points[i].length == 2
//1 <= points[i][0], points[i][1] <= 108

using namespace std;
int minimumDistance(vector<vector<int>>& points) {
    int n = points.size();
    vector<pair<int, int>> dir;
    
    for (auto i : points) dir.emplace_back(i[0], i[1]);
    
    sort(dir.begin(), dir.end());
    
    vector<int> maxD(n), minD(n);
    int resMax = 0, resMin = INT_MAX;

    for (int i = 1; i < n; i++) {
        int dist = abs(dir[i].first - dir[i - 1].first) + abs(dir[i].second - dir[i - 1].second);
        maxD[i] = max(maxD[i - 1], dist);
        minD[i] = min(minD[i - 1], dist);
        resMax = max(resMax, dist);
        resMin = min(resMin, dist);
    }

    int minmax = resMax;

    for (int i = 0; i < n; i++) {
        int left_max = (i == 0) ? 0 : maxD[i - 1];
        int right_max = (i == n - 1) ? 0 : maxD[n - 1] - minD[i];
        int tempMaxD = max(left_max, right_max);
        minmax = min(minmax, tempMaxD);
    }

    return minmax;
}
int main() {
    vector<vector<int>> points = {{3, 10}, {5, 15}, {10, 2}, {4, 4}};
    cout << minimumDistance(points) << endl;
    vector<vector<int>> points2 = {{1, 1}, {1, 1}, {1, 1}};
    cout << minimumDistance(points2) << endl;

    return 0;
}