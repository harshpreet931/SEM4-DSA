//
// Created by HARSHPREET SINGH on 6/04/2024.
//
//Here is the text from the two images:
//
//Image 1:
//The program should output the total amount of money held by the individuals seated at the four corners followed by amount possessed by the rest of the persons of the 2D matrix separated by comma (,).
//
//Constraints:
//
//The input array will always be a 3x3 matrix.
//The amount of money in each cell of the matrix will be a non-negative integer.
//Example:
//Consider the following 3x3 matrix representing the seating arrangement and the amount of money possessed by each individual:
//2 5 8 1 4 7 3 6 9
//
//Output:
//22, 23 // 22 is the addition of all four corner values (2,8,3,9) and 23 is the sum of rest (5,1,4,7,6)
//
//Sample Test Cases:
//Test Case 1:
//Expected Output:
//1 2 3 4 5 6 7 8 9
//
//20, 25
#include <stdio.h>
#include <stdio.h>

int main() {
    int sum = 0, sum2 = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int temp;
            scanf("%d", &temp);

            if((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 0) || (i == 2 && j == 2)) {
                sum += temp;
            } else {
                sum2 += temp;
            }
        }
    }

    printf("%d, %d\n", sum, sum2);
    return 0;
}
