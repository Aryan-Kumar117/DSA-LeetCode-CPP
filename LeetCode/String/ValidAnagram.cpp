#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> H;
        for(char x: s){
            H[x]++;
        }
        for(char x: t){
            H[x]--;
        }
        for(auto &pair: H){
            if(pair.second != 0) return false;
        }
        return true;
    }
};
/*
O(n) time and space complexity.
An easy one.
*/
int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    bool result = sol.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl; // Should print "true"
    
    s = "rat";
    t = "car";
    result = sol.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl; // Should print "false"
    
    return 0;
}