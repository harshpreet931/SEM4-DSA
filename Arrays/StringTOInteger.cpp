//
// Created by HARSHPREET SINGH on 17/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "21456";
    int res = 0;
    int j = s.size()-1;
    for(int i = 0; i<s.size();i++){
        res += (s[i]-'0') * (int)pow(10,j);
        j--;
    }
    cout << res;
    return 0;
}