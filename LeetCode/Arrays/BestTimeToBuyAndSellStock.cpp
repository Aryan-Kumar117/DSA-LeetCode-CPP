#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            if(prices[i] < minPrice){minPrice = prices[i];}
            if(prices[i] - minPrice > maxProfit){maxProfit = prices[i] - minPrice;}
        }
        return maxProfit;
    }
};

/*
O(n) time complexity and O(1) space complexity.
Once you figure out the logic, it's straightforward.
*/

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    int profit = sol.maxProfit(prices);
    
    cout << "Maximum profit: " << profit << endl;
    
    return 0;
}