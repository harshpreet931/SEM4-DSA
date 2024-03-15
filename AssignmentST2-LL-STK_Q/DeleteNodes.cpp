//Given a singly linked list delete all nodes which are having a greater value among any of the nodes residing on the right side.
//
//Input Format
//First line contains N, the number of nodes in the linked list.
//Next line contains the N nodes data .
//
//Constraints
//0<N<10^9
//
//Output Format
//Print the linked list after deleting the nodes which are having a greater value on right side.
//
//Sample Input
//8
//12 15 10 11 5 6 2 3
//Sample Output
//15 11 6 3
//Explanation
//In the given case 12 is having right node greater than itself i.e. 12<15 so delete it.
//Similarly, 10<11, 5<6 and 2<3 so delete 10, 5 and 2 as well.
//Thus, linked list becomes 15->11->6->3.

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(Node * &head, int data){
    if(head == NULL) {
        head = new Node(data);
        return;
    }
    Node * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new Node(data);
}

bool toDel(Node * head){
    Node * temp = head->next;
    int val = head->data;
    while(temp){
        if(temp->data > val) return true;
        temp = temp->next;
    }
    return false;
}

int main () {
    int n; cin >> n;
    Node * head = NULL;
    for(int i = 0;i<n;i++){
        int val; cin >> val;
        insertAtEnd(head,val);
    }
    Node * temp = head, *prev = NULL;
    while(temp){
        bool todel = toDel(temp);
        if(todel){
            if(prev == NULL){
                head = temp->next;
            }
            else{
                prev->next = temp->next;
            }
        }
        else{
            prev = temp;
        }
        temp = temp->next;
    }
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}