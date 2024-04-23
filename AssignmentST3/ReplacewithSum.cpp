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

TreeNode* insert(TreeNode* root, int val){
    if(root == NULL) return new TreeNode(val);

    if(val < root->val){
        root->left = insert(root->left, val);
    }
    if(val > root->val){
        root->right = insert(root->right, val);
    }
    return root;
}

void replaceSum(TreeNode*& root, int& sum) {
    if (root == NULL) return;
    replaceSum(root->right, sum);
    int temp = root->val;
    root->val = sum;
    sum += temp;
    replaceSum(root->left, sum);
}


string toString(TreeNode* root){
    if(root == NULL) return "";

    string retVal = "";
    if(root->left != NULL){
        retVal+=to_string(root->left->val) + " => ";
    }
    else{
        retVal+= "END => ";
    }

    retVal +=  to_string(root->val);

    if(root->right != NULL){
        retVal+=" <= " + to_string(root->right->val);
    }
    else{
        retVal+=" <= END";
    }

    retVal += "\n";

    retVal += toString(root->left);
    retVal += toString(root->right);
    return retVal;
}

int main() {
    int n; cin >> n;
    TreeNode* root = NULL;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        root = insert(root, val);
    }
    int sum = 0;
    replaceSum(root,sum);
    string res = toString(root);
    cout << res;
    return 0;
}