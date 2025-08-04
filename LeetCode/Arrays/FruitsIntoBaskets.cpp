#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        int left = 0;
        int right = 0;
        std::unordered_map<int, int> map;

        while(right < fruits.size()){
            map[fruits[right]]++;
            while(map.size() > 2){
                map[fruits[left]]--;
                if (map[fruits[left]] == 0) {
                    map.erase(fruits[left]);
                }
                left++;
            }
            right++;
            maxFruits = std::max(maxFruits, right - left);
        }
        return maxFruits;
    }
};
/*
O(n) time complexity and O(1) space complexity, where n is the number of fruits.
Implemented a sliding window approach to find the maximum number of fruits in two baskets.
*/
int main() {
    Solution sol;
    // Example usage:
    vector<int> fruits = {1, 2, 1, 2, 3, 2, 1};
    int result = sol.totalFruit(fruits);
    cout << "Maximum number of fruits in two baskets: " << result << endl;
    return 0;
}