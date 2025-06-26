#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n%3 == 0){
            n = n/3;
        }
        if(n == 1) return true;
        return false;
    }
};
// First solved using tail recursion, then converted it to an iterative solution. Simple and fun.

int main()
{
    Solution sol;
}
