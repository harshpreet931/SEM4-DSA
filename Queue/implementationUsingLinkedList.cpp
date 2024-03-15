//
// Created by HARSHPREET SINGH on 11/03/2024.
//
#include <bits/stdc++.h>
using namespace std;

class QuwuNode{
public:
    int data;
    QuwuNode * next;
    QuwuNode(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue{
    QuwuNode * front, * back;
    int size, capacity;
public:
    Queue(int cap){
        capacity = cap;
        size = 0;
        front = back = NULL;
    }
    void push(int data){
        if(size == capacity) {
            cout << "Queue Overflow" << endl; return;
        }
        if(front == NULL){
            front = back = new QuwuNode(data);
        }
        else{
            back->next = new QuwuNode(data);
            back = back->next;
        }
        size++;
    }
    void pop(){
        if(size == 0){
            cout << "Queue Underflow" << endl; return;
        }
        else{
            QuwuNode * temp = front;
            front = front->next;
            delete temp;
        }
        size--;
    }
    int getFront(){
        if(size == 0){
            cout << "Queue is empty" << endl; return -1;
        }
        return front->data;
        }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
};


int main() {
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.isEmpty()){
        cout << q.getFront() << " ";
        q.pop();
    }
    return 0;
}