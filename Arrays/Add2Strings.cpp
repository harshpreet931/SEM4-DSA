#include <bits/stdc++.h>
using namespace std;
 // do this and 3rd question on leetcode
 // currently wrong
int main() {
    string s1 = "1294";
    string s2 = "5432100";

    string res = "";

    int carry = 0;

    for(int i = s2.size() - 1; i >= 0; i--) {
        int curr = (s2[i] - '0') + (s1[i] - '0') + carry;

        if(curr > 9) {
            carry = 1;
            curr %= 10;
        } else {
            carry = 0;
        }

        res[i] = (char)(curr + '0');
    }

    if (carry > 0) {
        res.insert(s2.begin(), '1');
    }

    cout << res << endl;


    return 0;
}
