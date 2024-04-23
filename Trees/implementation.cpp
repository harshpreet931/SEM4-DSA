//
// Created by HARSHPREET SINGH on 18/03/2024.
//
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    TreeNode * left, * right;
    int val;
    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

void preorderTraversal(TreeNode * root){
    if(root == NULL) return;
    cout << root->val << " ";
    if(root->left){
        preorderTraversal(root->left);
    }
    if(root->right){
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode * root){
    if(root == NULL) return;
    if(root->left){
        inorderTraversal(root->left);
    }
    cout << root->val << " ";
    if(root->right){
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode * root){
    if(root == NULL) return;
    if(root->left){
        postorderTraversal(root->left);
    }
    if(root->right){
        postorderTraversal(root->right);
    }
    cout << root->val << " ";

}

void BFS(TreeNode * root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode * temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            cout << temp->val << " ";
        }
    }
}

int main() {
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    preorderTraversal(root);
    cout << endl;
    inorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    cout << endl;
    BFS(root);
    cout << endl;
    return 0;
}