//
// Created by HARSHPREET SINGH on 16/02/2024.
//


#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr = {2,2,1,5};
    int k = 1;
    map<int,int> mp;
    for(int i : arr) mp[i]++;

    priority_queue<int,vector<int>, greater<int>>pq;
    for(auto it : mp) pq.push(it.second);
    int res = mp.size();

    while(k > 0 && !pq.empty()){
        int temp = pq.top();
        pq.pop();
        if(temp <= k) k-=temp;
        else break;
        res--;
    }
    cout << res << endl;
    return 0;
}