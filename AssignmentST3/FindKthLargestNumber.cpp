#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<n;i++){
        int val; cin >> val; pq.push(val);
        if(pq.size() > k) pq.pop();
    }

    cout << pq.top();
    return 0;
}