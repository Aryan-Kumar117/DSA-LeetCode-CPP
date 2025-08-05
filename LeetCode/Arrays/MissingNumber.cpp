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
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1)) / 2;
        for(int x: nums){
            sum -= x;
        }
        return sum;
    }
};
/*
O(n) time complexity and O(1) space complexity.
Using the Gauss formula to find the missing number in the array.
*/
int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1}; // Example input
    int result = sol.missingNumber(nums);
    cout << "The missing number is: " << result << endl;
    return 0;
}