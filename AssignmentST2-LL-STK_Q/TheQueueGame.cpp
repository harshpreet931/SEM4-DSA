//The Game is as follows You have given a binary array, where 1 denotes push operation and 0 denotes a pop operation in a queue. The task is to check if the possible set of operations are valid or not.
//Print Valid if the set of Operations are Valid Otherwise Print Invalid.
//
//Input Format
//The First Line contains an Integer T, as the number of Test cases.
//The Next Line contains an Integer N, as the Size of the Array.
//The Next Line contains N Binary numbers separated by space.
//
//Constraints
//Output Format
//Print Valid If the set of operations are valid Otherwise Print Invalid for each Test Case separated by a new Line.
//
//Sample Input
//2
//5
//1 1 0 0 1
//5
//1 1 0 0 0
//Sample Output
//Valid
//Invalid

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    // making a min-heap of absolute difference and corresponding array value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // store the difference one by one with the array value
    for (int i = 0; i < arr.size(); i++)
        pq.push({abs(arr[i] - x), arr[i]});

    vector<int> ans;

    // get the top of the heap i.e. the element with minimum absolute difference
    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop(); // pop it k times
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main () {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int valid = 0;
        bool check = true;
        while(n--){
            int val; cin >> val;
            if(val == 1) valid++;
            else{
                if(valid == 0){
                    check = false;
                }
                valid--;
            }
        }
        if(check) cout << "Valid" << endl;
        else cout << "Invalid" << endl;
    }
    return 0;
}