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
    int findLucky(vector<int>& arr) {
        std::unordered_map<int, int> H;
        int maxLuck = -1;
        for(int x : arr){
            H[x]++;
        }
        for(const auto& pair : H){
            if(pair.first == pair.second && pair.first > maxLuck){
                maxLuck = pair.first;
            } 
        }
        return maxLuck;
    }
};

/*
O(n) time complexity and O(n) space complexity.
LeetCode's daily problem for 05-07-2025. An easy one, that's why I attempted it.
*/

int main() {
    Solution sol;
    vector<int> arr = {2, 2, 3, 4};
    cout << "Lucky Integer: " << sol.findLucky(arr) << endl; // Output: 2
    return 0;
}