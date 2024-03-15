//Given two numbers represented by two linked lists, write a program that prints the sum list. The sum list is linked list representation of addition of two input numbers in linked lists. It is not allowed to modify the lists. Also, not allowed to use explicit extra space (Use Recursion).
//
//Input Format
//First line contains N,M, number of nodes in the 1st and 2nd list.
//Next line contains N nodes of 1st list.
//Next line contains M nodes of 2nd list.
//
//Constraints
//0<N<10^6
//
//Output Format
//Print the sum list after adding the two linked lists.
//
//Sample Input
//3 3
//5 6 3
//8 4 2
//Sample Output
//1 4 0 5
//Explanation
//        After adding the two numbers represented by linked lists i.e. 563 + 842 =1405 is represented as sum list. Sum list =1 -> 4 -> 0 -> 5.


#include<iostream>
#include<bits/stdc++.h>
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

void insertAtEnd(Node *& head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(data);
}

Node* addTwoNumbers(Node * l1, Node * l2){
    int carry = 0;
    stack<int> s1,s2;
    while(l1){
        s1.push(l1->data); l1 = l1->next;
    }
    while(l2){
        s2.push(l2->data); l2 = l2->next;
    }
    stack<int> res;
    while(!s1.empty() || !s2.empty()){
        int sum = 0;
        if(!s1.empty()){
            sum += s1.top(); s1.pop();
        }
        if(!s2.empty()){
            sum += s2.top(); s2.pop();
        }
        sum += carry;
        carry = sum/10;
        res.push(sum%10);
    }
    if(carry == 1){
        res.push(1);
    }
    Node * head = new Node(0);
    Node * temp = head;
    while(!res.empty()){
        temp->next = new Node(res.top());
        res.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return head->next;
}


int main () {
    Node *l1 = NULL, *l2 = NULL;
    int n, m; cin >> n >> m;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        insertAtEnd(l1,val);
    }
    for(int i=0;i<m;i++){
        int val; cin >> val;
        insertAtEnd(l2,val);
    }

    Node * ans = addTwoNumbers(l1,l2);
    while(ans){
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}