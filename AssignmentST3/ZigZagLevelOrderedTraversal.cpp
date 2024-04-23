#include <bits/stdc++.h>
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
    string left; cin >> left;

    TreeNode* root = new TreeNode(val);

    if(left == "true"){
        root->left = buildTree();
    }

    string right; cin >> right;
    if(right == "true"){
        root->right = buildTree();
    }

    return root;
}

void zigzag(TreeNode* root){
    queue<TreeNode*> q{{root}};
    int level = 0;
    while(!q.empty()){
        int n = q.size();
        vector<int> nodes;
        while(n--){
            auto temp = q.front(); q.pop();
            nodes.push_back(temp->val);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(level%2!=0){
            reverse(nodes.begin(),nodes.end());
        }
        for(int i : nodes) cout << i << " ";
        level++;
    }
}

int main(){
    TreeNode* root = buildTree();
    zigzag(root);
    return 0;
}