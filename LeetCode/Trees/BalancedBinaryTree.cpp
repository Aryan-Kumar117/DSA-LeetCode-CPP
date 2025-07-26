#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        checkHeight(root, balanced);
        return balanced;
    }
    int checkHeight(TreeNode* node, bool& isBalanced){
        if(!node || !isBalanced) return false;
        int left = checkHeight(node->left, isBalanced);
        int right = checkHeight(node->right, isBalanced);
        if(std::abs(left-right) > 1) isBalanced = false;
        return 1+std::max(left, right);
    }
};
/*
O(n) time complexity and O(h) space complexity, where h is the height of the tree.
Started learning about trees. 
*/
int main() {
    Solution sol;
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    bool result = sol.isBalanced(root);
    cout << "Is the binary tree balanced? " << (result ? "Yes" : "No") << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}