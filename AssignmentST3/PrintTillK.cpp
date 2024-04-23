#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->data) {
        root->left = createTree(root->left, val);
    } else {
        root->right = createTree(root->right, val);
    }
    return root;
}

void preOrderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void setParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!root) return;
    if (root->left) parent[root->left] = root;
    if (root->right) parent[root->right] = root;
    setParents(root->left, parent);
    setParents(root->right, parent);
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root || root->data == val) return root;
    TreeNode* left = findNode(root->left, val);
    TreeNode* right = findNode(root->right, val);
    return left ? left : right;
}

int main() {
    int n;
    cin >> n;
    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = createTree(root, val);
    }
    int num, k;
    cin >> num >> k;
    unordered_map<TreeNode*, TreeNode*> parent;
    setParents(root, parent);
    parent[root] = nullptr;
    TreeNode* start = findNode(root, num);
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    visited[start] = true;
    q.push(start);
    int level = 0;
    vector<int> result;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* current = q.front();
            q.pop();
            if (level == k) {
                result.push_back(current->data);
            }
            if (current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent[current] && !visited[parent[current]]) {
                q.push(parent[current]);
                visited[parent[current]] = true;
            }
        }
        level++;
        if (level > k) break;
    }

    sort(result.begin(), result.end());

    for (int i : result) {
        cout << i << endl;
    }

    return 0;
}
