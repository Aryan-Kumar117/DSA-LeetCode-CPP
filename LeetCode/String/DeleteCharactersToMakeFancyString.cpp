#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

/*class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3) return s;
        char first = s[0];
        char second = s[1];
        for(auto it = s.begin()+2; it != s.end(); ){
            if(first == second && second == *it){
                it = s.erase(it);
            }
            else{
                first = second;
                second = *it;
                ++it;
            }
        }
        return s;
    }
};
O(n) time complexity and O(1) space complexity.
The above code is inefficient, passed 305/306 test cases. 
*/

class Solution {
public:
    string makeFancyString(string s) {
        std::string ans = "";
        if(s.size() < 3) return s;
        char first = s[0];
        char second = s[1];
        for(auto it = s.begin()+2; it != s.end(); ){
            if(!(first == second && second == *it)){
                ans.push_back(first);
            }
                first = second;
                second = *it;
                ++it;
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "leeetcode"; // Example input
    string result = sol.makeFancyString(s);
    cout << "The fancy string is: " << result << endl;
    return 0;
}
