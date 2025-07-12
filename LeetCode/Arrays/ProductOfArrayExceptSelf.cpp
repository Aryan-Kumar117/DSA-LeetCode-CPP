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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);
        int runMult = 1;
        for(int i = 0; i < n; i++){
            if(i>0) answer[i] = runMult;
            runMult *= nums[i];
        }
        int suffixProduct = 1;
        for(int j = n-1; j >= 0; j--){
            answer[j] *= suffixProduct;
            suffixProduct *= nums[j];
        }
        return answer;
    }
};

/*
This one was a bit hard. Without using division, and being constrained to O(n) time complexity, it feels a bit tricky.
However, the idea is to first calculate the product of all elements to the left of each index,
then calculate the product of all elements to the right of each index, and multiply these two results together.
*/  

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; // Example input
    vector<int> result = sol.productExceptSelf(nums);
    
    cout << "Product of array except self: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl; // Should print "24 12 8 6"
    
    return 0;
}