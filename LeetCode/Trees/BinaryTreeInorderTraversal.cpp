#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> st;
        std::vector<int> res;
        TreeNode* t = root;
        while(t || !st.empty()){
            if(t){
                st.push(t);
                t = t->left;
            }
            else{
                if(!st.empty()) t = st.top();
                st.pop();
                res.push_back(t->val);
                t = t->right;
            }
        }
        return res;
    }
};
/*
Inorder traversal of a binary tree using iterative approach with stack.
*/
int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution sol;
    vector<int> result = sol.inorderTraversal(root);
    
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}