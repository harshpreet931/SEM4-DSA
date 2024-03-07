//
// Created by HARSHPREET SINGH on 9/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

void subsets(string str, string temp, int idx){
    if(idx == str.size()){
        cout << temp << endl;
        return;
    }

    subsets(str,temp+str[idx],idx+1);
    subsets(str,temp,idx+1);
}

void sirQuestion(string str, int k, string temp){
    if(k == temp.size()){
        cout << temp << endl;
        return;
    }

    for(int i=0;i<str.size();i++){
        sirQuestion(str,k,temp+str[i]);
    }
}

int main() {
    string str = "abc";
    string temp;
    subsets(str,temp,0);

    sirQuestion("abc",2,"");
    return 0;
}