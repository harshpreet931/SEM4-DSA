//
// Created by HARSHPREET SINGH on 2/04/2024.
//
#include <bits/stdc++.h>
using namespace std;

// Implementing Heap. MaxHeap.

class heap {
    int *arr;
    int size;
    int capacity;
public:
    heap(int c) {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    void push(int x) { // time complexity O(logn)
        if (size == capacity) {
            cout << "Heap is full" << endl;
            return;
        }
        arr[size] = x;
        int i = size;
        size++;

        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void pop() { // time complexity O(logn)
        if (size == 0) {
            cout << "Empty" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        int i = 0;
        while (i < size) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size && arr[left] > arr[i] && arr[left] > arr[right]) {
                swap(arr[left], arr[i]);
                i = left;
            } else if (right < size && arr[right] > arr[i] && arr[right] > arr[left]) {
                swap(arr[right], arr[i]);
                i = right;
            } else {
                break;
            }
        }
    }

    int top() {
        if (size == 0) return -1;
        return arr[0];
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(vector<int>& arr, int n, int i){ // time complexity O(logn)
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr, int n){
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}

int main() {
    heap h(10);
    h.push(10);
    h.push(20);
    h.push(30);
    h.push(40);
    h.push(50);
    h.push(60);
    h.push(70);
    h.print();
    vector<int> arr = {10, 20, 15, 17, 9, 21};
    heapSort(arr, arr.size());
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}