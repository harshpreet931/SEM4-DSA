//Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.
//
//You need not have to create a new list. Just reverse the old one using head.
//
//Input Format
//The first line contains 2 space separated integers N and K
//
//The next line contains N space separated integral elements of the list.
//
//Constraints
//0 <= N <= 10^6 0 <= K <= 10^6
//
//Output Format
//Display the linkedlist after reversing every k elements
//
//Sample Input
//9 3
//9 4 1 7 8 3 2 6 5
//Sample Output
//1 4 9 3 8 7 5 6 2
//Explanation
//N = 9 & K = 3
//
//Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5
//
//After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int data) {
    if (head == NULL) {
        head = new Node(data);
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

Node* reverse(Node* head, int k) {
    if (!head || k <= 0) return head;

    Node* prev = NULL, *curr = head, *next = NULL;
    int count = 0;

    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next) head->next = reverse(next, k);

    return prev;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtEnd(head, val);
    }

    head = reverse(head, k);

    while (head) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}