#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum = 0;
        int currSum = 0;
        std::unordered_set<int> set;
        int slow = 0;

        for(int fast = 0; fast < nums.size(); ++fast){
            while(set.count(nums[fast])){
                set.erase(nums[slow]);
                currSum -= nums[slow];
                ++slow;
            }
            set.insert(nums[fast]);
            currSum += nums[fast];
            maxSum = std::max(maxSum, currSum);
        }
        return maxSum;
    }
};
/*
O(n) time complexity and O(n) space complexity.
This solution uses a sliding window approach with a hash set to track unique elements.
A bit inefficient approach still.
*/
int main() {
    Solution sol;
    vector<int> nums = {4,2,4,5,6}; // Example input
    int result = sol.maximumUniqueSubarray(nums);
    cout << "The maximum erasure value is: " << result << endl;
    return 0;
}