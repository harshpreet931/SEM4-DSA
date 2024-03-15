//Given three linked lists, say a, b and c, find one node from each list such that the sum of the values of the nodes is equal to a given number say, Target. As any number of answers can be possible return the first one you get while traversing.
//
//Input Format
//The First Line contains 3 Integers n, m and k as the Size of the Three LinedLists. Next 3 Lines contains n, m and k integers Respectively as the elements of Linked Lists. Next Line contains the an Integer as Target.
//
//Constraints
//The Size of the Lists can be different.
//
//Output Format
//Display the 3 elements from each of the Lists whose sum is equals to the target separated by space.
//
//Sample Input
//3 3 3
//12 6 29
//23 5 8
//90 20 59
//101
//Sample Output
//6 5 90
//Explanation
//In the Given Sample Input, 6, 5 and 90 from lists 1, 2 and 3 respectively add to give 101.

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void findNodes(Node* head1, Node* head2, Node* head3, int target) {
    Node* ptr1 = head1;
    while (ptr1) {
        Node* ptr2 = head2;
        while (ptr2) {
            Node* ptr3 = head3;
            while (ptr3) {
                int sum = ptr1->data + ptr2->data + ptr3->data;
                if (sum == target) {
                    cout << ptr1->data << " " << ptr2->data << " " << ptr3->data << endl;
                    return;
                }
                ptr3 = ptr3->next;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main() {
    int n, m, o;
    cin >> n >> m >> o;
    Node* head1 = nullptr, *head2 = nullptr, *head3 = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtEnd(head1, val);
    }
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        insertAtEnd(head2, val);
    }
    for (int i = 0; i < o; i++) {
        int val;
        cin >> val;
        insertAtEnd(head3, val);
    }
    int target;
    cin >> target;
    findNodes(head1, head2, head3, target);
    return 0;
}