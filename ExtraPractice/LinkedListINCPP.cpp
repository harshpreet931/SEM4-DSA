//
// Created by HARSHPREET SINGH on 22/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

// this is basically the full structure
// after this we just have to make functions and all;
class Node{
public:
    int val;
    Node* next;

    Node(int data, Node* nextone){
        next = nextone;
        val = data;
    }
    Node(int data){
        val = data;
        next = nullptr;
    }
};

int main() {
    Node*y = new Node(10);
    cout << y << endl;
    cout << y->val;
    return 0;
}