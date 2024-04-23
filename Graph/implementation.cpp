//
// Created by HARSHPREET SINGH on 5/04/2024.
//
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], unordered_map<int,bool>& vis, int i){
    vis[i] = true;
    for(int x : graph[i]){
        if(!vis[x]){
            cout << "Parent:" << i << " Child:" << x << endl;
            dfs(graph,vis,x);
        }
    }

}

void bfs(vector<int> graph[], unordered_map<int,bool>& vis, int i){
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int j : graph[x]){
            if(!vis[j]){
                q.push(j);
                vis[j] = true;
                cout << "Parent:" << x << " Child:" << j << endl;
            }
        }
    }
}

int main() {
    int v,e; cin >> v >> e;
    unordered_map<int, bool> vis;
    unordered_map<int, bool> vis2;
    vector<int> graph[v];
    for(int i=0;i<e;i++){
        int v1,v2; cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(graph,vis,0);

    for(auto i : vis){
        cout << i.first << " " << i.second << endl;
    }

    for(int i=0;i<v;i++){
        if(!vis[i])
            dfs(graph, vis, i);
    }

    bfs(graph, vis2, 0);
    return 0;
}