#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = tail = NULL;
    }

    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtStart(int data){
        Node* newNode = new Node(data);
        if(!head){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtIndex(int data, int idx){
        if(idx==0){
            insertAtStart(data);
            return;
        }
        Node* temp = head;
        for(int i=0;i<idx-1;i++){
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
    }

    void print() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(0);
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtStart(-1);
    dll.insertAtIndex(4,4);
    dll.print();
    return 0;
}
