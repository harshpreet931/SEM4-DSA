#include<iostream>
using namespace std;
//Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.
//
//Input Format
//First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.
//
//Constraints
//n < 10^5
//
//Output Format
//Output a single line containing the node value at the kth element from last.
//
//Sample Input
//1 2 3 4 5 6 -1
//3
//Sample Output
//4
//Explanation
//The linked list is 1 2 3 4 5 6. -1 is not included in the list. So the third element from the last is 4

class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void KthNode(Node* head, int n) {
    if (head == NULL || n <= 0) return;

    Node* slow = head, *fast = head;

    for (int i = 0; i < n; i++) {
        if (fast == NULL) return;
        fast = fast->next;
    }

    if (fast == NULL) {
        cout << n << endl;
        return;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    cout << slow->next->data << endl;
}
int main() {
    Node* head = NULL;
    int n;
    while(cin >> n && n != -1){
        insertAtEnd(head, n);
    }
    int k; cin >> k;
    KthNode(head, k);
    return 0;
}