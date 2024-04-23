#include <iostream>
#include <queue>
#include <map>
#include <utility>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree() {
    int val; cin >> val;
    TreeNode* root = new TreeNode(val);

    queue<TreeNode*> q{{root}};
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal >> rightVal;

        if (leftVal != -1) {
            temp->left = new TreeNode(leftVal);
            q.push(temp->left);
        }
        if (rightVal != -1) {
            temp->right = new TreeNode(rightVal);
            q.push(temp->right);
        }
    }
    return root;
}

void topView(TreeNode* root) {
    if (root == NULL) return;
    queue<pair<TreeNode*, int>> q;
    map<int, int> topViewMap;

    q.push({root, 0});
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        TreeNode* curr = temp.first;
        int horD = temp.second;

        if (topViewMap.find(horD) == topViewMap.end()) {
            topViewMap[horD] = curr->val;
        }
        if (curr->left != NULL) {
            q.push({curr->left, horD - 1});
        }
        if (curr->right != NULL) {
            q.push({curr->right, horD + 1});
        }
    }

    for (auto it : topViewMap) {
        cout << it.second << " ";
    }
}

int main() {
    TreeNode* root = buildTree();
    topView(root);
    return 0;
}
