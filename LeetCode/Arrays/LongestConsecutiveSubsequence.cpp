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
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> S;
        S.reserve(nums.size());
        int maxCount = 0;
        for(int x: nums){
            S.insert(x);
        }
        for(int x: nums){
            if(!S.count(x-1)){
                int i = 0;
                int currCount = 0;
                int curr = x;
                while(S.count(curr)){
                    ++curr;
                    ++currCount;
                }
                maxCount = std::max(maxCount, currCount);
            }
        }
        return maxCount;
    }
};

/*
The problem with the above code is that it passes 78/81 test cases on LeetCode. In theory, it should be O(n) time complexity,
but on test cases with large duplicate inputs and large consecutive sequences, it fails to complete in time.
Thus, I will try to implement a different approach.
*/

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2}; // Example input
    int result = sol.longestConsecutive(nums);
    
    cout << "Longest consecutive sequence length: " << result << endl; // Should print "4"
    
    return 0;
}

