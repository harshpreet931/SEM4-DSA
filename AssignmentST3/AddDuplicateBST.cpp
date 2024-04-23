#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val){
    if(root == NULL) return new TreeNode(val);

    if(val < root->val) root->left = insert(root->left, val);
    if(val > root->val) root->right = insert(root->right, val);
    return root;
}

string toString(TreeNode* root){
    if(root == NULL) return "";
    string res = "";
    if(root->left != NULL){
        res += to_string(root->left->val) + " => ";
    }
    else{
        res += "END => ";
    }
    res += to_string(root->val);
    if(root->right != NULL){
        res += " <= " + to_string(root->right->val);
    }
    else{
        res += " <= END";
    }
    res += "\n";
    res += toString(root->left);
    res += toString(root->right);
    return res;
}

void dupTree(TreeNode* root){
    TreeNode* oldleft;
    if(root == NULL) return;
    dupTree(root->left);
    dupTree(root->right);

    oldleft = root->left;
    root->left = new TreeNode(root->val);
    root->left->left = oldleft;
}

int main() {
    int n; cin >> n;
    TreeNode* root = NULL;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        root = insert(root, val);
    }

    dupTree(root);
    string ans = toString(root);
    cout << ans;
    return 0;
}