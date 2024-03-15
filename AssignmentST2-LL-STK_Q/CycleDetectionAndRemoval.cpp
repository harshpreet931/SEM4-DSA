//head - Head pointer of the Linked List
//Return a boolean value indicating the presence of cycle
//If the cycle is present, modify the linked list to remove the cycle as well
//complete this Method Given Below
//
//
//bool floydCycleRemoval(Node head)
//{
//    /* Code here */
//}
//
//
//You do not need to refer or modify any code below this.
//Only modify the above function definition.
//Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
//You do not even need to read or know about the code below.
//Given the head pointer to a linked list , complete the function to check whether there is a cycle present in the linked list. If so , modify the linked list to remove the cycle.
//
//Note : You are only supposed to update the designated function. Do not change/alter the remaining code or your program may not work.
//
//Input Format
//Your function accepts one single argument that is the head pointer to the linked list.
//
//Constraints
//Your function should run in O(n) time.
//
//Output Format
//Your function should return a boolean value - True/False , indicating the presence of the cycle.
//True if cycle is present, False otherwise.
//If true , remove the cycle as well.
//
//Sample Input
//
//1 2 3 4 5 2
//Consider a linked list like
//1 -> 2 -> 3
//     ^    |
//     |    v
//     5<-  4
//
//
//
//
//Sample Output
//Your function should return True for the above linked list and remove the cycle as well <br>
//The new linked list should look like - 1->2->3->4->5-> NULL
//Explanation
//Clearly there is a cycle present. We return true to indicate it and remove it.

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

bool floydCycleRemoval(Node *&head)
{
    /* Code here */
    if(head == NULL || head->next == NULL) return false;
    Node * slow = head, *fast = head;
    slow = slow->next, fast = fast->next->next;
    bool cyc = false;
    while(fast && fast->next){
        if(slow == fast){
            cyc = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(!cyc) return false;
    slow = head;
    if(slow == fast){
        while(fast->next != slow) fast = fast->next;
    }
    else{
        while(slow->next != fast->next){
            slow = slow->next, fast = fast->next;
        }
    }
    fast->next = NULL;
    return true;
}
