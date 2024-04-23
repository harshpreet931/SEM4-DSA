//
// Created by HARSHPREET SINGH on 5/04/2024.
//
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, unordered_map<int,bool>& vis, int i){
    vis[i] = true;
    for(int x : graph[i]){
        if(!vis[x]){
            dfs(graph,vis,x);
        }
    }
}

int findCircleNum(vector<vector<int>>& graph) {
    int n = graph.size();
    unordered_map<int,bool> vis;
    int count = 0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(graph,vis,i);
        }
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                provinces++;
            }
        }

        return provinces;
    }

private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        visited[node] = true;

        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(isConnected, visited, neighbor);
            }
        }
    }
};

int main() {
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    cout << findCircleNum(graph) << endl;
    return 0;
}