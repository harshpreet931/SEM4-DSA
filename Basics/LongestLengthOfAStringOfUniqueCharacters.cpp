//
// Created by HARSHPREET SINGH on 18/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int longestSIREDITION(string s){
    int arr[26] = {0};
    int i = 0, j = 0;
    int ans = 0;
    while(j < s.size()){
        arr[s[j]-'a']++;
        while(arr[s[j]-'a'] > 1){
            arr[s[i]-'a']--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}

int main() {
    string str = "acbdabxlmdnamb";
    unordered_set<char> s;
    int maxi = 0;
    int i = 0, j = 0;
    while(j < str.size()){
        if(s.find(str[j]) == s.end()){
            s.insert(str[j++]);
            maxi = max(maxi, j - i);
        }
        else{
            s.erase(str[i++]);
        }
    }
    cout << maxi << endl;
    cout << longestSIREDITION(str) << endl;
    return 0;
}