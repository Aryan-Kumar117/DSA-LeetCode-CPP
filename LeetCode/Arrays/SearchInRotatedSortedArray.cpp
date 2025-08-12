#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;

            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else{
                if(target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};
/*
O(log n) time complexity and O(1) space complexity.
Binary search implemented with a small twist to handle the rotated sorted array.
*/
int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0; // Example target
    int result = sol.search(nums, target);
    cout << "Index of target " << target << ": " << result << endl;
    return 0;
}