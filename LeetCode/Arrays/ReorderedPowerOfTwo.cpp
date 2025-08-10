#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto getFreq = [](long long x) {
            std::unordered_map<char, int> freq;
            for(char c: std::to_string(x)) freq[c]++;
            return freq;
        };

        auto target = getFreq(n);
        int lenN = std::to_string(n).size();

        for(long long p = 1; p <= 1'000'000'000; p <<= 1){
            if(std::to_string(p).size() == lenN && getFreq(p) == target) {
                return true;
            }
        }
        return false;
    }
};
/*
O(d) time complexity, where d is the number of digits in n.
This solution checks all powers of 2 up to 1 billion, which is efficient given the constraints.
We use a lambda function to get the frequency of digits in a number, and compare it with the target frequency.
*/
int main() {
    Solution sol;
    int n = 46; // Example input
    bool result = sol.reorderedPowerOf2(n);
    cout << "Can " << n << " be reordered to form a power of 2? " << (result ? "Yes" : "No") << endl;
    return 0;
}