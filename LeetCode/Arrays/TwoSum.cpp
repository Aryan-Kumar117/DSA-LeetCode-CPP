#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int c = target - nums[i];
            if(numMap.count(c)){
                return{numMap[c], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

//Had to take a look at the unordered_map here, then take a look at the solution on LeetCode.

int main()
{
    Solution sol;
}
