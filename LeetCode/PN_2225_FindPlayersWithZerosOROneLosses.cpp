#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, pair<int, int>> mp;

    // Count wins and losses for each player
    for (auto i : matches) {
        mp[i[0]].first++; // this is for winning
        mp[i[1]].second++; // this is for losing
    }

    vector<int> wins;
    vector<int> losses;

    // Identify players with no losses and at least one win as winners
    for (auto i : mp) {
        if (i.second.second == 0 && i.second.first > 0) {
            wins.push_back(i.first);
        }
        else if (i.second.second > 0) {
            losses.push_back(i.first);
        }
    }

    // Create the result vector
    vector<vector<int>> ans;
    ans.push_back(wins);
    ans.push_back(losses);

    return ans;
}

int main() {
    int matches[][2] = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    vector<vector<int>> ans = findWinners(matches);

    // Output the results
    cout << "Winners: ";
    for (auto i : ans[0]) {
        cout << i << " ";
    }

    cout << "\nLosers: ";
    for (auto i : ans[1]) {
        cout << i << " ";
    }

    return 0;
}
