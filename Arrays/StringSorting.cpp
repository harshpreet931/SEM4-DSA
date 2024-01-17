//
// Created by HARSHPREET SINGH on 17/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

string sortin(string s){
    int freqB[26] = {0};
    int freqb[26] = {0};

    for(char c : s){
        if(c >= 'A' && c <= 'Z'){
            freqB[c-'A']++;
        }
        else{
            freqb[c-'a']++;
        }
    }
    string res = "";
    for(int i=0;i<26;i++){
        while(freqB[i]--){
            res+= (char)(i+'A');
        }
        while(freqb[i]--){
            res+= (char)(i+'a');
        }
    }
    return res;
}

int main() {
//    Sorting a string
      string s; cin >> s;
      // o(n) time complexity
      int arr[26] = {0};
      for(char c : s){
          arr[c-'a']++;
      }
      string res = "";
      for(int i=0;i<26;i++){
          while(arr[i]--){
              res += (char)(i+'a');
          }
        }
      cout << res << endl;

      // now we need to solve the same using character array
        char c[100];
        cin >> c;
        int arr2[26] = {0};
        for(int i=0;c[i]!='\0';i++){
            arr2[c[i]-'a']++;
        }
        char res2[100] = {0};
        int idx = 0;
        for(int i=0;i<26;i++){
            while(arr2[i]--){
                res2[idx++] += (char)(i+'a');
            }
        }
        res2[idx] = '\0';
        cout << res2 << endl;

        string str; cin >> str;
        cout << sortin(str);
    return 0;
}