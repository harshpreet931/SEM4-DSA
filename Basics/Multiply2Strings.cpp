//
// Created by HARSHPREET SINGH on 18/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

string multiply(string s1, string s2){
    if(s1 == "0" || s2 == "0") return "0";

    vector<int> res(s1.size() + s2.size(),0);

    for(int i=s1.size()-1;i>=0;i--){
        for(int j=s2.size()-1;j>=0;j--){
            res[i+j+1] += (s1[i]-'0') * (s2[j]-'0');
            res[i+j] += res[i+j+1]/10;
            res[i+j+1] %= 10;
        }
    }

    int i = 0;
    while(i<res.size() && res[i]==0) i++;
    string ans = "";
    while(i < res.size()) ans.push_back(res[i++]+'0');
    return ans;
}

int main() {
    string s1 = "123";
    string s2 = "456";
    string ans = multiply(s1,s2);
    cout << ans;
    return 0;
}