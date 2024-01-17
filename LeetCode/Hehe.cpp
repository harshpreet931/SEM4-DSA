//
// Created by HARSHPREET SINGH on 13/01/2024.
//


#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#include <stdio.h>

int powo(int base,int exponent){
    if (exponent ==0){
        return 1;
    }
    else
        return base * powo(base,exponent-1);
}
int main(){
    int a;
    int b;
    scanf("%d",&a);
    scanf("%d",&b);
    int sum = 0;
    int power = 1;
    for(int i = 1;i<=b;i++){

        if(i%2 !=0){
            sum += powo(a,power);
            power+=2;
        }
        else{
            sum -= powo(a,power);
            power+=2;
        }
    }
    printf("%d",sum);
}