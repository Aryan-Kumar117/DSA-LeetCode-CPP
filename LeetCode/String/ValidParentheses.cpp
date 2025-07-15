#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stac;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stac.push(s[i]);
            }
            else if(s[i] == ')' && !stac.empty() && stac.top() == '('){
                stac.pop();
            }
            else if(s[i] == '}' && !stac.empty() && stac.top() == '{'){
                stac.pop();
            }
            else if(s[i] == ']' && !stac.empty() && stac.top() == '['){
                stac.pop();
            }
            else{
                return false;
            }
        }
        if(stac.empty()) return true;
        return false;
    }
};
/* 
O(n) time and O(n) space complexity.
Classic problem.
*/
int main() {
    Solution sol;
    // Example usage:
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    
    cout << (sol.isValid(s1) ? "true" : "false") << endl; // Should print "true"
    cout << (sol.isValid(s2) ? "true" : "false") << endl; // Should print "true"
    cout << (sol.isValid(s3) ? "true" : "false") << endl; // Should print "false"
    
    return 0;
}