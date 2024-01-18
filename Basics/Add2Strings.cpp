#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "1294";
    string s2 = "540000";

    string res = "";

    int carry = 0;

    int i = s1.size()-1;
    int j = s2.size()-1;

    while(i >= 0 || j >= 0){
        int d1 = i >= 0 ? s1[i]-'0' : 0;
        int d2 = j >= 0 ? s2[j]-'0' : 0;
        int sum = d1 + d2 + carry;
        res += (char)(sum%10 + '0');
        carry = sum / 10;
        i--; j--;
    }
    if(carry == 1) res += '1';
    reverse(res.begin(),res.end());
    cout << res << endl;
    return 0;
}
