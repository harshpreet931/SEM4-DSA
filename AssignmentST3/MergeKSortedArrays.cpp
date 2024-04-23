#include<bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int,vector<int>, greater<int>> pq;
    int n, k; cin >> n >> k;
    for(int i=0;i<n*k;i++){
        int val; cin >> val;
        pq.push(val);
    }
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}