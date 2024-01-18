//
// Created by HARSHPREET SINGH on 16/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

void insertion(char*arr, int n, char key, int pos){
    for(int i=n+1;i>pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = key;
}

void deletion(char*arr,int &n, int pos){
    for(int i=pos;i<n;i++){
        arr[i] = arr[i+1];
    }
    n--;
}

int search(char*arr, int n, char key){
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main() {
    int n; cin >> n;
    char arr[n+1];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    arr[n] = '\0';
    cout << arr << endl;

    for(int i=0;i<arr[i]!='\0';i++){
        cout << arr[i];
    }
    cout << endl;

    insertion(arr,n,'X',2);
    cout << arr << endl;
    deletion(arr,n,2);
    cout << arr << endl;
    cout << search(arr,n,'X') << endl;
    return 0;
}