//
// Created by HARSHPREET SINGH on 3/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

//100211. Apply Operations to Make String Empty
//You are given a string s.
//
//Consider performing the following operation until s becomes empty:
//
//For every alphabet character from 'a' to 'z', remove the first occurrence of that character in s (if it exists).
//Return the value of the string s right before applying the last operation.
//
//
//
//Example 1:
//
//Input: s = "aabcbbca"
//Output: "ba"
//Explanation: We do the following operations:
//- Remove the underlined characters s = "aabcbbca". The resulting string is s = "abbca".
//- Remove the underlined characters s = "abbca". The resulting string is s = "ba".
//- Remove the underlined characters s = "ba". The resulting string is s = "".
//The string just before the last operation is "ba".
//Example 2:
//
//Input: s = "abcd"
//Output: "abcd"
//Explanation: We do the following operation:
//- Remove the underlined characters s = "abcd". The resulting string is s = "".
//The string just before the last operation is "abcd".


string lastNonEmptyString(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        if (--freq[s[i] - 'a'] == 0) {
            res = s.substr(0, i + 1);
            break;
        }
    }
    return res;
}


int main() {
    string s = "aabcbbca";
    cout << lastNonEmptyString(s) << endl;
    string s2 = "abcd";
    cout << lastNonEmptyString(s2) << endl;
    return 0;

}