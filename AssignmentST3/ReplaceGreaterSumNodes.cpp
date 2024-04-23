#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode*left, *right;

    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};

TreeNode* constructBST(vector<int>& arr, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = constructBST(arr,start,mid-1);
    root->right = constructBST(arr,mid+1,end);
    return root;
}

void replace(TreeNode* root, int& sum){
    if(root == NULL) return;
    replace(root->right, sum);
    root->val += sum;
    sum = root->val;
    replace(root->left, sum);
}

void print(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main() {
    int n; cin >> n;
    vector<int> inorder(n);
    for(int i=0;i<n;i++) cin >> inorder[i];

    TreeNode* root = constructBST(inorder, 0, inorder.size()-1);
    int sum = 0;
    replace(root,sum);
    print(root);
    return 0;
}