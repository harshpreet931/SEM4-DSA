//Given a linked list, sort it using the merge sort algorithm.
//
//Input Format
//First line of input contains integer N, denoting the size of the linked list. Next line of input contains N space separated integers denoting the elements of the linked list.
//
//Constraints
//1<=N<=10^3
//
//Output Format
//Print the elements of the linked list after sorting.
//
//Sample Input
//5
//5 4 3 2 1
//Sample Output
//1 2 3 4 5
//Explanation
//5 4 3 2 1 will become 1 2 3 4 5 after sorting.

#include<iostream>
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

Node* merge(Node * a, Node * b){
    Node * res = NULL;
    if(a == NULL) return b;
    if(b == NULL) return a;

    if(a->data <= b->data){
        res = a;
        res->next = merge(a->next,b);
    }
    else{
        res = b;
        res->next = merge(a,b->next);
    }
    return res;
}

Node* mergeSort(Node * head){
    if(head == NULL || head->next == NULL) return head;
    Node * slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node * second = slow->next;
    slow->next = NULL;
    Node * left = mergeSort(head);
    Node * right = mergeSort(second);
    return merge(left,right);
}

int main () {
    int n; cin >> n;
    Node * head = NULL;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        insertAtEnd(head,val);
    }
    head = mergeSort(head);
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}