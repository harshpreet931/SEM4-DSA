#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int count = 0;
    int i = 0;
    while(n!=0 && (n&(1<<i))==0){
        count++;
        i++;
    }
    cout << count;
    return 0;
}