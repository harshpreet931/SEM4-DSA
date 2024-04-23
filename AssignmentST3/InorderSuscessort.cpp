#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

TreeNode* buildBST(vector<int> arr) {
    if (arr.size() == 0) return NULL;
    TreeNode* root = new TreeNode(arr[0]);
    for (int i = 1; i < (int)arr.size(); i++) {
        TreeNode* curr = root;
        while (true) {
            if (arr[i] < curr->val) {
                if (curr->left) curr = curr->left;
                else {
                    TreeNode* newNode = new TreeNode(arr[i]);
                    newNode->parent = curr;
                    curr->left = newNode;
                    break;
                }
            } else {
                if (curr->right) curr = curr->right;
                else {
                    TreeNode* newNode = new TreeNode(arr[i]);
                    newNode->parent = curr;
                    curr->right = newNode;
                    break;
                }
            }
        }
    }
    return root;
}

TreeNode* findSuc(TreeNode* node) {
    if (node->right) {
        node = node->right;
        while (node->left) node = node->left;
        return node;
    } else {
        while (node->parent && node == node->parent->right) {
            node = node->parent;
        }
        return node->parent;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;

    TreeNode* root = buildBST(arr);

    TreeNode* node = root;
    while (node && node->val != k) {
        if (k < node->val) node = node->left;
        else node = node->right;
    }

    TreeNode* succ = findSuc(node);
    if (succ) cout << succ->val << endl;
    else cout << "null" << endl;

    return 0;
}