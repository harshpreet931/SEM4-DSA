#include <bits/stdc++.h>
using namespace std;
//100237. Count Submatrices with Top-Left Element and Sum Less Than k
//User Accepted:3
//User Tried:3
//Total Accepted:3
//Total Submissions:3
//Difficulty:Medium
//You are given a 0-indexed integer matrix grid and an integer k.
//
//Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
//
//
//
//Example 1:
//
//
//Input: grid = [[7,6,3],[6,6,1]], k = 18
//Output: 4
//Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
//Example 2:
//
//
//Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
//Output: 6
//Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
//
//
//Constraints:
//
//m == grid.length
//n == grid[i].length
//1 <= n, m <= 1000
//0 <= grid[i][j] <= 1000
//1 <= k <= 106
// the matrix always starts from 0,0
// so we go only in 3 directions, right, down and diagonally

int countSubmatrices(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefixSum[i][j] = grid[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    for (int p = 1; p <= m; ++p) {
        for (int q = 1; q <= n; ++q) {
            int _sum = prefixSum[p][q];
            if (_sum <= k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> grid = {{7, 6, 3},
                                {6, 6, 1}};
    int k = 18;
    cout << countSubmatrices(grid, k) << endl; // Output should be 4

    vector<vector<int>> grid1 = {{7, 2, 9},
                                 {1, 5, 0},
                                 {2, 6, 6}};
    int k1 = 20;
    cout << countSubmatrices(grid1, k1) << endl; // Output should be 6

    return 0;
}