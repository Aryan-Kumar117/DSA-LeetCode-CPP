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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path = "";
        helper(root, path, res);
        return res;
    }
    void helper(TreeNode* node, string path, vector<string>& res){
        if(!node) return;
        path += to_string(node->val);
        if(node->left == NULL && node->right == NULL) res.push_back(path);
        else{
            helper(node->left, path+"->", res);
            helper(node->right, path+"->", res);
        }       
    }
};
/*
O(n^2) worst case time complexity and O(n^2) space complexity.. sheesh.. kinda common with binary trees though.
This is because of the string concatenation in the path variable.
*/
int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));
    Solution sol;
    vector<string> paths = sol.binaryTreePaths(root);
    
    for(const string& path : paths) {
        cout << path << endl;
    }
    
    // Clean up memory (not shown here)
    return 0;
}