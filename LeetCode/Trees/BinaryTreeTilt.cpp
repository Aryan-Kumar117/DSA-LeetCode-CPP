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
    int findTilt(TreeNode* root) {
        TreeNode* t = root;
        int tiltSum = 0;
        postorder(root, tiltSum);
        return tiltSum;
    }

    int postorder(TreeNode* node, int& tiltSum) {
        if (!node) return 0;
        int left = postorder(node->left, tiltSum);
        int right = postorder(node->right, tiltSum);
        tiltSum += std::abs(left - right);
        return left + right + node->val;
    }
};
/*
O(n) time complexity and O(h) space complexity, where h is the height of the tree.
Implemented a helper function to calculate the tilt of each node.
*/
int main() {
    Solution sol;   
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int result = sol.findTilt(root);
    cout << "The total tilt of the binary tree is: " << result << endl; 
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;    
    return 0;
}