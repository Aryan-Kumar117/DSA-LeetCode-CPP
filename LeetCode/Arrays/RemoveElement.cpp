#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int valCount = 0;
        for(auto it = nums.begin(); it != nums.end(); ){
            if(*it == val){
                it = nums.erase(it);
                valCount++;
            }
            else{++it;}
        }
        return (n - valCount);
    }
};

/*
O(n) time complexity and O(1) space complexity.
Learnt about iterating through a vector using iterators and the erase method.
Erase method is a bit tricky, can't loop through the vector traditionally while erasing elements,
as it invalidates the iterator. Instead, we use the iterator returned by the erase method to continue iterating.
*/

int main() {
    Solution sol;
    vector<int> nums = {3,2,2,3}; // Example input
    int val = 3; // Value to remove
    int newLength = sol.removeElement(nums, val);
    
    cout << "New length of the array after removing " << val << " is: " << newLength << endl;
    cout << "Modified array: ";
    for(int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}