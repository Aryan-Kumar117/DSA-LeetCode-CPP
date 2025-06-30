#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

/*
What I initially used, a bit inefficient but works:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.empty()){return 0;}
       int unqEle = 1;
        for(auto it = nums.begin(); it+1 != nums.end(); ){
            if(*it != *(it+1)){
                it++;
                unqEle++;
            }
            else{
                it = nums.erase(it);
            }
        }
        return unqEle;
    }
};
*/
//nums.erase() causes repeated shifting, so it is less efficient.
//Two pointers approach takes O(n) time complexity and O(1) space complexity.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){return 0;}
        int i = 0;
        int n = nums.size();
        for(int j = 1; j < n; ++j){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2}; // Example input
    int newLength = sol.removeDuplicates(nums);
    
    cout << "New length of the array after removing duplicates is: " << newLength << endl;
    cout << "Modified array: ";
    for(int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}