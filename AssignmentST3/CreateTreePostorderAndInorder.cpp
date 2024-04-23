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

TreeNode* buildTreeHelper(vector<int>& postOrder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd){
    if(postStart > postEnd || inStart > inEnd) return NULL;
    int rootVal = postOrder[postEnd];
    int rootIdxInOrder;
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i] == rootVal){
            rootIdxInOrder = i;
            break;
        }
    }

    TreeNode* root = new TreeNode(rootVal);
    int leftSubtreeSize = rootIdxInOrder - inStart;
    int rightSubtreeSize = inEnd - rootIdxInOrder;
    root->left = buildTreeHelper(postOrder,postStart,postStart+leftSubtreeSize-1, inorder, inStart, rootIdxInOrder-1);
    root->right = buildTreeHelper(postOrder, postStart + leftSubtreeSize, postEnd-1, inorder, rootIdxInOrder+1,  inEnd);
    return root;
}

TreeNode* buildTree(vector<int> postOrder, vector<int> inorder){
    int n = postOrder.size(), m = inorder.size();
    if(n != m || n == 0) return NULL;
    return buildTreeHelper(postOrder, 0, n-1, inorder, 0, m-1);
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

int main() {
    vector<int> postOrder, inorder;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        postOrder.push_back(val);
    }
    int m; cin >> m;
    for(int i=0;i<m;i++){
        int val; cin >> val;
        inorder.push_back(val);
    }
    TreeNode* root = buildTree(postOrder, inorder);
    string ans = toString(root);
    cout << ans;
    return 0;
}