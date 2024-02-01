//
// Created by HARSHPREET SINGH on 30/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>&arr){
    int n = arr.size();
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j] == '.') continue;

            for(int k=i+1;k<n;k++){
                if(arr[i][j] == arr[k][j]) return false;
            }
            for(int k=j+1;k<n;k++){
                if(arr[i][j] == arr[i][k]) return false;
            }

            for(int a = i/3*3; a < i/3*3+3; a++){
                for(int b = j/3*3; b < j/3*3+3; b++){
                    if(arr[a][b] == arr[i][j] && i!=a && j!=b) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},

        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','.','9'},
    };
    cout << isValidSudoku(board);
    return 0;
}