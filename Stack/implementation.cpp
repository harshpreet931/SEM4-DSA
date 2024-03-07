//
// Created by HARSHPREET SINGH on 28/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

class Stack{
    int * arr;
    int top;
    int capacity;
public:
    Stack(int capacity){
        arr = new int[capacity];
        top = -1;
        this->capacity = capacity;
    }

    void push(int x){
        if(top == capacity-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    int peek(){
        if(top == -1){
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }

    void display(){
        for(int i = 0; i < top; i++){
            cout << arr[i] << "->";
        }
        cout << arr[top] <<  endl;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.display();
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;

    while(!s.isEmpty()){
        cout << s.peek() << endl;
        s.pop();
    }

    return 0;
}