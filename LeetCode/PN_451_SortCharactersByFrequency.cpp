//
// Created by HARSHPREET SINGH on 21/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcAbc";
    map<char,int> mp;
    for(char c : s) mp[c]++;
    for(auto i : mp) cout << i.first << " " << i.second << endl;

    priority_queue<pair<int,char>> pq;
    for(auto i : mp){
        pq.push({i.second,i.first});
    }
    s = "";
    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        s += string(pq.top().first,pq.top().second);
        pq.pop();
    }
    cout << s << endl;

    string res = string(10,'a');
    cout << res;

    priority_queue<int> test;
    test.push(10);
    test.push(20);
    test.push(30);
    test.push(40);

    while(!test.empty()){
        cout << test.top() << endl;
        test.pop();
    }

}