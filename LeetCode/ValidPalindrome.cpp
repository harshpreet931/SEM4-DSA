//
// Created by HARSHPREET SINGH on 25/01/2024.
//


#include <bits/stdc++.h>
using namespace std;

bool helper(string str,int start,int end){
    if(start>end) return true;
    if(str[start] != str[end]) return false;
    return helper(str,start+1,end-1);
}
bool isPalindrome(string s) {
    string res = "";
    for(char c : s){
        if(isupper(c) || islower(c)) res += tolower(c);
    }
    return helper(res,0,res.size()-1);
}

int main() {
    string str = "A man, a plan, a canal: Panama";
    if(isPalindrome(str)) cout << "True";
    else cout << "False";
    return 0;
}