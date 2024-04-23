//
// Created by HARSHPREET SINGH on 20/03/2024.
//
#include <stdio.h>

void reverse(int array[], int n){
    int start = 0, end = n-1;
    while(start < end){
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }

}

int main() {
    int n; scanf("%d", &n);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d", &array[i]);
    }

    // 2 pointers


    for(int i=0;i<n;i++){
        printf("%d ", array[i]);
    }

    return 0;
}