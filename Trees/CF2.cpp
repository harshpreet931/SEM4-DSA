#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

int helper(){
    ll n, k; cin >> n >> k; vector<ll> arr(n);
    ll sigma = 0, sum = 0, maxi = 0, p = 1;
    for (int i = 0; i < n; i++) { cin >> arr[i]; sigma += arr[i]; }
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sum < 0 ? sum = 0 : 0;
        maxi = max(maxi, sum);
    }
    for (int i = 0; i < k; i++) p = (p * 2) % MOD;
    ll ans = (maxi * (p - 1)) % MOD;
    ll fin = (ans + sigma) % MOD;
    fin < 0 ? fin += MOD : 0;
    cout << fin << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) helper();

    return 0;
}