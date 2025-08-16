#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if(!root) return res;

        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            std::vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
/*
O(n) time and O(n) space complexity.
Level order traversal of a binary tree using a queue.
*/
int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);
    
    for(const auto& level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}