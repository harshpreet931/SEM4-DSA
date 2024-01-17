#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "leetcode";
    string t = "practice";

    // question starts;

    map<char, int> s1, s2;
    for (auto ch : s) {
        s1[ch]++;
    }
    for (auto ch : t) {
        s2[ch]++;
    }

    int count = 0;

    auto it1 = s1.begin();
    auto it2 = s2.begin();

    while (it1 != s1.end() || it2 != s2.end()) {
        if (it1->first == it2->first) {
            if (it1->second != it2->second) {
                count += abs(it1->second - it2->second);
            }
        } else {
            count += abs(it1->second - it2->second);
        }
        it1++;
        it2++;
    }
    cout << count;

    return 0;
}
