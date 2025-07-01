#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = nums[0];
        for(int i = 0; i < n; i++){
            if(count == 0){candidate = nums[i];}
            if(nums[i] == candidate){count++;}
            else{count--;}
        }
        return candidate;
    }
};

/*
O(n) time complexity and O(1) space complexity.
This is the Boyer Moore Majority Voting Algorithm in action. 
It works by maintaining a count of the current candidate for the majority element.
When the count reaches zero, it selects a new candidate.
*/

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3}; // Example input
    int result = sol.majorityElement(nums);
    cout << "The majority element is: " << result << endl;
    return 0;
}