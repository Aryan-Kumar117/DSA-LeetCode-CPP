#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> H;
        int currSum = 0;
        int count = 0;
        H[0] = 1;
        for(int i = 0; i < n; i++){
            currSum += nums[i];
            if(H.count(currSum - k)) count += H[currSum - k];
            H[currSum]++;
        }
        return count;
    }
};
/*
O(n) time complexity and O(n) space complexity.
This solution uses a hash map to store the cumulative sums and their frequencies.
*/
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2; // Example target sum
    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << ": " << result << endl; // Output: 2
    return 0;
}