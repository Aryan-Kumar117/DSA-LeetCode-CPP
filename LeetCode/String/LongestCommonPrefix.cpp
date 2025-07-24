#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n = strs.size();
        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i];
            for(int j = 1; j < n; j++){
                if(i >= strs[j].size() || strs[j][i] != c){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
/*
O(m * n) time complexity and O(1) space complexity.
Quite clever if I do say so myself. Learnt about the substring method.
*/
int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"}; // Example input
    string result = sol.longestCommonPrefix(strs);
    cout << "The longest common prefix is: " << result << endl;
    return 0;
}