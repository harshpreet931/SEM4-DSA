//
// Created by HARSHPREET SINGH on 3/02/2024.
//

//100194. Find the Number of Ways to Place People I
//User Accepted:0
//User Tried:8
//Total Accepted:0
//Total Submissions:8
//Difficulty:Medium
//You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//
//We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)
//
//You have to place n people, including Chisato and Takina, at these points such that there is exactly one person at every point. Chisato wants to be alone with Takina, so Chisato will build a rectangular fence with Chisato's position as the upper left corner and Takina's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Chisato and Takina is either inside the fence or on the fence, Chisato will be sad.
//
//Return the number of pairs of points where you can place Chisato and Takina, such that Chisato does not become sad on building the fence.
//
//Note that Chisato can only build a fence with Chisato's position as the upper left corner, and Takina's position as the lower right corner. For example, Chisato cannot build either of the fences in the picture below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:
//
//With Chisato at (3, 3) and Takina at (1, 1), Chisato's position is not the upper left corner and Takina's position is not the lower right corner of the fence.
//With Chisato at (1, 3) and Takina at (1, 1), Takina's position is not the lower right corner of the fence.
//
//
//
//Example 1:
//
//
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 0
//Explanation: There is no way to place Chisato and Takina such that Chisato can build a fence with Chisato's position as the upper left corner and Takina's position as the lower right corner. Hence we return 0.
//Example 2:
//
//
//Input: points = [[6,2],[4,4],[2,6]]
//Output: 2
//Explanation: There are two ways to place Chisato and Takina such that Chisato will not be sad:
//- Place Chisato at (4, 4) and Takina at (6, 2).
//- Place Chisato at (2, 6) and Takina at (4, 4).
//You cannot place Chisato at (2, 6) and Takina at (6, 2) because the person at (4, 4) will be inside the fence.
//Example 3:
//
//
//Input: points = [[3,1],[1,3],[1,1]]
//Output: 2
//Explanation: There are two ways to place Chisato and Takina such that Chisato will not be sad:
//- Place Chisato at (1, 1) and Takina at (3, 1).
//- Place Chisato at (1, 3) and Takina at (1, 1).
//You cannot place Chisato at (1, 3) and Takina at (3, 1) because the person at (1, 1) will be on the fence.
//Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.
//
//
//Constraints:
//
//2 <= n <= 50
//points[i].length == 2
//0 <= points[i][0], points[i][1] <= 50
//All points[i] are distinct.


#include <bits/stdc++.h>
using namespace std;

int numberOfPairs(vector<vector<int>>& points) {
    int count = 0;
    for(int i=0;i<points.size();i++){
        for(int j=0;j<points.size();j++){
            if(i==j) continue;

            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[j][0];
            int y2 = points[j][1];

            if(x1 <= x2 && y1 >= y2){
                bool check = true;
                for(int k=0;k<points.size();k++){
                    if(k==i || k==j) continue;
                    int checkx = points[k][0];
                    int checky = points[k][1];
                    if((checkx > x1 && checkx < x2) && (checky < y1 && checky > y2)){
                        check = false;
                        break;
                    }
                    if((checkx == x1 || checkx == x2) && (checky <= y1 && checky >= y2)){
                        check = false;
                        break;
                    }
                    if((checky == y1 || checky == y2) && (checkx >= x1 && checkx <= x2)){
                        check = false;
                        break;
                    }

                }
                if(check) count++;

            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    cout<<numberOfPairs(points);
    vector<vector<int>> points1 = {{6,2},{4,4},{2,6}};
    cout<<numberOfPairs(points1);
    vector<vector<int>> points2 = {{3,1},{1,3},{1,1}};
    cout<<numberOfPairs(points2);
    return 0;
}