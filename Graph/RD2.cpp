//
// Created by HARSHPREET SINGH on 6/04/2024.
//
#include <stdio.h>
//The question is: Write a C program to print the day of the week for leftmost digit of a number. A number can have only valid digits from 1 to 7 if the any one of the digit is other than 1 to 7 i.e. 0, 8 or 9 the display a message "Invalid number".


int main() {
    int num;
    scanf("%d", &num);
    int left = num;
    while (left >= 10) {
        left /= 10;
    }
    switch (left) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid number\n");
            break;
    }

    return 0;
}