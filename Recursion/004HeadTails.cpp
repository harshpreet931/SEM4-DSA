//
// Created by HARSHPREET SINGH on 6/02/2024.
//


#include <bits/stdc++.h>
using namespace std;

vector<string> coins;
void coin(int n, string temp){
     if(n==0) {
         coins.push_back(temp);
         return;
     }
     coin(n-1,temp+'H');
     coin(n-1, temp+'T');
}

int main() {
    coin(3,"");
    for(auto i : coins){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}