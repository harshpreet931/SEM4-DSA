//
// Created by HARSHPREET SINGH on 20/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

class LinkedList{
public:
    int data;
    LinkedList* next;
    LinkedList(int data){
        this->data = data;
        this->next = NULL;
    }
};

void display(LinkedList* head){
    LinkedList* temp = head;
    while(temp){
        cout << temp->data << " - > ";
        temp = temp->next;
    }cout << "NULL" << endl;
}

void insertAtEnd(LinkedList* &head, int data){
    LinkedList* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new LinkedList(data);
}

void insertAtStart(LinkedList*& head, int data){
    if(head==NULL){
        head = new LinkedList(data);
        return;
    }
    LinkedList* temp = new LinkedList(data);
    temp->next = head;
    head = temp;
}

void insertAtIndex(LinkedList* &head, int data, int index){
    if(index==0){
        insertAtStart(head, data);
        return;
    }
    LinkedList* temp = head;
    for(int i=0;i<index-1;i++){
        temp = temp->next;
    }
    LinkedList* newNode = new LinkedList(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

bool search(LinkedList* head, int x){
    LinkedList* temp = head;
    while(temp){
        if(temp->data == x) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deletion(LinkedList* &head, int data){
    if(head==NULL)return;
    if(head->data == data){
        LinkedList* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    LinkedList* temp = head;
    while(temp->next){
        if(temp->next->data == data){
            LinkedList* todel = temp->next;
            temp->next = temp->next->next;
            delete todel;
            return;
        }
        temp = temp->next;
    }
}

int main() {
    LinkedList* head = new LinkedList(10);
    head->next = new LinkedList(20);
    head->next->next = new LinkedList(30);
    head->next->next->next = new LinkedList(40);

    display(head);

    insertAtEnd(head, 50);

    display(head);

    insertAtStart(head, 5);

    display(head);

    cout << search(head, 10) << endl; // 1 is trueeeeeeeeeeeeeeeeeeeee rem
    cout << search(head, 100) << endl;


    deletion(head,50);
    display(head);
    deletion(head,5);
    display(head);

    insertAtIndex(head, 100, 2);
    display(head);
    insertAtIndex(head, 200, 0);
    display(head);
    return 0;
}