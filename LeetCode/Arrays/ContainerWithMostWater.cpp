#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea = 0;
        while(i<j){
            int lower = (height[i] < height[j]) ? height[i] : height[j];
            int area = (j-i) * lower;
            if(height[i] < height[j]) i++;
            else j--;
            maxArea = std::max(maxArea, area);
        }
        return maxArea;
    }
};
/*
O(n) time complexity and O(1) space complexity.
Simple use of the two-pointer technique to find the maximum area between two lines.
*/
int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7}; // Example input
    int maxArea = sol.maxArea(height); 
    cout << "Maximum area: " << maxArea << endl;
    return 0;
}