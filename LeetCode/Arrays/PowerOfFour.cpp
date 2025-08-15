#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n-1)) == 0 && ((n-1) % 3) == 0;
    }
};
/*
O(1) time and O(1) space complexity.
One liner solution to check if a number is a power of four.
*/
int main() {
    Solution sol;
    int n = 16; // Example input
    bool result = sol.isPowerOfFour(n);
    cout << "Is " << n << " a power of four? " << (result ? "Yes" : "No") << endl;
    return 0;
}