#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool containsConsonant = false;
        bool containsVowel = false;
        for(char x: word){
            if(!isalnum(x)) return false;
            x = tolower(x);
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') containsVowel = true;
            else if(isalpha(x)) containsConsonant = true;
        }
        if(containsConsonant && containsVowel) return true;
        return false;
    }
};
/*
LeetCode's daily problem for 15th July 2025.
O(n) time and O(1) space complexity.
*/
int main() {
    Solution sol;
    // Example usage:
    string word1 = "hello";
    string word2 = "aeiou";
    string word3 = "bcd";
    
    cout << (sol.isValid(word1) ? "true" : "false") << endl; // Should print "true"
    cout << (sol.isValid(word2) ? "true" : "false") << endl; // Should print "false"
    cout << (sol.isValid(word3) ? "true" : "false") << endl; // Should print "false"
    
    return 0;
}