#include <bits/stdc++.h>
using namespace std;

void findMedian(int arr[], int n) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        if (maxHeap.empty() || arr[i] <= maxHeap.top()) {
            maxHeap.push(arr[i]);
        } else {
            minHeap.push(arr[i]);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() == minHeap.size()) {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        } else {
            cout << maxHeap.top() << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        findMedian(arr, n);
    }
    return 0;
}