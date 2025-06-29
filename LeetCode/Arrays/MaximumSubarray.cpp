#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int maxSum = sum;

        for(int i = 1; i < n; i++){
            sum = max(sum + nums[i], nums[i]);// max function from algorithm header!
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
/*
Learnt about Kadane's algorithm. At each index, we decide whether to add the current number to the existing subarray,
or start a new subarray with the current number. 
This is done by comparing the sum of the current subarray plus the current number with just the current number itself. 
The maximum of these two values is stored as the current subarray sum.
O(n) time complexity and O(1) space complexity.
From now on, I will add time and space complexity comments to my code snippets.
*/
int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4}; // Example input
    int result = sol.maxSubArray(nums);
    cout << "The maximum subarray sum is: " << result << endl;
    return 0;
}