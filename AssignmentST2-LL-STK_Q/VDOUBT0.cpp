//
// Created by HARSHPREET SINGH on 12/03/2024.
//

#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* back;

public:
    node(int data1, node* next1 = nullptr, node* back1 = nullptr)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};

void print(node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
node* deleteTail(node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    node* tail = head;
    while (tail->next->next != nullptr)
    {
        tail = tail->next;
    }
    node* oldTail = tail->next;
    tail->next = nullptr;
    oldTail->back = nullptr;

    delete oldTail;
    return head;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    node* head = nullptr;
    for (int i = n - 1; i >= 0; i--)
    {
        head = new node(arr[i], head,nullptr);
    }

    head = deleteTail(head);
    print(head);

    return 0;
}