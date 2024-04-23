#include<bits/stdc++.h>
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
    int val;
    string left;
    cin >> val >> left;

    TreeNode* root = new TreeNode(val);
    if(left == "true"){
        root->left = buildTree();
    }

    string right;
    cin >> right;
    if(right == "true"){
        root->right = buildTree();
    }
    return root;
}

TreeNode* lca(TreeNode* root, int p, int q){
    if(root == NULL) return NULL;
    if(root->val == p || root->val == q) return root;

    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    if(left != NULL && right != NULL) return root;
    if(left != NULL) return left;
    return right;
}

int main() {
    TreeNode* root = buildTree();
    int p, q; cin >> p >> q;
    TreeNode* res = lca(root, p, q);
    cout << res->val;
    return 0;
}