//Implement a Queue using two stacks Make it Dequeue efficient.
//
//Input Format
//Enter the size of the queue N add 0 - N-1 numbers in the queue
//
//Constraints
//Output Format
//Display the numbers in the order they are dequeued and in a space separated manner
//
//Sample Input
//5
//Sample Output
//0 1 2 3 4

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Kyu{
    stack<int> s1,s2;
public:
    void push(int data){
        s1.push(data);
    }
    int dequeue(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int data = s2.top();
        s2.pop();
        return data;
    }
};

int main() {
    int n;cin >> n;
    Kyu q;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    for(int i=0;i<n;i++){
        cout << q.dequeue() << " ";
    }
    return 0;
}