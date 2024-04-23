//
// Created by HARSHPREET SINGH on 12/04/2024.
//
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree(){
    int val; cin >> val;
    auto* root = new TreeNode(val);
    queue<TreeNode*> q{{root}};

    while(!q.empty()){
        int n = q.size();
        while(n--){
            auto front = q.front(); q.pop();
            int left, right;
            cin >> left >> right;
            if(left!=-1){
                front->left = new TreeNode(left);
                q.push(front->left);
            }
            if(right!=-1){
                front->right = new TreeNode(right);
                q.push(front->right);
            }
        }
    }
    return root;
}

void allLeaves(TreeNode* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        cout << root->val << " ";
    }
    allLeaves(root->left);
    allLeaves(root->right);
}

int main() {
    TreeNode* root = buildTree();
    allLeaves(root);
    return 0;
}