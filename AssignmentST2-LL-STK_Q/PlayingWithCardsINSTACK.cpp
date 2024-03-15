//You are at a casino. There are N stacked cards on pile A0. Each card has a number written on it. Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and check whether the number written on the card is divisible by the ith prime number. If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .
//
//Input Format
//First line contains N and Q. The next line contains N space separated integers representing the initial pile of cards i.e., A0. The leftmost value represents the bottom plate of the pile.
//
//Constraints
//N < 10^5
//Q < 10^5
//|Ai| < 10^9
//
//Output Format
//Output N lines, each line containing the number written on the card.
//
//Sample Input
//5 1
//3 4 7 6 5
//Sample Output
//4
//6
//3
//7
//5
//Explanation
//Initially:
//
//A0 = [3, 4, 7, 6, 5]<-TOP
//
//After 1st iteration:
//
//A0 = []<-TOP
//
//A1 = [5, 7, 3]<-TOP
//
//B1 = [6, 4]<-TOP
//
//Now first print B1 from top to bottom then A1 from top to bottom.

#include<bits/stdc++.h>
using namespace std;

void primes(vector<int>& res){
    vector<bool> prime(100001);
    prime[0] = true;
    prime[1] = true;
    for(int i=2;i*i<100000;i++){
        if(prime[i] == false){
            res.push_back(i);
            for(int a=2;a*i<=100000;a++){
                prime[a*i] = true;
            }
        }
    }
    for(int i=2;i<=100000;i++){
        if(!prime[i]) res.push_back(i);
    }
}

void helper(stack<int>&cards, int q){
    stack<int> a , b;
    vector<int> res;
    primes(res);
    for(int i=1;i<=q;i++){
        int prime = res[i-1];
        while(!cards.empty()){
            int temp = cards.top(); cards.pop();
            if(temp%prime==0) b.push(temp);
            else a.push(temp);
        }
        while(!b.empty()){
            cout << b.top() << endl;
            b.pop();
        }
        cards = a;
        while(!a.empty()) a.pop();
    }
    while(!cards.empty()){
        cout << cards.top() << endl;
        cards.pop();
    }
}

int main(){
    int n, q; cin >> n >> q; stack<int> cards;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        cards.push(val);
    }
    helper(cards,q);
}


