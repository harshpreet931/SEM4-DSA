#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

// Definition of the tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructors
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int n) : data(n), left(nullptr), right(nullptr) {}
};

// Function to build the binary tree using level order traversal
TreeNode* levelOrderInput() {
    int rootVal;
    cin >> rootVal;
    TreeNode* root = new TreeNode(rootVal);
    queue<TreeNode*> qu;
    qu.push(root);

    while (!qu.empty()) {
        TreeNode* current = qu.front();
        qu.pop();
        int leftVal, rightVal;
        cin >> leftVal >> rightVal;
        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            qu.push(current->left);
        }
        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            qu.push(current->right);
        }
    }
    return root;
}

// Recursive function for vertical traversal of the tree
void verticalTraversal(TreeNode* root, int depth, map<int, vector<int>>& verticalMap) {
    if (!root) return;
    verticalMap[depth].push_back(root->data);
    verticalTraversal(root->left, depth - 1, verticalMap);
    verticalTraversal(root->right, depth + 1, verticalMap);
}

// Function to print vertical traversal of the tree
void vertical(TreeNode* root) {
    if (!root) return;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    map<int, vector<int>> verticalMap;
    verticalTraversal(root, 0, verticalMap);

    for (const auto& pair : verticalMap) {
        for (int val : pair.second) {
            cout << val << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    TreeNode* root = levelOrderInput();
    vertical(root);
    return 0;
}

