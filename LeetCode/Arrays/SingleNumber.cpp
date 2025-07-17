#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int x: nums){
            res ^= x;
        }
        return res;
    }
};
/*
O(n) time complexity and O(1) space complexity.
Learned about the XOR operation to solve this problem.
*/
int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single Number: " << sol.singleNumber(nums) << endl; // Output: 4
    return 0;
}