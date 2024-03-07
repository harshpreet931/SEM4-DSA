//
// Created by HARSHPREET SINGH on 28/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    Node * top;
    int size;
    int capacity;
public:
    Stack(int c){
        top = NULL;
        size = 0;
        capacity = c;
    }
    void push(int x){
        if(size == capacity){
            cout << "OVERFLOW" << endl;
            return;
        }
        if(top == NULL){
            top = new Node(x);
            size++;
            return;
        }
        Node * toPush = new Node(x);
        toPush->next = top;
        top = toPush;
        size++;
    }
    void pop(){
        if(top == NULL){
            cout << "UNDERFLOW" << endl;
            return;
        }
        Node * temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek(){
        if(top == NULL){
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        if(top == NULL) return true;
        else return false;
    }
};

int main() {
    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.isEmpty()){
        cout << s.peek() << endl;
        s.pop();
    }
    s.pop();
    return 0;
}