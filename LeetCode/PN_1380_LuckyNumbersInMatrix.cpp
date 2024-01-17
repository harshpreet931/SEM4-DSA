//
// Created by HARSHPREET SINGH on 16/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> rowsMax;
    vector<int> colsMax;
    for(int i=0;i<matrix.size();i++){
        int maxRow = INT_MIN;
        for(int j=0;j<matrix[i].size();j++){
            maxRow = max(maxRow, matrix[i][j]);
        }
        rowsMax.push_back(maxRow);

        int maxCol = INT_MIN;
        for(int j=0;j<matrix[i].size();j++){
            maxCol = max(maxCol, matrix[j][i]);
        }
        colsMax.push_back(maxCol);
    }

    vector<int> res;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j] < rowsMax[i] && matrix[i][j] > colsMax[j]){
                res.push_back(matrix[i][j]);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    vector<int> res = luckyNumbers(matrix);
    for(auto i : res){
        cout << i << " ";
    }
    return 0;
}