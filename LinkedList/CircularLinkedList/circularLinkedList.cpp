//
// Created by HARSHPREET SINGH on 27/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class circularLL{
public:
    Node*head;
    Node*tail;
    circularLL(){
        head = NULL;
        tail = NULL;
    }
    void insertAtEnd(int data){
        Node*newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            tail->next = head;
        }else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void insertAtStart(int data){
        Node*newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void deleteAtStart(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
        }else if(head == tail){
            head = NULL;
            tail = NULL;
        }else{
            head = head->next;
            tail->next = head;
        }
    }
    void deleteAtEnd(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
        }else if(head == tail){
            head = NULL;
            tail = NULL;
        }else{
            Node*temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = head;
            tail = temp;
        }
    }
    void display (){
        if(head == NULL) cout << "Empty";
        cout << head->data << " ";
        Node*temp = head->next;
        while(temp != head){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data;
    }

};

int main() {
    circularLL cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtStart(5);
    cll.display();
    return 0;
}