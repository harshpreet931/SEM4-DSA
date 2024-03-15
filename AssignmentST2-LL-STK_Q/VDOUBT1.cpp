#include <iostream>
#include <vector>

using namespace std;

class node {
public:
    int data;
    node* next;
    node* back;

public:
    node(int data1, node* next1, node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
};

void print(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* deleteHead(node* head) {
    if (head == NULL || head->next == NULL) {
        return nullptr;
    }
    node* nextnode = head->next;
    nextnode->back = nullptr;
    delete head;
    return nextnode;
}

node* deleteTail(node* head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return nullptr;
    }
    node* Tail = head;
    while (Tail->next->next != nullptr) {
        Tail = Tail->next;
    }
    node* oldTail = Tail->next;
    Tail->next = nullptr;
    oldTail->back = nullptr;
    delete oldTail;
    return head;
}

node* removeKthElement(node* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    int cnt = 0;
    node* Knode = head;
    while (Knode != nullptr) {
        cnt++;
        if (cnt == k) {
            break;
        }
        Knode = Knode->next;
    }
    node* prev = Knode->back;
    node* front = Knode->next;
    if (prev == NULL && front == NULL) {
        return NULL;
    } else if (prev == NULL) {
        return deleteHead(head);
    } else if (front == NULL) {
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    Knode->next = nullptr;
    Knode->back = nullptr;
    delete Knode;
    return head;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        head = new node(arr[i], head, nullptr);
        if (head->next != nullptr) {
            head->next->back = head;
        }
    }
    head = removeKthElement(head, k);
    print(head);
    return 0;
}