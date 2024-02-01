#include <bits/stdc++.h>
using namespace std;

void wavePrint(vector<vector<int>> arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    for (int i = 0; i < cols; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < rows; j++) {
                cout << arr[j][i] << " ";
            }
        } else {
            for (int j = rows - 1; j >= 0; j--) {
                cout << arr[j][i] << " ";
            }
        }
    }
}

void spiralPrint(vector<vector<int>> matrix){
    int top = 0, left = 0, right = matrix[0].size()-1, bottom = matrix.size()-1;

    vector<int> res;
    while(top <= bottom && left <= right){
        for(int i=left;i<=right;i++){
            cout << (matrix[top][i]) << " ";
        }
        top++;

        for(int i=top; i<=bottom; i++){
            cout << (matrix[i][right]) << " ";
        }
        right--;

        if(top <= bottom){
            for(int i=right;i>=left;i--){
                cout << (matrix[bottom][i]) << " ";
            }
            bottom--;
        }
        if(left <= right){
            for(int i=bottom;i>=top;i--){
                cout << (matrix[i][left]) << " ";
            }
            left++;
        }
    }

}

int main() {
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    wavePrint(arr); cout << endl;
    spiralPrint(arr);
    return 0;
}
