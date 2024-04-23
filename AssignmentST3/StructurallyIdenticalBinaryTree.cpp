#include<iostream>
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
    TreeNode* root = new TreeNode(val);

    string left;
    cin >> left;

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

bool structId(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;

    return structId(root1->left, root2->left) && structId(root1->right,root2->right);
}

int main() {
    TreeNode* root1 = buildTree();
    TreeNode* root2 = buildTree();
    bool ans = structId(root1, root2);
    if(ans) cout << "true";
    else cout << "false";
    return 0;
}