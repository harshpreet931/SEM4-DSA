//
// Created by HARSHPREET SINGH on 3/02/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
//    Given 3 sides of the triangle in the vector find if the triangle is valid or not
//      then tell the type of triangle
    vector<int> sides = {3, 4, 5};
    sort(sides.begin(), sides.end());
    if (sides[0] + sides[1] > sides[2]) {
        if (sides[0] == sides[1] && sides[1] == sides[2]) {
            cout << "Equilateral Triangle";
        } else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2]) {
            cout << "Isosceles Triangle";
        } else {
            cout << "Scalene Triangle";
        }
    } else {
        cout << "Invalid Triangle";
    }
    return 0;
}