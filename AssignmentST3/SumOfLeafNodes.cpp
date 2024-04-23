//
// Created by HARSHPREET SINGH on 11/04/2024.
//
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree(){
    int val;
    string hasLeft;
    cin >> val >> hasLeft;
    TreeNode *root = new TreeNode(val);
    if(hasLeft == "true") root->left = buildTree();

    string hasRight;
    cin >> hasRight;
    if(hasRight == "true") root->right = buildTree();
    return root;
}

int sumOfNodes(TreeNode* root){
    if(root == NULL) return 0;
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main(){
    TreeNode* root = buildTree();
    cout << sumOfNodes(root) << endl;
    return 0;
}