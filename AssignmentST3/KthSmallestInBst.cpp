#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        pq.push(val);
    }

    int k; cin >> k;
    for(int i=0;i<k-1;i++){
        pq.pop();
    }
    cout << pq.top();
}