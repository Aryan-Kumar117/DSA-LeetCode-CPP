#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxSum = 0;
        std::unordered_set<int> set;
        int maxVal = *std::max_element(nums.begin(), nums.end());
        if(maxVal < 0) return maxVal;
        for(int x: nums){
            if(x <= 0) continue;
            if(!set.count(x)) maxSum += x;
            set.insert(x);
        }
        return maxSum;
    }
};

/*
O(n) time complexity and O(n) space complexity.
LeetCode's daily problem for 25-07-2025.
*/

int main() {
    Solution sol;
    vector<int> nums = {4, 2, 1, 6, 3, 5}; // Example input
    int result = sol.maxSum(nums);
    cout << "The maximum unique subarray sum after deletion is: " << result << endl;
    return 0;
}