//
// Created by HARSHPREET SINGH on 8/04/2024.
//
#include <bits/stdc++.h>
using namespace std;

//class Solution {
//    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) {
//        boolean vis[] = new boolean[V];
//        for(int i=0;i<V;i++)
//            if(!vis[i] && dfs(i,-1,vis,adj)) return true;
//        return false;
//    }
//       private boolean dfs(int current,int parent,boolean vis[],ArrayList<ArrayList<Integer>> adj){
//        vis[current]=true;
//        for(int child : adj.get(current))
//            if(!vis[child]){
//                if(dfs(child,current,vis,adj)) return true;
//            }
//            else if(child != parent) return true;
//        return false;
//    }

bool isCycle(int v, vector<int> adj[]){
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++)
        if(!vis[i] && dfs(i,-1,vis,adj)) return true;
    return false;
}

bool dfs(int curr, int parent, vector<bool>& vis, vector<int> adj[]){
    vis[curr] = true;
    for(int child : adj[curr]){
        if(!vis[child]){
            if(dfs(child,curr,vis,adj)) return true;
        }
        else if(child != parent) return true;
    }
    return false;
}

int main() {

    return 0;
}