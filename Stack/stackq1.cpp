//
// Created by HARSHPREET SINGH on 28/02/2024.
//

// reverse a stack like 1 - > 2 - > 3 - > 4 as 4 - > 3 - > 2 - > 1 without extra space
#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n)
{
    stack<
}

vector<long long> printNGE(vector<long long> &arr, int n){
    vector<long long> res;
    stack<long long> s;
    for(int i = n-1; i >= 0; i--){
        if(s.empty()){
            res.push_back(-1);
        }
        else if(s.top() > arr[i]){
            res.push_back(s.top());
        }
        else{
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                res.push_back(-1);
            }
            else{
                res.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(res.begin(),res.end());
    return res;

}

void stackI(stack<int>s, stack<int>&res){
    if(s.empty()){
        return;
    }
    int peek = s.top();
    s.pop();
    stackI(s,res);
    res.push(peek);
}

void insertAtBottom(stack<int>&s, int toInsert){
    if(s.empty()){
        s.push(toInsert);
        return;
    }
    int peek = s.top();
    s.pop();
    insertAtBottom(s,toInsert);
    s.push(peek);
}

void reverse(stack<int>&s){
    if(s.empty()){
        return;
    }
    int peek = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,peek);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    stack<int> res;
    stackI(s,res);

    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    cout << endl;
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}