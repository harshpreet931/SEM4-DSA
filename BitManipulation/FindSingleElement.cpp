//
// Created by HARSHPREET SINGH on 2/02/2024.
//


#include <bits/stdc++.h>
using namespace std;

vector<int> elements2(vector<int> arr){
    int x = 0;
    for(int i : arr){
        x = x^i;
    }
    int p = 0;
    while((x&1)==0){
        p++;
        x = x >> 1;
    }

    int num1 = 0, num2 = 0;
    for(int i : arr){
        if(((i>>p) & 1) == 1){
            num1 = num1 ^ i;
        }
        else{
            num2 = num2 ^ i;
        }
    }
    return {num1,num2};
}

int main() {
    int ans = 0;
    vector<int> arr = {1,2,4,3,2,4,1,5,6,7,8,6,8,7};
    for(int i=0;i<arr.size();i++){
        ans = ans^arr[i];
    }
    cout<<ans << endl;
    vector<int> res = elements2(arr);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}