#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> H;
        int ans = 0;
        bool flag = true;
        for(char x: s) H[x]++;
        for(auto it = H.begin(); it != H.end(); ++it){
            if(it->second % 2 == 0){
                ans += it->second;
            }
            else{
                ans += it->second - 1;
                if(flag){
                    ++ans;
                    flag = false;
                }
            }
        }
        return ans;
    }
};
/*
O(n) time complexity and O(n) space complexity.
This is a straightforward solution using a hash map to count character frequencies.
*/
int main() {
    Solution sol;
    string s = "abccccdd"; // Example input
    int result = sol.longestPalindrome(s);
    cout << "The length of the longest palindrome that can be built is: " << result << endl;
    return 0;
}