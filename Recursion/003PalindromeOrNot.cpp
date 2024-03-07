#include <bits/stdc++.h>
using namespace std;

bool isPalin(string s, int start, int end) {
    if (start >= end)
        return true;
    if (s[start] != s[end])
        return false;
    return isPalin(s, start + 1, end - 1);
}

int main() {
    string str = "abccba";
    if (isPalin(str, 0, str.size() - 1)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}
