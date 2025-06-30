#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> H;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            H[nums[i]]++;
        }
        for(auto& freq : H){
            if(freq.second > 1){return true;}
        }
        return false;
    }
};

/*
O(n) time complexity and O(n) space complexity.
Used unordered_map.
Second method would be to sort the array and check for adjacent duplicates, which would be O(n log n) time complexity.
This method is more efficient.
*/

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1}; // Example input
    bool hasDuplicate = sol.containsDuplicate(nums);
    
    cout << "Contains duplicate: " << (hasDuplicate ? "Yes" : "No") << endl;
    
    return 0;
}