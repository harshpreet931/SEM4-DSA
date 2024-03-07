#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n; long long sum = 0, temp; for(int i=0;i<n-1;i++) cin >> temp, sum+=temp;
    long long idealSum = n*(n+1)/2;
    cout << idealSum - sum;
    return 0;
}