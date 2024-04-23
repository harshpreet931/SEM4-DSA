#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left, *right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};

TreeNode* buildTree(){
    int val; cin >> val;
    string left; cin >> left;

    TreeNode* root = new TreeNode(val);
    if(left == "true"){
        root->left = buildTree();
    }
    string right; cin >> right;
    if(right == "true"){
        root->right = buildTree();
    }
    return root;
}

int depth(TreeNode* root){
    if(root == NULL) return 0;
    return max(depth(root->left), depth(root->right))+1;
}

bool isBalanced(TreeNode* root){
    if(root == NULL) return true;
    int left = depth(root->left);
    int right = depth(root->right);

    return abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    TreeNode* root = buildTree();
    if(isBalanced(root)) cout << "true";
    else cout << "false";
    return 0;
}