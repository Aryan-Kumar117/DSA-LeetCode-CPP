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
    void moveZeroes(vector<int>& nums) {
        int lastNonZero = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                std::swap(nums[i], nums[lastNonZero]);
                ++lastNonZero;
            }
        }
    }
};
/*
O(n) time complexity and O(1) space complexity.
Used two pointer approach to swap and solve.
*/
int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    
    sol.moveZeroes(nums);
    
    cout << "Array after moving zeroes:" << endl;
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}