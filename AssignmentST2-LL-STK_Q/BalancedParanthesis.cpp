//You are given a string of brackets i.e. '{', '}' , '(' , ')', '[' , ']' . You have to check whether the sequence of parenthesis is balanced or not.
//For example, "(())", "(())()" are balanced and "())(", "(()))" are not.
//
//Input Format
//A string of '(' , ')' , '{' , '}' and '[' , ']' .
//
//Constraints
//1<=|S|<=10^5
//
//Output Format
//Print "Yes" if the brackets are balanced and "No" if not balanced.
//
//Sample Input
//(())
//Sample Output
//Yes
//Explanation
//(()) is a balanced string.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isBal(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '{' || c == '(' || c == '[') stk.push(c);
        else{
            if(stk.empty()) return false;
            else if(stk.top() == '(' && c == ')') stk.pop();
            else if(stk.top() == '{' && c == '}') stk.pop();
            else if(stk.top() == '[' && c == ']') stk.pop();
            else{
                return false;
            }
        }
    }
    return stk.empty();
}
int main() {
    string str; cin >> str;
    if(isBal(str)) cout << "Yes";
    else cout << "No";
    return 0;
}