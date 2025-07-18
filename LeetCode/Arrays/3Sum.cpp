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
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> answer;
        int n = nums.size();
        for(int i = 0; i < n-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    answer.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) ++left;
                    while(left < right && nums[right] == nums[right-1]) --right;
                    ++left; --right;
                }
                else if(sum < 0) ++left;
                else --right;
            }
        }
        return answer;
    }
};
/*
O(n^2) time complexity and O(1) space complexity.
This one was interesting. The naive approach would take O(n^3) time, but we optimize it to O(n^2) using sorting and two pointers.
I also tried using a hash set, but the two-pointer technique is more efficient for this problem.
*/
int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);
    
    cout << "Three Sum Results:" << endl;
    for(const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    
    return 0;
}