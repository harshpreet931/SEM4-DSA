//Given a linked list of length N and an integer K , append the last K elements of a linked list to the front. Note that K can be greater than N.
//
//Input Format
//First line contains a single integer N denoting the size of the linked list.
//Second line contains N space separated integers denoting the elements of the linked list.
//Third line contains a single integer K denoting the number of elements that are to be appended.
//
//Constraints
//1 <= N <= 10^4
//1 <= K <= 10^4
//
//Output Format
//Display all the elements in the modified linked list.
//
//Sample Input
//7
//1 2 2 1 8 5 6
//3
//Sample Output
//8 5 6 1 2 2 1
//Explanation
//Initially the linked list is
//1→ 2→ 3 → 4 → 5 → 6→ null
//and k = 2. After appending the last two elements to the front , the new linked list looks like
//5→ 6→ 1→ 2→ 3 → 4 → null

#include<iostream>
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

void insertAtEnd(Node * &head, int data){
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
int main() {
    Node * head = NULL;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        insertAtEnd(head,val);
    }
    int k; cin >> k;
    if(!head) return 0;

    Node * temp = head;
    while(temp->next) temp = temp->next;
    temp->next = head;
    k %= n;
    for(int i=0;i<n-k;i++) temp = temp->next;
    head = temp->next;
    temp->next = NULL;

    while(head){
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}