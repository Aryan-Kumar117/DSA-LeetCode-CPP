#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <unordered_set>
using namespace std;

/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        std::vector<int> intersec;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, dupeCheck = INT_MIN;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){i++;} 
            else if(nums1[i] > nums2[j]){j++;} 
            else{
                if(dupeCheck != nums1[i]){
                    dupeCheck = nums1[i];
                    intersec.push_back(nums1[i]);i++;j++;
                }
            }
        }
        return intersec;
    }
};*/

/*
This code should work, it takes O(nlogn + mlogm) time complexity due to sorting and O(n + m) space complexity for the result vector.
But in LeetCode, it gives a TLE error for large inputs.
Thus, I will implement unordered_set for this, which has same theoretical time complexity but is more efficient in practice.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> s;
        std::unordered_set<int> dupeCheck;
        std::vector<int> intersec;
        for(int x: nums1){
            s.insert(x);
        }
        for(int y: nums2){
            if(s.count(y) == 1 && dupeCheck.count(y) == 0){
                intersec.push_back(y);
                dupeCheck.insert(y);
            }
        }
        return intersec;
    }
};

//One very easy thing that could have been done was using the .erase() method of unordered_set to remove duplicates from nums1 and nums2.
//But that would have been O(n) time complexity for each erase operation, which would have made the overall time complexity O(n^2) in the worst case.

//below code is similar to two others on Github, as the int main() function is auto generated by Copilot, but the class Solution is written by me.
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = sol.intersection(nums1, nums2);
    
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}