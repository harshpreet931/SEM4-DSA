#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n; cin >> n; vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin >> arr[i];

        sort(arr.begin(), arr.end());
        ll res = 1;
        ll m;
        n%2 == 0 ? m = n/2 : m = (n+1)/2;
        for(ll i=m-1; i<n-1;i++){
            if(arr[i] != arr[i+1]) break;
            else res++;
        }
        cout << res << endl;
    }
    return 0;
}