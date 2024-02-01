//
// Created by HARSHPREET SINGH on 22/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int start = 0, end = s.size()-1;
    while(start < end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

int main() {
    string s = "cbbd";
    int maxi = 1;
    string max_string = s.substr(0,maxi);

    for(int i=0;i<s.size();i++){
        for(int j=i+maxi;j<=s.size();j++){
            if(j-i>maxi && isPalindrome(s.substr(i,j-i))){
                maxi = j-i;
                max_string = s.substr(i,j-i);
            }
        }
    }

    cout << max_string;
    return 0;
}