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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        std::stack<TreeNode*> st;
        st.push(root);
        std::vector<int> res;

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            res.push_back(curr->val);
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr-> left);
        }

        return res;
    }
};
/*
O(n) time complexity and O(n) space complexity for the stack.
*/
int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    Solution sol;
    vector<int> result = sol.preorderTraversal(root);
    
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