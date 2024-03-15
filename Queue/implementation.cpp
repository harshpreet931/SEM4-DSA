//
// Created by HARSHPREET SINGH on 7/03/2024.
//
#include <bits/stdc++.h>
using namespace std;

class CircularQuwu{
    int front, rear, size, capacity;
    int * arr;
public:
    CircularQuwu(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0, rear = capacity - 1, size = 0;
    }
    void push(int data){
        if(size == capacity) return;
        rear = (rear + 1) % capacity;
        size++;
        arr[rear] = data;
    }
};

int main() {

    return 0;
}